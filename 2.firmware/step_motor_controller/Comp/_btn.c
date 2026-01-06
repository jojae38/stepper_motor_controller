/*
 * _btn.c
 *
 *  Created on: 2026. 1. 4.
 *      Author: jaehyun
 */


#include "_btn.h"

btn_tbl_t btn_tbl[BTN_CHANNEL_MAX] = {
    {BTN1_GPIO_Port,BTN1_Pin,GPIO_PIN_RESET,GPIO_PIN_SET,false,0},
    {BTN2_GPIO_Port,BTN2_Pin,GPIO_PIN_RESET,GPIO_PIN_SET,false,0}
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
      btn_tbl[i].current_state = true;
    else
      btn_tbl[i].current_state = false;
  }
}

bool getBtnState(uint8_t ch)
{


  bool ret = btn_tbl[ch].current_state;
  return ret;
}
