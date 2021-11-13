#include "cambas.h"

#define OMV_XCLK_FREQUENCY      (12000000)

#define	RGB565_128X128_BUF_SIZE (128*128*2) // 128x128
#define	RGB565_160X160_BUF_SIZE (160*160*2) // 160x160
#define	RGB565_QVGA_BUF_SIZE    (320*240*2) // 320X240
#define	RGB565_VGA_BUF_SIZE     (640*480*2) // 640X480


#define IM_MAX(a,b)     ({ __typeof__ (a) _a = (a); __typeof__ (b) _b = (b); _a > _b ? _a : _b; })
#define IM_MIN(a,b)     ({ __typeof__ (a) _a = (a); __typeof__ (b) _b = (b); _a < _b ? _a : _b; })
#define IM_LOG2_2(x)    (((x) &                0x2ULL) ? ( 2                        ) :             1) // NO ({ ... }) !
#define IM_LOG2_4(x)    (((x) &                0xCULL) ? ( 2 +  IM_LOG2_2((x) >>  2)) :  IM_LOG2_2(x)) // NO ({ ... }) !
#define IM_LOG2_8(x)    (((x) &               0xF0ULL) ? ( 4 +  IM_LOG2_4((x) >>  4)) :  IM_LOG2_4(x)) // NO ({ ... }) !
#define IM_LOG2_16(x)   (((x) &             0xFF00ULL) ? ( 8 +  IM_LOG2_8((x) >>  8)) :  IM_LOG2_8(x)) // NO ({ ... }) !
#define IM_LOG2_32(x)   (((x) &         0xFFFF0000ULL) ? (16 + IM_LOG2_16((x) >> 16)) : IM_LOG2_16(x)) // NO ({ ... }) !
#define IM_LOG2(x)      (((x) & 0xFFFFFFFF00000000ULL) ? (32 + IM_LOG2_32((x) >> 32)) : IM_LOG2_32(x)) // NO ({ ... }) !
// Pixel format IDs.
typedef enum {
    PIXFORMAT_ID_BINARY     = 1,
    PIXFORMAT_ID_GRAY       = 2,
    PIXFORMAT_ID_RGB565     = 3,
    PIXFORMAT_ID_BAYER      = 4,
    PIXFORMAT_ID_YUV422     = 5,
    PIXFORMAT_ID_JPEG       = 6,
    /* Note: Update PIXFORMAT_IS_VALID when adding new formats */
} pixformat_id_t;

// Pixel sub-format IDs.
typedef enum {
    SUBFORMAT_ID_GRAY8      = 0,
    SUBFORMAT_ID_GRAY16     = 1,
    SUBFORMAT_ID_BGGR       = 0, // !!! Note: Make sure bayer sub-formats don't  !!!
    SUBFORMAT_ID_GBRG       = 1, // !!! overflow the sensor.hw_flags.bayer field !!!
    SUBFORMAT_ID_GRBG       = 2,
    SUBFORMAT_ID_RGGB       = 3,
    SUBFORMAT_ID_YUV422     = 0,
    SUBFORMAT_ID_YVU422     = 1,
    /* Note: Update PIXFORMAT_IS_VALID when adding new formats */
} subformat_id_t;

// Pixel format Byte Per Pixel.
typedef enum {
    PIXFORMAT_BPP_BINARY    = 0,
    PIXFORMAT_BPP_GRAY8     = 1,
    PIXFORMAT_BPP_GRAY16    = 2,
    PIXFORMAT_BPP_RGB565    = 2,
    PIXFORMAT_BPP_BAYER     = 1,
    PIXFORMAT_BPP_YUV422    = 2,
    /* Note: Update PIXFORMAT_IS_VALID when adding new formats */
} pixformat_bpp_t;

#define PIXFORMAT_FLAGS_Y       (1 << 28) // YUV format.
#define PIXFORMAT_FLAGS_M       (1 << 27) // Mutable format.
#define PIXFORMAT_FLAGS_C       (1 << 26) // Colored format.
#define PIXFORMAT_FLAGS_J       (1 << 25) // Compressed format (JPEG/PNG).
#define PIXFORMAT_FLAGS_R       (1 << 24) // RAW/Bayer format.
#define PIXFORMAT_FLAGS_CY      (PIXFORMAT_FLAGS_C | PIXFORMAT_FLAGS_Y)
#define PIXFORMAT_FLAGS_CM      (PIXFORMAT_FLAGS_C | PIXFORMAT_FLAGS_M)
#define PIXFORMAT_FLAGS_CR      (PIXFORMAT_FLAGS_C | PIXFORMAT_FLAGS_R)
#define PIXFORMAT_FLAGS_CJ      (PIXFORMAT_FLAGS_C | PIXFORMAT_FLAGS_J)

