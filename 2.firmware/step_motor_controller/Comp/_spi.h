/*
 * _spi.h
 *
 *  Created on: 2026. 1. 4.
 *      Author: jaehyun
 */

#ifndef SPI_H_
#define SPI_H_

#include "hw_def.h"

typedef struct{
  SPI_HandleTypeDef *spi_handler;
  GPIO_TypeDef *ncs_port;
  uint16_t ncs_pin;
}spi_tbl_t;

void spiInit(void);

#endif /* SPI_H_ */
