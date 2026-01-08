/*
 * ap.c
 *
 *  Created on: 2026. 1. 4.
 *      Author: jaehyun
 */

#include "ap.h"

void apInit(void)
{
  motorInit();
}


void apMain(void)
{
	while(true)
	{
	  motorMain();
	}
}
