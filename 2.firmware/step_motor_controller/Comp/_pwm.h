/*
 * _pwm.h
 *
 *  Created on: 2026. 1. 4.
 *      Author: jaehyun
 */

#ifndef PWM_H_
#define PWM_H_

#include "hw_def.h"

typedef struct{
  TIM_HandleTypeDef* tim_handler;
  uint16_t           tim_channel;
  uint32_t           freq;
  uint32_t           counter_period;
  float              duty;
  bool               state;
}pwm_tbl_t;

void pwmInit(void);
void pwmMain(void);
void pwmChangeDuty(uint8_t ch, float duty);

#endif /* PWM_H_ */
