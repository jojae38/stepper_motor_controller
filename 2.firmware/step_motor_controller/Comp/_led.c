/*
 * _led.c
 *
 *  Created on: 2026. 1. 4.
 *      Author: jaehyun
 */

#include "_led.h"

led_tbl_t led_tbl[LED_CHANNEL_MAX] =
{
    {LED1_GPIO_Port,LED1_Pin,GPIO_PIN_RESET,GPIO_PIN_SET,false},
    {LED2_GPIO_Port,LED2_Pin,GPIO_PIN_RESET,GPIO_PIN_SET,false}
};

void ledInit(void)
{
  for(int i = 0; i < LED_CHANNEL_MAX; i++)
  {
    ledOff(i);
  }
}

void ledOn(uint8_t ch)
{
  led_tbl[ch].current_state = true;
  HAL_GPIO_WritePin(led_tbl[ch].port, led_tbl[ch].pin, led_tbl[ch].on_state);
}

void ledOff(uint8_t ch)
{
  led_tbl[ch].current_state = false;
  HAL_GPIO_WritePin(led_tbl[ch].port, led_tbl[ch].pin, led_tbl[ch].off_state);
}

void ledToggle(uint8_t ch)
{
  if(led_tbl[ch].current_state == false)
    ledOn(ch);
  else
    ledOff(ch);
}
