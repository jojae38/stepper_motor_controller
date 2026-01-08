/*
 * _btn.h
 *
 *  Created on: 2026. 1. 4.
 *      Author: jaehyun
 */

#ifndef BTN_H_
#define BTN_H_

#include "hw_def.h"

typedef struct{
  GPIO_TypeDef* port;
  uint16_t      pin;
  GPIO_PinState on_state;
  GPIO_PinState off_state;
  bool          state;
  uint32_t      duration;
}btn_tbl_t;

void btnInit(void);
void btnMain(void);
bool getBtnState(uint8_t ch);

#endif /* BTN_H_ */
