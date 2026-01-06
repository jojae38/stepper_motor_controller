/*
 * bsp.h
 *
 *  Created on: 2026. 1. 4.
 *      Author: jaehyun
 */

#ifndef BSP_BSP_H_
#define BSP_BSP_H_

#include "stm32f1xx.h"
#include "stm32f103xb.h"
#include "stm32f1xx_hal.h"

void delay(uint32_t ms);
uint32_t millis(void);
void Reset(void);

#endif /* BSP_BSP_H_ */
