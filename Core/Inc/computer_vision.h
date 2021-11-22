/**
  ******************************************************************************
  * @file       computer_vision.h
  * @brief      Computer vision on STM32 include file.
  *
  * @note       This file must be included in the main project (in main.h or
  *             main.c).
  *
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

#ifndef INC_COMPUTER_VISION_H_
#define INC_COMPUTER_VISION_H_

/* Includes ------------------------------------------------------------------*/
#include "stm32h7xx_hal.h"

/* Private defines -----------------------------------------------------------*/
//You need to define a GUI definition to render the GUI.
#define GUI
//You need to define a QUANT definition to use TFLite with quantization.
#define QUANT

/* Private types -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private constants ---------------------------------------------------------*/
/* Private macros ------------------------------------------------------------*/

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/* Exported functions prototypes ---------------------------------------------*/
void MNIST_AI_block(uint16_t *imag_trans);
void CIFAR_AI_block(uint16_t *imag_trans);
void CIFAR100_AI_block(uint16_t *imag_trans);
void MobileNet_AI_block(uint16_t *imag_trans);

#endif /* INC_COMPUTER_VISION_H_ */
