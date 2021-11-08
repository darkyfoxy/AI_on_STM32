/**
  ******************************************************************************
  * @file       computer_vision.c
  * @brief      This file provides functions to testing computer vision on STM32

  * @author     darkyfoxy [*GitHub*](https://github.com/darkyfoxy)
  * @version    0.01
  * @date       08.11.2021
  *
  ******************************************************************************
  * @copyright  <h3>Copyright (c) 2021 Pavlov V.</h3>
  *
  * Permission is hereby granted, free of charge, to any person obtaining a copy
  * of this software and associated documentation files (the "Software"), to deal
  * in the Software without restriction, including without limitation the rights
  * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  * copies of the Software, and to permit persons to whom the Software is
  * furnished to do so, subject to the following conditions:
  *
  * The above copyright notice and this permission notice shall be included in all
  * copies or substantial portions of the Software.
  *
  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
  * SOFTWARE.
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "computer_vision.h"
#include "stm32h7xx_hal.h"
#include "app_x-cube-ai.h"
#include "ili9163.h"
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
static uint8_t fps_buf[4];

static const char lable[10][11] = {"airplane",
								   "automobile",
								   "bird",
								   "cat",
								   "deer",
								   "dog",
								   "frog",
								   "horse",
								   "ship",
								   "truck"};
/* External variables --------------------------------------------------------*/
extern uint8_t fps;

/* Private function prototypes -----------------------------------------------*/
static uint8_t CIFAR_Ai_calculate(uint16_t *frameBuffer);

#ifndef QUANT
static uint8_t MNIST_Ai_calculate(uint16_t *frameBuffer);
#else
static uint8_t Q_MNIST_Ai_calculate(uint16_t *frameBuffer);
#endif

static void Non_HAL_CON_UInt_to_DecString_8bit(uint8_t data, uint8_t *decstr, uint8_t sizebuf);

/* Private functions ---------------------------------------------------------*/

/**
  * @brief  The function to preparing data for the CIFAR network with quantization,
  * 		starting the network and calculating a maximum element of a network output
  * @param  frameBuffer a pointer on a frame buffer with RGB565 values (size 128*128)
  * @retval res a uint8_t value with a number of a max item in a network output
  */
static uint8_t CIFAR_Ai_calculate(uint16_t *frameBuffer)
{
	float input[32][32][3];
	float output[10];

	for(int i = 0; i < 32; i ++)
	{
		for(int j = 0; j < 32; j ++)
		{
			uint16_t RGB_sample = frameBuffer[(128*32) + 32 + (i*128*2) + (j*2)];
			float B = (float)(RGB_sample & 0x1f) / 32.0;
			float G = (float)((RGB_sample >> 6) & 0x1f) / 32.0;
			float R = (float)(RGB_sample >> 11) / 32.0;

			input[i][j][0] = (R - 0.1307) / 0.3081;
			input[i][j][1] = (G - 0.1307) / 0.3081;
			input[i][j][2] = (B - 0.1307) / 0.3081;
		}
	}



	SCB_EnableDCache();
	my_ai_run((void *)input, (void *)output);
	SCB_DisableDCache();

	uint8_t res=0;
	float max = output[0];

	for(int g = 1; g < 10; g++)
	{
		if(max < output[g])
		{
			res = g;
			max = output[g];
		}
	}
	return res;
}

#ifndef QUANT
/**
  * @brief  The function to preparing data for the MNIST network without quantization,
  * 		starting the network and calculating a maximum element of a network output
  * @note	See computer_vision.h for a definition of GUI
  * @param  frameBuffer a pointer on a frame buffer with RGB565 values (size 128*128)
  * @retval res a uint8_t value with a number of a max item in a network output
  */