typedef enum {
    PIXFORMAT_INVALID    = (0),
    PIXFORMAT_BINARY     = (PIXFORMAT_FLAGS_M  | (PIXFORMAT_ID_BINARY << 16) | (0                   << 8) | PIXFORMAT_BPP_BINARY ),
    PIXFORMAT_GRAYSCALE  = (PIXFORMAT_FLAGS_M  | (PIXFORMAT_ID_GRAY   << 16) | (SUBFORMAT_ID_GRAY8  << 8) | PIXFORMAT_BPP_GRAY8  ),
    PIXFORMAT_RGB565     = (PIXFORMAT_FLAGS_CM | (PIXFORMAT_ID_RGB565 << 16) | (0                   << 8) | PIXFORMAT_BPP_RGB565 ),
    PIXFORMAT_BAYER      = (PIXFORMAT_FLAGS_CR | (PIXFORMAT_ID_BAYER  << 16) | (SUBFORMAT_ID_BGGR   << 8) | PIXFORMAT_BPP_BAYER  ),
    PIXFORMAT_BAYER_BGGR = (PIXFORMAT_FLAGS_CR | (PIXFORMAT_ID_BAYER  << 16) | (SUBFORMAT_ID_BGGR   << 8) | PIXFORMAT_BPP_BAYER  ),
    PIXFORMAT_BAYER_GBRG = (PIXFORMAT_FLAGS_CR | (PIXFORMAT_ID_BAYER  << 16) | (SUBFORMAT_ID_GBRG   << 8) | PIXFORMAT_BPP_BAYER  ),
    PIXFORMAT_BAYER_GRBG = (PIXFORMAT_FLAGS_CR | (PIXFORMAT_ID_BAYER  << 16) | (SUBFORMAT_ID_GRBG   << 8) | PIXFORMAT_BPP_BAYER  ),
    PIXFORMAT_BAYER_RGGB = (PIXFORMAT_FLAGS_CR | (PIXFORMAT_ID_BAYER  << 16) | (SUBFORMAT_ID_RGGB   << 8) | PIXFORMAT_BPP_BAYER  ),
    PIXFORMAT_YUV422     = (PIXFORMAT_FLAGS_CY | (PIXFORMAT_ID_YUV422 << 16) | (SUBFORMAT_ID_YUV422 << 8) | PIXFORMAT_BPP_YUV422 ),
    PIXFORMAT_YVU422     = (PIXFORMAT_FLAGS_CY | (PIXFORMAT_ID_YUV422 << 16) | (SUBFORMAT_ID_YVU422 << 8) | PIXFORMAT_BPP_YUV422 ),
    PIXFORMAT_JPEG       = (PIXFORMAT_FLAGS_CJ | (PIXFORMAT_ID_JPEG   << 16) | (0                   << 8) | 0                    ),
    PIXFORMAT_LAST       = 0xFFFFFFFFU,
} pixformat_t;

