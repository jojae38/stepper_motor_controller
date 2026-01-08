/*
 * mt6816.h
 *
 *  Created on: 2026. 1. 8.
 *      Author: jojae
 */

#include "hw_def.h"

#ifndef MT6816_MT6816_H_
#define MT6816_MT6816_H_

#define _2PI                                6.28318530718f
#define MT6816_CPR                          16384.0f

#define MT6816_READ_REG_03                  0x8300
#define MT6816_READ_REG_04                  0x8400

#define MT6816_NO_MAGNET_WARNING_BIT        0x0002
#define MT6816_BITORDER                     MSBFIRST

typedef struct{
  SPI_HandleTypeDef* spi_handler;
  GPIO_TypeDef*      ncs_port;
  uint32_t           ncs_pin;
}MT6816_tbl_t;

typedef enum {
    MT6816_Ok,     // 0
    MT6816_Err,    // 1
    MT6816_Timeout // 2
} MT6816_result_t;

void mt6816_Init(MT6816_tbl_t T);
void mt6816_Main(void);

#endif /* MT6816_MT6816_H_ */
