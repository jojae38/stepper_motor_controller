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
}

void hwMain(void)
{
  btnMain();
}
