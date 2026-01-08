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


void adcInit(void)
{

}

void adcMain(void)
{

}