static uint8_t MNIST_Ai_calculate(uint16_t *frameBuffer)
{
	float input[28*28];
	float output[10];

	for(int i = 0; i < 28; i ++)
	{
		for(int j = 0; j < 28; j ++)
		{
			uint16_t RGB_sample = frameBuffer[(128*23) + 23 - 10 + (i*128*3) + (j*3)];
			float B = (float)(RGB_sample & 0x1f) / 128.0;
			float G = (float)((RGB_sample >> 5) & 0x3f) / 128.0;
			float R = (float)(RGB_sample >> 11) / 128.0;
			float pre_sum = (R + G + B);
			float sum = pre_sum < 0.3 ? (1-pre_sum) : 0.0;

			input[28*i + j] = (sum - 0.1307) / 0.3081;

			#if defined GUI
			uint16_t gray = (uint16_t)(sum * 31);
			uint16_t RGB_gray =  (gray << 11) | (gray << 6) |  gray;

			frameBuffer[(128*100) + 100 + (i*128) + (j)] = RGB_gray;
			#endif
		}
	}

	SCB_EnableDCache();
	my_ai_run((void *)input, (void *)output);
	SCB_DisableDCache();

	uint8_t res=0;
	float max = output[0];

	for(int g = 1; g < 10; g++)
	{
		if(max < output[g])
		{
			res = g;
			max = output[g];
		}
	}
	return res;
}
#endif

#ifdef QUANT
/**
  * @brief  The function to preparing data for the MNIST network with quantization,
  * 		starting the network and calculating a maximum element of a network output
  * @note	See computer_vision.h for a definition of GUI
  * @param  frameBuffer a pointer on a frame buffer with RGB565 values (size 128*128)
  * @retval res a uint8_t value with a number of a max item in a network output
  */
static uint8_t Q_MNIST_Ai_calculate(uint16_t *frameBuffer)
{
	int8_t input[28*28];
	int8_t output[10];

	for(int i = 0; i < 28; i ++)
	{
		for(int j = 0; j < 28; j ++)
		{
			uint16_t RGB_sample = frameBuffer[(128*23) + 23 - 10 + (i*128*3) + (j*3)];
			float B = (float)(RGB_sample & 0x1f) / 128.0;
			float G = (float)((RGB_sample >> 5) & 0x3f) / 128.0;
			float R = (float)(RGB_sample >> 11) / 128.0;
			float pre_sum = (R + G + B);
			float sum = pre_sum < 0.3 ? (1-pre_sum) : 0.0;

			input[28*i + j] = (int8_t)((sum - 0.5) * 255);


			#if defined GUI
			uint16_t gray = (uint16_t)(sum * 31);
			uint16_t RGB_gray =  (gray << 11) | (gray << 6) |  gray;

			frameBuffer[(128*100) + 100 + (i*128) + (j)] = RGB_gray;
			#endif
		}
	}

	SCB_EnableDCache();
	my_ai_run((void *)input, (void *)output);
	SCB_DisableDCache();

	uint8_t res = 0;
	int8_t max = output[0];

	for(int g = 1; g < 10; g++)
	{
		if(max < output[g])
		{
			res = g;
			max = output[g];
		}
	}
	return res;
}
#endif

/**
  * @brief  The function to convert an uint8_t value to a character string
  *         with decimal symbols (from 0 to 9)
  * @param  data an uint8_t value to convert to a character string
  * @param  bitstr a pointer on a character string
  * @param  sizebuf a size of a character string which must be least 4 (+1 for \0)
  * @retval void
  */
static void Non_HAL_CON_UInt_to_DecString_8bit(uint8_t data, uint8_t *decstr, uint8_t sizebuf)
{
    char first_zeroflag = 1;
    for(char i=100; i>0; i/=10)
    {
      *decstr = ((data/i)%10) + '0';
      if(*decstr != 0 + '0' || first_zeroflag == 0)
      {
        decstr++;
        first_zeroflag = 0;
      }
    }
    *decstr = 0;
}


/* Exported functions --------------------------------------------------------*/

/**
  * @brief  The function to NMIST network computing and GUI rendering
  * @note	See computer_vision.h for a definition of GUI and QUANT
  * @param  imag_trans a pointer on a frame buffer with RGB565 values (size 128*128)
  * @retval void
  */
