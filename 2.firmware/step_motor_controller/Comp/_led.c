/*
 * _led.c
 *
 *  Created on: 2026. 1. 4.
 *      Author: jaehyun
 */

#include "_led.h"

led_tbl_t led_tbl[LED_CHANNEL_MAX] =
{
    {.port = LED1_GPIO_Port, .pin = LED1_Pin, .on_state = GPIO_PIN_RESET, .off_state = GPIO_PIN_SET, .state = false},
    {.port = LED2_GPIO_Port, .pin = LED2_Pin, .on_state = GPIO_PIN_RESET, .off_state = GPIO_PIN_SET, .state = false}
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
  led_tbl[ch].state = true;
  HAL_GPIO_WritePin(led_tbl[ch].port, led_tbl[ch].pin, led_tbl[ch].on_state);
}

void ledOff(uint8_t ch)
{
  led_tbl[ch].state = false;
  HAL_GPIO_WritePin(led_tbl[ch].port, led_tbl[ch].pin, led_tbl[ch].off_state);
}

void ledToggle(uint8_t ch)
{
  if(led_tbl[ch].state == false)
    ledOn(ch);
  else
    ledOff(ch);
}
