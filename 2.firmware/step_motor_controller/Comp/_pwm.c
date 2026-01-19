/*
 * _pwm.c
 *
 *  Created on: 2026. 1. 4.
 *      Author: jaehyun
 */


#include "_pwm.h"

extern TIM_HandleTypeDef htim1;

pwm_tbl_t pwm_tbl[PWM_CHANNEL_MAX] = {
    {.tim_handler = &htim1,.tim_channel = TIM_CHANNEL_1,.freq = 20000,.counter_period = 100,.duty = 0.1,false},
    {.tim_handler = &htim1,.tim_channel = TIM_CHANNEL_2,.freq = 20000,.counter_period = 100,.duty = 0.1,false}
};

void pwmInit(void)
{
  return;
}

void pwmMain(void)
{
  return;
}

void pwmChangeDuty(uint8_t ch, float duty)
{
  if(duty >= 1) duty = 1;
  if(duty <= 0) duty = 0;
  pwm_tbl[ch].duty = duty;
  uint32_t pulse = pwm_tbl[ch].counter_period * duty;
  __HAL_TIM_SET_COMPARE(pwm_tbl[ch].tim_handler, pwm_tbl[ch].tim_channel, pulse);
}
