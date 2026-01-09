/*
 * hw.c
 *
 *  Created on: 2026. 1. 4.
 *      Author: jaehyun
 */


#include "hw.h"

void hwInit(void)
{
  ledInit();
  btnInit();

  //통신
  uartInit();
  cliInit();
  esp32CliInit();

  //센서
}

static __vo uint32_t timer_100ms = 0;
static __vo uint32_t last_100ms_tick = 0;
static __vo uint32_t last_500ms = 0;
static __vo uint32_t last_1s    = 0;
static __vo uint32_t last_5s    = 0;

void hwMain(void)
{
  timer_100ms = millis()/100;

  if(timer_100ms != last_100ms_tick)
  {
    //0.1초마다 실행
    last_100ms_tick = timer_100ms;

    //0.5초마다 실행
    if(timer_100ms - last_500ms >= 5)
    {
      last_500ms = timer_100ms;
      btnMain();

    }

    //1초마다 실행
    if(timer_100ms - last_1s >= 10)
    {
      last_1s = timer_100ms;
    }

    //5초마다 실행
    if(timer_100ms - last_5s >= 50)
    {
      last_5s = timer_100ms;
    }
  }
  //상시 실행
  cliMain();
  esp32CliMain();
}
