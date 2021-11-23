/**
  ******************************************************************************
  * @file       computer_vision.c
  * @brief      This file provides functions to testing computer vision on STM32

  * @author     darkyfoxy [*GitHub*](https://github.com/darkyfoxy)
  * @version    0.02
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
#include "imagnet_lables.h"
#include "cifar_superclasses.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
static uint8_t string_buf[11];

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
#ifndef QUANT
static uint8_t CIFAR_Ai_calculate(uint16_t *frameBuffer);
#else
static uint8_t Q_CIFAR_Ai_calculate(uint16_t *frameBuffer);
#endif

#ifdef QUANT
static uint8_t Q_CIFAR100_Ai_calculate(uint16_t *frameBuffer);
#endif


#ifndef QUANT
static uint8_t MNIST_Ai_calculate(uint16_t *frameBuffer);
#else
static uint8_t Q_MNIST_Ai_calculate(uint16_t *frameBuffer);
#endif

static void MobileNet_Ai_calculate(uint16_t *frameBuffer, uint16_t *lables);

static void Non_HAL_CON_UInt_to_DecString_8bit(uint8_t data, uint8_t *decstr, uint8_t sizebuf);


/* Private functions ---------------------------------------------------------*/

#ifndef QUANT
/**
  * @brief  The function to preparing data for the CIFAR network without quantization,
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

	uint8_t res = 0;
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
  * @brief  The function to preparing data for the CIFAR network with quantization,
  * 		starting the network and calculating a maximum element of a network output
  * @note	See computer_vision.h for a definition of GUI
  * @param  frameBuffer a pointer on a frame buffer with RGB565 values (size 128*128)
  * @retval res a uint8_t value with a number of a max item in a network output
  */
