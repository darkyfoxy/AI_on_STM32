
#include "sensor.h"

#ifndef __OV2640_H__
#define __OV2640_H__
#define OV2640_XCLK_FREQ 24000000

#define RGB565_128X128
//#define	RGB565_160X160 // 160x160
//#define	RGB565_QVGA  // 320X240
//#define	RGB565_VGA   // 640X480

int ov2640_init(sensor_t *sensor);
#endif // __OV2640_H__
