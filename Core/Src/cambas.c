/*
 * cambas.c
 *
 *  Created on: 30 сент. 2021 г.
 *      Author: vlavi
 */

#include "cambas.h"


int cambus_readb(cambus_t *bus, uint8_t slv_addr, uint8_t reg_addr, uint8_t *reg_data)
{
    int ret = 0;

    if((HAL_I2C_Master_Transmit(bus->i2c, slv_addr, &reg_addr, 1, I2C_TIMEOUT) != HAL_OK)
    || (HAL_I2C_Master_Receive (bus->i2c, slv_addr, reg_data, 1, I2C_TIMEOUT) != HAL_OK)) {
        ret = -1;
    }
    return ret;
}

int cambus_writeb(cambus_t *bus, uint8_t slv_addr, uint8_t reg_addr, uint8_t reg_data)
{
    int ret=0;
    uint8_t buf[] = {reg_addr, reg_data};

    if(HAL_I2C_Master_Transmit(bus->i2c, slv_addr, buf, 2, I2C_TIMEOUT) != HAL_OK) {
        ret = -1;
    }
    return ret;
}