static uint8_t Q_CIFAR_Ai_calculate(uint16_t *frameBuffer)
{
	int8_t input[32][32][3];
	int8_t output[10];

	for(int i = 0; i < 32; i ++)
	{
		for(int j = 0; j < 32; j ++)
		{
			uint16_t RGB_sample = frameBuffer[(128*32) + 32 + (i*128*2) + (j*2)];
			float B = (float)(RGB_sample & 0x1f) / 32.0;
			float G = (float)((RGB_sample >> 6) & 0x1f) / 32.0;
			float R = (float)(RGB_sample >> 11) / 32.0;

			input[i][j][0] = (int8_t)((R - 0.5) * 255);
			input[i][j][1] = (int8_t)((G - 0.5) * 255);
			input[i][j][2] = (int8_t)((B - 0.5) * 255);
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

#ifdef QUANT
/**
  * @brief  The function to preparing data for the CIFAR100 network with quantization,
  * 		starting the network and calculating a maximum element of a network output
  * @note	See computer_vision.h for a definition of GUI
  * @param  frameBuffer a pointer on a frame buffer with RGB565 values (size 128*128)
  * @retval res a uint8_t value with a number of a max item in a network output
  */
static uint8_t Q_CIFAR100_Ai_calculate(uint16_t *frameBuffer)
{
	int8_t input[32][32][3];
	int8_t output[20];

	for(int i = 0; i < 32; i ++)
	{
		for(int j = 0; j < 32; j ++)
		{
			uint16_t RGB_sample = frameBuffer[(128*32) + 32 + (i*128*2) + (j*2)];
			float B = (float)(RGB_sample & 0x1f) / 32.0;
			float G = (float)((RGB_sample >> 6) & 0x1f) / 32.0;
			float R = (float)(RGB_sample >> 11) / 32.0;

			input[i][j][0] = (int8_t)((R - 0.5) * 255);
			input[i][j][1] = (int8_t)((G - 0.5) * 255);
			input[i][j][2] = (int8_t)((B - 0.5) * 255);
		}
	}



	SCB_EnableDCache();
	my_ai_run((void *)input, (void *)output);
	SCB_DisableDCache();

	uint8_t res = 0;
	int8_t max = output[0];

	for(int g = 1; g < 20; g++)
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

	uint8_t res = 0;
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
  * @brief  The function to preparing data for the MobileNet network with quantization,
  * 		starting the network and calculating a maximum element of a network output
  * @param  frameBuffer a pointer on a frame buffer with RGB565 values (size 128*128)
  * @retval res a uint16_t value with a number of a max item in a network output
  */
static void MobileNet_Ai_calculate(uint16_t *frameBuffer, uint16_t *lables)
{
	uint8_t input[128][128][3];
	uint8_t output[1001];

	for(int i = 0; i < 128; i ++)
	{
		for(int j = 0; j < 128; j ++)
		{
			uint16_t RGB_sample = frameBuffer[(i*128) + j];
			float B = (float)(RGB_sample & 0x1f) / 32.0;
			float G = (float)((RGB_sample >> 6) & 0x1f) / 32.0;
			float R = (float)(RGB_sample >> 11) / 32.0;

			input[i][j][0] = (uint8_t)(R * 255);
			input[i][j][1] = (uint8_t)(G * 255);
			input[i][j][2] = (uint8_t)(B * 255);
		}
	}

	SCB_EnableDCache();
	my_ai_run((void *)input, (void *)output);
	SCB_DisableDCache();

	uint16_t max[5] = {0};

	for(int i = 0; i < 1001; i++)
	{
		for(int n = 4; n >= 0; n--)
		{
			if(output[i] > max[n])
			{
			if(n != 0)
			{
				uint16_t t_max = max[n];
				uint16_t t_lable = lables[n];
				for(int g = n-1; g >= 0; g--)
				{
					uint16_t temp = lables[g];
					lables[g] = t_lable;
					t_lable = temp;

					temp = max[g];
					max[g] = t_max;
					t_max = temp;
				}

			}
			max[n] = output[i];
			lables[n] = i;
			break;
			}
		}
	}
}


/**
  * @brief  The function to preparing data for the person_detect network with quantization,
  * 		starting the network and calculating a maximum element of a network output
  * @note	See computer_vision.h for a definition of GUI
  * @param  frameBuffer a pointer on a frame buffer with RGB565 values (size 128*128)
  * @retval res a uint8_t value with a number of a max item in a network output
  */
static uint8_t Person_detect_Ai_calculate(uint16_t *frameBuffer)
{
	int8_t input[96][96];
	int8_t output[2];

	for(int i = 0; i < 96; i ++)
	{
		for(int j = 0; j < 96; j ++)
		{
			uint16_t RGB_sample = frameBuffer[(128*16) + 16 + (i*128) + (j)];
			float B = (float)(RGB_sample & 0x1f) / 128.0;
			float G = (float)((RGB_sample >> 5) & 0x3f) / 128.0;
			float R = (float)(RGB_sample >> 11) / 128.0;
			float sum = (R + G + B);

			input[i][j] = (int8_t)((sum - 0.5) * 255);
		}
	}

	SCB_EnableDCache();
	my_ai_run((void *)input, (void *)output);
	SCB_DisableDCache();

	uint8_t res = (uint8_t)((float)(output[1] + 128) * 0.39);
	return res;
}


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


  Non_HAL_CON_UInt_to_DecString_8bit(fps, string_buf, sizeof(string_buf));
  for(int i = 0; i < 3; i++)
  {
	  if(string_buf[i] != 0x0)
	  {
		  ILI9163_drawChar(imag_trans, 105 + (i*11), 1, string_buf[i], Font_11x18, 0x0);
	  }
  }
 #endif
}

/**
  * @brief  The function to CIFAR network computing and GUI rendering
  * @note	See computer_vision.h for a definition of GUI and QUANT
  * @param  imag_trans a pointer on a frame buffer with RGB565 values (size 128*128)
  * @retval void
  */
void CIFAR_AI_block(uint16_t *imag_trans)
{
#if defined GUI
  ILI9163_drawRect(imag_trans, 30, 30, 98, 98,  2,  0x1f<<11);
#endif

#ifndef QUANT
  uint8_t number = CIFAR_Ai_calculate(imag_trans);
#else
  uint8_t number = Q_CIFAR_Ai_calculate(imag_trans);
#endif

#if defined GUI
  ILI9163_fillRect(imag_trans, 70, 0, 128, 20, 0xffff);
  ILI9163_fillRect(imag_trans, 0, 107, 128, 128, 0xffff);


  ILI9163_drawChar(imag_trans, 103 - (3*11), 1, 'f', Font_11x18, 0x0);
  ILI9163_drawChar(imag_trans, 103 - (2*11), 1, 'p', Font_11x18, 0x0);
  ILI9163_drawChar(imag_trans, 103 - (1*11), 1, 's', Font_11x18, 0x0);
  ILI9163_drawChar(imag_trans, 99, 1, ':', Font_11x18, 0x0);

  for(int i = 0; lable[number][i] != 0; i++)
  {
	  ILI9163_drawChar(imag_trans, 1 + (i*11), 109, lable[number][i], Font_11x18, 0x0);
  }

  ILI9163_drawChar(imag_trans, 120, 109, number+0x30, Font_7x10, 0x0);

  Non_HAL_CON_UInt_to_DecString_8bit(fps, string_buf, sizeof(string_buf));
  for(int i = 0; string_buf[i] != 0x0; i++)
  {
	ILI9163_drawChar(imag_trans, 105 + (i*11), 1, string_buf[i], Font_11x18, 0x0);
  }
#endif
}

/**
  * @brief  The function to CIFAR100 network computing and GUI rendering
  * @note	See computer_vision.h for a definition of GUI and QUANT
  * @note	It work with #define QUANT in computer_vision.h only
  * @param  imag_trans a pointer on a frame buffer with RGB565 values (size 128*128)
  * @retval void
  */
void CIFAR100_AI_block(uint16_t *imag_trans)
{
#if defined GUI
  ILI9163_drawRect(imag_trans, 30, 30, 98, 98,  2,  0x1f<<11);
#endif

#ifdef QUANT
  uint8_t number = Q_CIFAR100_Ai_calculate(imag_trans);
#endif

#if defined GUI
  ILI9163_fillRect(imag_trans, 70, 0, 128, 20, 0xffff);
  ILI9163_fillRect(imag_trans, 0, 117, 128, 128, 0xffff);


  ILI9163_drawChar(imag_trans, 103 - (3*11), 1, 'f', Font_11x18, 0x0);
  ILI9163_drawChar(imag_trans, 103 - (2*11), 1, 'p', Font_11x18, 0x0);
  ILI9163_drawChar(imag_trans, 103 - (1*11), 1, 's', Font_11x18, 0x0);
  ILI9163_drawChar(imag_trans, 99, 1, ':', Font_11x18, 0x0);

  for(int i = 0; cifar_superclasses[number][i] != 0; i++)
  {
	  ILI9163_drawChar(imag_trans, 1 + (i*7), 118, cifar_superclasses[number][i], Font_7x10, 0x00);
  }

  Non_HAL_CON_UInt_to_DecString_8bit(fps, string_buf, sizeof(string_buf));
  for(int i = 0; string_buf[i] != 0x0; i++)
  {
	ILI9163_drawChar(imag_trans, 105 + (i*11), 1, string_buf[i], Font_11x18, 0x0);
  }
#endif
}

/**
  * @brief  The function to MobileNet network computing and GUI rendering
  * @note	See computer_vision.h for a definition of GUI.
  * @param  imag_trans a pointer on a frame buffer with RGB565 values (size 128*128)
  * @retval void
  */
void MobileNet_AI_block(uint16_t *imag_trans)
{

  uint16_t top_clas[5] = {0};
  MobileNet_Ai_calculate(imag_trans, top_clas);

  uint16_t number;

#if defined GUI
  ILI9163_fillRect(imag_trans, 91, 0, 128, 12, 0xffff);


  ILI9163_drawChar(imag_trans, 112 - (3*7), 1, 'f', Font_7x10, 0x0);
  ILI9163_drawChar(imag_trans, 112 - (2*7), 1, 'p', Font_7x10, 0x0);
  ILI9163_drawChar(imag_trans, 112 - (1*7), 1, 's', Font_7x10, 0x0);
  ILI9163_drawChar(imag_trans, 109, 1, ':', Font_7x10, 0x0);

  for(int x = 0; x < 128; x++)
  {
	  for(int y = 0; y < 50; y++)
	  {
		  imag_trans[128*78 + x + y*128] = imag_trans[128*78 + x + y*128] | 0b1100011000011000;
	  }
  }

  for(int m = 0; m <= 4; m++)
  {
	  number = top_clas[m];
	  ILI9163_drawChar(imag_trans, 0, 118 - (m*10), 0x35 - m, Font_7x10, 0x00);
	  for(int i = 0; mobilenet_lables[number][i] != 0; i++)
	  {
		  ILI9163_drawChar(imag_trans, 7 + (i*7), 118 - (m*10), mobilenet_lables[number][i], Font_7x10, 0x00);
	  }
  }

  Non_HAL_CON_UInt_to_DecString_8bit(fps, string_buf, sizeof(string_buf));
  for(int i = 0; string_buf[i] != 0; i++)
  {
	  ILI9163_drawChar(imag_trans, 113 + (i*7), 1, string_buf[i], Font_7x10, 0x0);
  }
#endif
}

/**
  * @brief  The function to MobileNet network computing and GUI rendering
  * @note	See person_detect.h for a definition of GUI.
  * @param  imag_trans a pointer on a frame buffer with RGB565 values (size 128*128)
  * @retval void
  */
void Person_detect_AI_block(uint16_t *imag_trans)
{
  uint8_t number = Person_detect_Ai_calculate(imag_trans);

#if defined GUI
  ILI9163_fillRect(imag_trans, 70, 0, 128, 20, 0xffff);
  ILI9163_fillRect(imag_trans, 0, 109, 128, 128, 0xffff);


  ILI9163_drawChar(imag_trans, 103 - (3*11), 1, 'f', Font_11x18, 0x0);
  ILI9163_drawChar(imag_trans, 103 - (2*11), 1, 'p', Font_11x18, 0x0);
  ILI9163_drawChar(imag_trans, 103 - (1*11), 1, 's', Font_11x18, 0x0);
  ILI9163_drawChar(imag_trans, 99, 1, ':', Font_11x18, 0x0);

  char *str_person = "person";
  for(int i = 0; str_person[i] != 0x0; i++)
  {
    ILI9163_drawChar(imag_trans, 1 + (i*11), 110, str_person[i], Font_11x18, 0x0);
  }
  ILI9163_drawChar(imag_trans, 64, 110, ':', Font_11x18, 0x0);
  ILI9163_drawChar(imag_trans, 94, 110, '%', Font_11x18, 0x0);

  Non_HAL_CON_UInt_to_DecString_8bit(number, string_buf, sizeof(string_buf));
  for(int i = 0; string_buf[i] != 0x0; i++)
  {
  	ILI9163_drawChar(imag_trans, 72 + (i*11), 110, string_buf[i], Font_11x18, 0x0);
  }

  Non_HAL_CON_UInt_to_DecString_8bit(fps, string_buf, sizeof(string_buf));
  for(int i = 0; string_buf[i] != 0x0; i++)
  {
	ILI9163_drawChar(imag_trans, 105 + (i*11), 1, string_buf[i], Font_11x18, 0x0);
  }
#endif
}
