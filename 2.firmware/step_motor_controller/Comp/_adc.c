/*
 * _adc.c
 *
 *  Created on: 2026. 1. 4.
 *      Author: jaehyun
 */


#include "_adc.h"

extern ADC_HandleTypeDef hadc1;

adc_tbl_t adc_tbl[ADC_CHANNEL_MAX] = {
    {.adc_handler = &hadc1,.adc_channel = ADC_CHANNEL_0},
    {.adc_handler = &hadc1,.adc_channel = ADC_CHANNEL_1}
};

uint16_t adc_values[2];

void adcInit(void)
{
  memset(adc_values, 0, sizeof(adc_values));
  HAL_ADC_Start_DMA(&hadc1, (uint32_t*)adc_values, 2);
  return;
}

void adcMain(void)
{
  //TODO 값 확인 및 출력
}
