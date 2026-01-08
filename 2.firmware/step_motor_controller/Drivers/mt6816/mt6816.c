/*
 * mt6816.c
 *
 *  Created on: 2026. 1. 8.
 *      Author: jojae
 */
#include "mt6816.h"

float MT6816_angle;
MT6816_tbl_t MT6816_tbl;

static inline void cs_on(MT6816_tbl_t *T) {
    HAL_GPIO_WritePin(T->ncs_port, T->ncs_pin, GPIO_PIN_RESET);
}

static inline void cs_off(MT6816_tbl_t *T) {
    HAL_GPIO_WritePin(T->ncs_port, T->ncs_pin, GPIO_PIN_SET);
}

MT6816_result_t w25qxx_transmit(MT6816_tbl_t* T, uint8_t *buf, uint32_t len) {
  MT6816_result_t ret = MT6816_Err;
    if (HAL_SPI_Transmit(T->spi_handler, buf, len, HAL_MAX_DELAY) == HAL_OK) {
        ret = MT6816_Ok;
    }
    return ret;
}

MT6816_result_t w25qxx_receive(MT6816_tbl_t* T, uint8_t *buf, uint32_t len) {
  MT6816_result_t ret = MT6816_Err;
    if (HAL_SPI_Receive(T->spi_handler, buf, len, HAL_MAX_DELAY) == HAL_OK) {
        ret = MT6816_Ok;
    }
    return ret;
}

void mt6816_Init(MT6816_tbl_t T)
{
  MT6816_tbl.spi_handler = T.spi_handler;
  MT6816_tbl.ncs_port = T.ncs_port;
  MT6816_tbl.ncs_pin = T.ncs_pin;
  MT6816_angle = 0;
}

void mt6816_Main(void)
{
  //mt6816 확인
}

float getMt6816_Angle(void)
{
  return MT6816_angle;
}
