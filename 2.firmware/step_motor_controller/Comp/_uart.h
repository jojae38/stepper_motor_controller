/*
 * _uart.h
 *
 *  Created on: 2026. 1. 4.
 *      Author: jaehyun
 */

#ifndef UART_H_
#define UART_H_

#include "hw_def.h"

void      uartInit(void);
bool      uartOpen(uint8_t ch, uint32_t baud, uint8_t* p_buffer, uint16_t buffer_size);
uint32_t  uartAvailable(uint8_t ch);
uint8_t   uartRead(uint8_t ch);
uint32_t  uartWrite(uint8_t ch, uint8_t *p_data, uint32_t length);
uint32_t  uartPrintf(uint8_t ch, const char *fmt, ...);
uint32_t  uartGetBaud(uint8_t ch);
uint32_t  uartFlush(uint8_t ch);
bool      uartChangeBaud(uint8_t ch, uint32_t baud);

#endif /* UART_H_ */
