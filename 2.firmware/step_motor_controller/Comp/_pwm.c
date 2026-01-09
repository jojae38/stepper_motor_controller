/*
 * _pwm.c
 *
 *  Created on: 2026. 1. 4.
 *      Author: jaehyun
 */


#include "_pwm.h"

extern TIM_HandleTypeDef htim1;

pwm_tbl_t pwm_tbl[PWM_CHANNEL_MAX] = {
    {.tim_handler = &htim1,.tim_channel = TIM_CHANNEL_1,.freq = 50000,.duty = 0.5,false},
    {.tim_handler = &htim1,.tim_channel = TIM_CHANNEL_2,.freq = 50000,.duty = 0.5,false}
};

void pwmInit(void)
{

}

void pwmMain(void)
{

}

void pwmChange(uint8_t ch, uint8_t value)
{

}
