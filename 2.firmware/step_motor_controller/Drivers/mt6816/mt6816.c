/*
 * mt6816.c
 *
 *  Created on: 2026. 1. 8.
 *      Author: jojae
 */
#include "mt6816.h"

uint16_t MT6816_angle_data;
float MT6816_angle;
MT6816_tbl_t MT6816_tbl;

bool MT6816_parityCheck(uint16_t data);

static inline void cs_on(MT6816_tbl_t *T) {
    HAL_GPIO_WritePin(T->ncs_port, T->ncs_pin, GPIO_PIN_RESET);
}

static inline void cs_off(MT6816_tbl_t *T) {
    HAL_GPIO_WritePin(T->ncs_port, T->ncs_pin, GPIO_PIN_SET);
}

MT6816_result_t MT6816_transmit(MT6816_tbl_t* T, uint8_t *buf, uint32_t len) {
  MT6816_result_t ret = MT6816_Err;
    if (HAL_SPI_Transmit(T->spi_handler, buf, len, HAL_MAX_DELAY) == HAL_OK) {
        ret = MT6816_Ok;
    }
    return ret;
}

MT6816_result_t MT6816_receive(MT6816_tbl_t* T, uint8_t *buf, uint32_t len) {
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
  MT6816_tbl.no_magnet = false;
  MT6816_angle_data = 0;
  MT6816_angle = 0;
}

void mt6816_Main(void)
{
  MT6816_angle_data = 0;
  uint8_t rx[2] = {0};
  uint16_t reg = 0;
  uint16_t raw = 0;

  cs_on(&MT6816_tbl);
  //첫번째 값
  reg = MT6816_READ_REG_03;
  {
    uint8_t tx[2] = {(uint8_t)(reg >> 8),(uint8_t)(reg & 0xFF)};
    if(MT6816_transmit(&MT6816_tbl, tx, 2) != MT6816_Ok) goto cleanup;
    if(MT6816_receive(&MT6816_tbl, &rx[0], 1)!= MT6816_Ok) goto cleanup;
  }

  //두번째 값
  reg = MT6816_READ_REG_04;
  {
    uint8_t tx[2] = {(uint8_t)(reg >> 8),(uint8_t)(reg & 0xFF)};
    if(MT6816_transmit(&MT6816_tbl, tx, 2) != MT6816_Ok) goto cleanup;
    if(MT6816_receive(&MT6816_tbl, &rx[0], 1)!= MT6816_Ok) goto cleanup;
  }
  cs_off(&MT6816_tbl);

  //mt6816 확인
  raw = ((uint16_t)rx[0] << 8)|(uint16_t)rx[1];
  MT6816_angle_data = raw;
  //주위 자석 유무 확인
  if ((MT6816_angle_data & MT6816_NO_MAGNET_WARNING_BIT) == MT6816_NO_MAGNET_WARNING_BIT)
  {
    MT6816_tbl.no_magnet = true;
    goto cleanup;
  }
  else
    MT6816_tbl.no_magnet = false;
  //패리티 체크
  if(MT6816_parityCheck(MT6816_angle_data) == false) goto cleanup;
  //각도 갱신
  MT6816_angle_data = MT6816_angle_data >> 2;
  MT6816_angle = (_2PI * (float)MT6816_angle_data) / MT6816_CPR;

cleanup:
  cs_off(&MT6816_tbl);
}

bool MT6816_parityCheck(uint16_t data) {
    data ^= data >> 8;
    data ^= data >> 4;
    data ^= data >> 2;
    data ^= data >> 1;

    return (~data) & 1;
}

float getMt6816_Angle(void)
{
  return MT6816_angle;
}
