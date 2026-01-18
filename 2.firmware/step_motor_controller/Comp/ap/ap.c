/*
 * ap.c
 *
 *  Created on: 2026. 1. 4.
 *      Author: jaehyun
 */

#include "ap.h"

void apInit(void)
{
  hwInit();
//  motorInit();
}


void apMain(void)
{
	while(true)
	{
	  hwMain();
//ledOn(0);
//delay(500);
//ledOff(0);
//delay(500);
//ledOn(1);
//delay(500);
//ledOff(1);
//delay(500);
//	  motorMain();
	}
}
