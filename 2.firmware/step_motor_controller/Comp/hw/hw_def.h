/*
 * hw_def.h
 *
 *  Created on: 2026. 1. 4.
 *      Author: jaehyun
 */

#ifndef HW_HW_DEF_H_
#define HW_HW_DEF_H_

//하드웨어 특성 파라미터 보관
#include "def.h"
#include "main.h"
#include "bsp.h"

#define LED_CHANNEL_MAX 2
#define BTN_CHANNEL_MAX 2
#define PWM_CHANNEL_MAX 2
#define ADC_CHANNEL_MAX 2
#define UART_CHANNEL_MAX 2

// LED
#define _DEF_LED1   0
#define _DEF_LED2   1

// UART
#define _DEF_UART1_DBG    0
#define _DEF_UART2_ESP32  1

// BTN
#define _DEF_BTN1  0
#define _DEF_BTN2  1

// PWM
#define _DEF_A_PWM1  0
#define _DEF_B_PWM2  1

// ADC
#define _DEF_ADC1  0
#define _DEF_ADC2  1

#endif /* HW_HW_DEF_H_ */
