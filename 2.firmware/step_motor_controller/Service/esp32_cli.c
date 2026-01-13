/*
 * esp32_cli.c
 *
 *  Created on: 2026. 1. 4.
 *      Author: jaehyun
 */

#include "_uart.h"
#include "esp32_cli.h"

#define ESP_BUFFER_SIZE      (512)
static uint8_t uartbuffer[ESP_BUFFER_SIZE];
//static uint8_t rx_data = 0;

void esp32CliInit(void)
{
  uartOpen(_DEF_UART2_ESP32, 115200, uartbuffer, ESP_BUFFER_SIZE);
}

void esp32CliMain(void)
{
  //TODO 프로토콜
}