void MNIST_AI_block(uint16_t *imag_trans)
{
#if defined GUI
  ILI9163_drawRect(imag_trans, 11, 21, 97, 107,  2,  0x1f<<11);
#endif

#ifndef QUANT
  uint8_t number = MNIST_Ai_calculate(imag_trans) + 0x30;
#else
  uint8_t number = Q_MNIST_Ai_calculate(imag_trans) + 0x30;
#endif

#if defined GUI
  ILI9163_fillRect(imag_trans, 0, 0, 128, 20, 0xffff);
  ILI9163_fillRect(imag_trans, 99, 99, 100, 127, 0xffff);
  ILI9163_fillRect(imag_trans, 99, 99, 128, 100, 0xffff);

  ILI9163_drawChar(imag_trans, 1, 1, 'r', Font_11x18, 0x0);
  ILI9163_drawChar(imag_trans, 1 + (1*11), 1, 'e', Font_11x18, 0x0);
  ILI9163_drawChar(imag_trans, 1 + (2*11), 1, 's', Font_11x18, 0x0);
  ILI9163_drawChar(imag_trans, -3 + (3*11), 1, ':', Font_11x18, 0x0);

  ILI9163_drawChar(imag_trans, 1 + (3*11) + 5, 1, number, Font_11x18, 0x0);


  ILI9163_drawChar(imag_trans, 103 - (3*11), 1, 'f', Font_11x18, 0x0);
  ILI9163_drawChar(imag_trans, 103 - (2*11), 1, 'p', Font_11x18, 0x0);
  ILI9163_drawChar(imag_trans, 103 - (1*11), 1, 's', Font_11x18, 0x0);
  ILI9163_drawChar(imag_trans, 99, 1, ':', Font_11x18, 0x0);


  Non_HAL_CON_UInt_to_DecString_8bit(fps, fps_buf, sizeof(fps_buf));
  for(int i = 0; i < 3; i++)
  {
	  if(fps_buf[i] != 0x0)
	  {
		  ILI9163_drawChar(imag_trans, 105 + (i*11), 1, fps_buf[i], Font_11x18, 0x0);
	  }
  }
 #endif
}

/**
  * @brief  The function to CIFAR network computing and GUI rendering
  * @note	See computer_vision.h for a definition of GUI and QUANT.
  * @param  imag_trans a pointer on a frame buffer with RGB565 values (size 128*128)
  * @retval void
  */
void CIFAR_AI_block(uint16_t *imag_trans)
{
#if defined GUI
  ILI9163_drawRect(imag_trans, 30, 30, 98, 98,  2,  0x1f<<11);
#endif

  uint8_t number = CIFAR_Ai_calculate(imag_trans);

#if defined GUI
  ILI9163_fillRect(imag_trans, 60, 0, 128, 20, 0xffff);
  ILI9163_fillRect(imag_trans, 0, 128-20, 128, 128, 0xffff);


  ILI9163_drawChar(imag_trans, 93 - (3*11) + 10, 1, 'f', Font_11x18, 0x0);
  ILI9163_drawChar(imag_trans, 93 - (2*11) + 10, 1, 'p', Font_11x18, 0x0);
  ILI9163_drawChar(imag_trans, 93 - (1*11) + 10, 1, 's', Font_11x18, 0x0);
  ILI9163_drawChar(imag_trans, 89 + 10, 1, ':', Font_11x18, 0x0);

  for(int i = 0; lable[number][i] != 0; i++)
  {
	  ILI9163_drawChar(imag_trans, 1 + (i*11), 109, lable[number][i], Font_11x18, 0x0);
  }

  ILI9163_drawChar(imag_trans, 128-8, 109, number+0x30, Font_7x10, 0x0);


  Non_HAL_CON_UInt_to_DecString_8bit(fps, fps_buf, sizeof(fps_buf));
  for(int i = 0; i < 3; i++)
  {
	  if(fps_buf[i] != 0x0)
	  {
		  ILI9163_drawChar(imag_trans, 95 + (i*11) + 10, 1, fps_buf[i], Font_11x18, 0x0);
	  }
  }
#endif
}
