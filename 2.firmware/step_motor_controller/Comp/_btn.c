/*
 * _btn.c
 *
 *  Created on: 2026. 1. 4.
 *      Author: jaehyun
 */


#include "_btn.h"

btn_tbl_t btn_tbl[BTN_CHANNEL_MAX] = {
    {.port = BTN1_GPIO_Port, .pin = BTN1_Pin,.on_state = GPIO_PIN_RESET,.off_state = GPIO_PIN_SET, .state = false, .duration = 0},
    {.port = BTN2_GPIO_Port, .pin = BTN2_Pin,.on_state = GPIO_PIN_RESET,.off_state = GPIO_PIN_SET, .state = false, .duration = 0}
};

void btnInit(void)
{
  return;
}

void btnMain(void)
{
  for(int i = 0; i< BTN_CHANNEL_MAX; i++)
  {
    GPIO_PinState tmp_state = HAL_GPIO_ReadPin(btn_tbl[i].port, btn_tbl[i].pin);
    if(btn_tbl[i].on_state == tmp_state)
    {
      btn_tbl[i].state = true;
      btn_tbl[i].duration += 100;
    }
    else
    {
      btn_tbl[i].state = false;
      btn_tbl[i].duration = 0;
    }
  }
}

bool getBtnState(uint8_t ch)
{
  bool ret = btn_tbl[ch].state;
  return ret;
}
