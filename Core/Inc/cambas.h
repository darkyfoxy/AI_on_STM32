/*
 * cambas.h
 *
 *  Created on: 30 сент. 2021 г.
 *      Author: vlavi
 */

#ifndef INC_CAMBAS_H_
#define INC_CAMBAS_H_
#include "stm32h7xx_hal.h"
#define I2C_TIMEOUT             (1000)

typedef struct _cambus {
	I2C_HandleTypeDef *i2c;
} cambus_t;


int cambus_readb(cambus_t *bus, uint8_t slv_addr, uint8_t reg_addr,  uint8_t *reg_data);
int cambus_writeb(cambus_t *bus, uint8_t slv_addr, uint8_t reg_addr, uint8_t reg_data);

#endif /* INC_CAMBAS_H_ */
