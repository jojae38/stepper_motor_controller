/*
 * _pwm.h
 *
 *  Created on: 2026. 1. 4.
 *      Author: jaehyun
 */

#ifndef PWM_H_
#define PWM_H_

#include "hw_def.h"

typedef struct{
  GPIO_TypeDef* port;
  uint16_t      pin;
  float         duty;
  bool          state;
}pwm_tbl_t;

void pwmInit(void);
void pwmMain(void);
void pwmChange(uint8_t ch, uint8_t value);

#endif /* PWM_H_ */
