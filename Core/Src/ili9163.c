#include "ili9163.h"


extern SPI_HandleTypeDef DISP_SPI;

void ILI9163_writeCommand(uint8_t address) {
	HAL_GPIO_WritePin(DISP_CS_Port, DISP_CS_Pin, 0);
	HAL_GPIO_WritePin(DISP_DC_Port, DISP_DC_Pin, 0);

	HAL_SPI_Transmit(&DISP_SPI, &address, 1, 300);

	HAL_GPIO_WritePin(DISP_CS_Port, DISP_CS_Pin, 1);
}

void ILI9163_writeData(uint8_t data) {
	HAL_GPIO_WritePin(DISP_CS_Port, DISP_CS_Pin, 0);
	HAL_GPIO_WritePin(DISP_DC_Port, DISP_DC_Pin, 1);

	HAL_SPI_Transmit(&DISP_SPI, &data, 1, 300);

	HAL_GPIO_WritePin(DISP_CS_Port, DISP_CS_Pin, 1);
}

void ILI9163_writeData16(uint16_t word) {
	HAL_GPIO_WritePin(DISP_CS_Port, DISP_CS_Pin, 0);
	HAL_GPIO_WritePin(DISP_DC_Port, DISP_DC_Pin, 1);

	uint8_t data [2] = {(word >> 8) & 0x00FF, word & 0x00FF};
	HAL_SPI_Transmit(&DISP_SPI, data, 2, 300);

	HAL_GPIO_WritePin(DISP_CS_Port, DISP_CS_Pin, 1);
}

void ILI9163_setAddress(uint16_t x1,uint16_t y1,uint16_t x2,uint16_t y2) {
	ILI9163_writeCommand(ILI9163_CMD_SET_COLUMN_ADDRESS);
	ILI9163_writeData16(x1);
	ILI9163_writeData16(x2);

	ILI9163_writeCommand(ILI9163_CMD_SET_PAGE_ADDRESS);
	ILI9163_writeData16(y1);
	ILI9163_writeData16(y2);

	ILI9163_writeCommand(ILI9163_CMD_WRITE_MEMORY_START);
}

void ILI9163_reset(void)
{
	HAL_GPIO_WritePin(DISP_RST_Port, DISP_RST_Pin, 0);
	HAL_Delay(50);

	HAL_GPIO_WritePin(DISP_RST_Port, DISP_RST_Pin, 1);
	HAL_Delay(100);
}

