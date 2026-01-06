/*
 * bsp.c
 *
 *  Created on: 2026. 1. 4.
 *      Author: jaehyun
 */

#include "bsp.h"

void delay(uint32_t ms)
{
  HAL_Delay(ms);
}

uint32_t millis(void)
{
  return HAL_GetTick();
}

void Reset(void)
{
  NVIC_SystemReset();
}
