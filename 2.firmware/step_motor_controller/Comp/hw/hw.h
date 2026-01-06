/*
 * hw.h
 *
 *  Created on: 2026. 1. 4.
 *      Author: jaehyun
 */

#ifndef HW_HW_H_
#define HW_HW_H_

#include <_btn.h>
#include "hw_def.h"
#include "_adc.h"
#include "_can.h"
#include "_led.h"
#include "_pwm.h"
#include "_spi.h"
#include "_uart.h"


void hwInit(void);
void hwMain(void);

#endif /* HW_HW_H_ */