void ILI9163_init(int rotation) {
	HAL_GPIO_WritePin(DISP_CS_Port, DISP_CS_Pin, 1);
	HAL_GPIO_WritePin(DISP_RST_Port, DISP_RST_Pin, 1);

	ILI9163_reset(); // Hardware reset the LCD

	ILI9163_writeCommand(ILI9163_CMD_EXIT_SLEEP_MODE);
	HAL_Delay(5); // Wait for the screen to wake up

	ILI9163_writeCommand(ILI9163_CMD_SET_PIXEL_FORMAT);
	ILI9163_writeData(0x05); // 16 bpp

	ILI9163_writeCommand(ILI9163_CMD_SET_GAMMA_CURVE);
	ILI9163_writeData(0x04); // Gamma curve 3

	ILI9163_writeCommand(ILI9163_CMD_GAM_R_SEL);
	ILI9163_writeData(0x01); // Gamma curve enable

	ILI9163_writeCommand(ILI9163_CMD_POSITIVE_GAMMA_CORRECT);
	ILI9163_writeData(0x3f);
	ILI9163_writeData(0x25);
	ILI9163_writeData(0x1c);
	ILI9163_writeData(0x1e);
	ILI9163_writeData(0x20);
	ILI9163_writeData(0x12);
	ILI9163_writeData(0x2a);
	ILI9163_writeData(0x90);
	ILI9163_writeData(0x24);
	ILI9163_writeData(0x11);
	ILI9163_writeData(0x00);
	ILI9163_writeData(0x00);
	ILI9163_writeData(0x00);
	ILI9163_writeData(0x00);
	ILI9163_writeData(0x00);

	ILI9163_writeCommand(ILI9163_CMD_NEGATIVE_GAMMA_CORRECT);
	ILI9163_writeData(0x20);
	ILI9163_writeData(0x20);
	ILI9163_writeData(0x20);
	ILI9163_writeData(0x20);
	ILI9163_writeData(0x05);
	ILI9163_writeData(0x00);
	ILI9163_writeData(0x15);
	ILI9163_writeData(0xa7);
	ILI9163_writeData(0x3d);
	ILI9163_writeData(0x18);
	ILI9163_writeData(0x25);
	ILI9163_writeData(0x2a);
	ILI9163_writeData(0x2b);
	ILI9163_writeData(0x2b);
	ILI9163_writeData(0x3a);


	ILI9163_writeCommand(ILI9163_CMD_FRAME_RATE_CONTROL1);
	ILI9163_writeData(0x08); // DIVA = 8
	ILI9163_writeData(0x02); // VPA = 8

	ILI9163_writeCommand(ILI9163_CMD_FRAME_RATE_CONTROL2);
	ILI9163_writeData(0x08); // DIVA = 8
	ILI9163_writeData(0x02); // VPA = 8

	ILI9163_writeCommand(ILI9163_CMD_FRAME_RATE_CONTROL3);
	ILI9163_writeData(0x08); // DIVA = 8
	ILI9163_writeData(0x02); // VPA = 8

	ILI9163_writeCommand(ILI9163_CMD_DISPLAY_INVERSION);
	ILI9163_writeData(0x07); // NLA = 1, NLB = 1, NLC = 1 (all on Frame Inversion)


	ILI9163_writeCommand(ILI9163_CMD_SET_COLUMN_ADDRESS);
	ILI9163_writeData(0x00);
	ILI9163_writeData(0x00);
	ILI9163_writeData(0x00);
	ILI9163_writeData(ILI9163_HEIGHT-1);

	ILI9163_writeCommand(ILI9163_CMD_SET_PAGE_ADDRESS);
	ILI9163_writeData(0x00);
	ILI9163_writeData(0x00);
	ILI9163_writeData(0x00);
	ILI9163_writeData(ILI9163_WIDTH-1);

	ILI9163_writeCommand(ILI9163_CMD_SET_ADDRESS_MODE);
	if(rotation)
		ILI9163_writeData(0x80 | 0x20 | 0x08);
	else
		ILI9163_writeData(0x40 | 0x20 | 0x08);

	ILI9163_writeCommand(ILI9163_CMD_ENTER_NORMAL_MODE);
	ILI9163_writeCommand(ILI9163_CMD_SET_DISPLAY_ON);
	ILI9163_writeCommand(ILI9163_CMD_WRITE_MEMORY_START);
}


void ILI9163_render(uint16_t *frameBuffer)
{
	ILI9163_setAddress(1, 2, ILI9163_WIDTH, ILI9163_HEIGHT+1);
	HAL_GPIO_WritePin(DISP_CS_Port, DISP_CS_Pin, 0);
	HAL_GPIO_WritePin(DISP_DC_Port, DISP_DC_Pin, 1);

	uint8_t test = 0;
	HAL_SPI_Transmit(&DISP_SPI, &test, 1, 1000);

	HAL_SPI_Transmit_DMA(&DISP_SPI, (uint8_t*)frameBuffer, BUFSIZE*2);

}

void ILI9163_drawPixel(uint16_t *frameBuffer, uint8_t x, uint8_t y, uint16_t color) {
	if ((x < 0) || (x >= ILI9163_WIDTH) || (y < 0) || (y >= ILI9163_HEIGHT)) return;
	frameBuffer[((x)+(y*ILI9163_WIDTH))] = color;
}

void ILI9163_fillRect(uint16_t *frameBuffer, uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, uint16_t color)
{
	for(uint8_t x = x1; x < x2; x++)
		for(uint8_t y = y1; y < y2; y++)
			ILI9163_drawPixel(frameBuffer, x, y, color);
}

void ILI9163_drawRect(uint16_t *frameBuffer, uint8_t x1,uint8_t y1,uint8_t x2,uint8_t y2, uint8_t thickness, uint16_t color) {
	ILI9163_fillRect(frameBuffer, x1, y1, x2, y1+thickness, color);
	ILI9163_fillRect(frameBuffer, x1, y2-thickness, x2, y2, color);

	ILI9163_fillRect(frameBuffer, x1, y1, x1+thickness, y2, color);
	ILI9163_fillRect(frameBuffer, x2-thickness, y1, x2, y2, color);
}


void ILI9163_drawChar(uint16_t *frameBuffer, uint8_t x, uint8_t y, char ch, FontDef font, uint16_t color) {
	uint16_t i, b, j;
	for(i = 0; i < font.height; i++) {
		b = font.data[(ch - 32) * font.height + i];
		for(j = 0; j < font.width; j++) {
			if((b << j) & 0x8000)  {
				ILI9163_drawPixel(frameBuffer, x + j, y + i, color);
			}
		}
	}
}
