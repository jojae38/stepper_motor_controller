/*
 * _adc.h
 *
 *  Created on: 2026. 1. 4.
 *      Author: jaehyun
 */

#ifndef ADC_H_
#define ADC_H_

#include "hw_def.h"

typedef struct{
  ADC_HandleTypeDef * adc_handler;
  uint16_t      adc_channel;
}adc_tbl_t;

void adcInit(void);
void adcMain(void);

#endif /* ADC_H_ */