typedef enum {
    FRAMESIZE_INVALID = 0,
    // C/SIF Resolutions
    FRAMESIZE_QQCIF,    // 88x72
    FRAMESIZE_QCIF,     // 176x144
    FRAMESIZE_CIF,      // 352x288
    FRAMESIZE_QQSIF,    // 88x60
    FRAMESIZE_QSIF,     // 176x120
    FRAMESIZE_SIF,      // 352x240
    // VGA Resolutions
    FRAMESIZE_QQQQVGA,  // 40x30
    FRAMESIZE_QQQVGA,   // 80x60
    FRAMESIZE_QQVGA,    // 160x120
    FRAMESIZE_QVGA,     // 320x240
    FRAMESIZE_VGA,      // 640x480
    FRAMESIZE_HQQQQVGA, // 30x20
    FRAMESIZE_HQQQVGA,  // 60x40
    FRAMESIZE_HQQVGA,   // 120x80
    FRAMESIZE_HQVGA,    // 240x160
    FRAMESIZE_HVGA,     // 480x320
    // FFT Resolutions
    FRAMESIZE_64X32,    // 64x32
    FRAMESIZE_64X64,    // 64x64
    FRAMESIZE_128X64,   // 128x64
    FRAMESIZE_128X128,  // 128x128
    // Himax Resolutions
    FRAMESIZE_160X160,  // 160x160
    FRAMESIZE_320X320,  // 320x320
    // Other
    FRAMESIZE_LCD,      // 128x160
    FRAMESIZE_QQVGA2,   // 128x160
    FRAMESIZE_WVGA,     // 720x480
    FRAMESIZE_WVGA2,    // 752x480
    FRAMESIZE_SVGA,     // 800x600
    FRAMESIZE_XGA,      // 1024x768
    FRAMESIZE_WXGA,     // 1280x768
    FRAMESIZE_SXGA,     // 1280x1024
    FRAMESIZE_SXGAM,    // 1280x960
    FRAMESIZE_UXGA,     // 1600x1200
    FRAMESIZE_HD,       // 1280x720
    FRAMESIZE_FHD,      // 1920x1080
    FRAMESIZE_QHD,      // 2560x1440
    FRAMESIZE_QXGA,     // 2048x1536
    FRAMESIZE_WQXGA,    // 2560x1600
    FRAMESIZE_WQXGA2,   // 2592x1944
} framesize_t;


typedef enum {
    GAINCEILING_2X,
    GAINCEILING_4X,
    GAINCEILING_8X,
    GAINCEILING_16X,
    GAINCEILING_32X,
    GAINCEILING_64X,
    GAINCEILING_128X,
} gainceiling_t;

typedef enum {
    SDE_NORMAL,
    SDE_NEGATIVE,
} sde_t;

typedef struct _sensor sensor_t;
typedef struct _sensor {
	uint8_t  pid;
	uint8_t  rev;
    uint8_t  slv_addr;          // Sensor I2C slave address.

    cambus_t bus;               // SCCB/I2C bus.

    // Sensor settings
    pixformat_t pixformat;
    framesize_t framesize;
    int contrast_level;
    int brightness_level;
    int saturation_level;

    // Sensor function pointers
    int  (*reset)               (sensor_t *sensor);
    int  (*set)                 (sensor_t *sensor);
    int  (*sleep)               (sensor_t *sensor, int enable);
    int  (*read_reg)            (sensor_t *sensor, uint16_t reg_addr);
    int  (*write_reg)           (sensor_t *sensor, uint16_t reg_addr, uint16_t reg_data);
    int  (*set_pixformat)       (sensor_t *sensor, pixformat_t pixformat);
    int  (*set_framesize)       (sensor_t *sensor, framesize_t framesize);
    int  (*set_contrast)        (sensor_t *sensor, int level);
    int  (*set_brightness)      (sensor_t *sensor, int level);
    int  (*set_saturation)      (sensor_t *sensor, int level);
    int  (*set_gainceiling)     (sensor_t *sensor, gainceiling_t gainceiling);
    int  (*set_quality)         (sensor_t *sensor, int quality);
    int  (*set_colorbar)        (sensor_t *sensor, int enable);
    int  (*set_auto_gain)       (sensor_t *sensor, int enable, float gain_db, float gain_db_ceiling);
    int  (*get_gain_db)         (sensor_t *sensor, float *gain_db);
    int  (*set_auto_exposure)   (sensor_t *sensor, int enable, int exposure_us);
    int  (*get_exposure_us)     (sensor_t *sensor, int *exposure_us);
    int  (*set_auto_whitebal)   (sensor_t *sensor, int enable, float r_gain_db, float g_gain_db, float b_gain_db);
    int  (*get_rgb_gain_db)     (sensor_t *sensor, float *r_gain_db, float *g_gain_db, float *b_gain_db);
    int  (*set_hmirror)         (sensor_t *sensor, int enable);
    int  (*set_vflip)           (sensor_t *sensor, int enable);
    int  (*set_special_effect)  (sensor_t *sensor, sde_t sde);
    int  (*snapshot)            (DCMI_HandleTypeDef DCMIHandle, int32_t *image);
} sensor_t;
