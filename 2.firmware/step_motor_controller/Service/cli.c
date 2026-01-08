/*
 * cli.c
 *
 *  Created on: 2026. 1. 4.
 *      Author: jaehyun
 */

#include "cli.h"
#include "_uart.h"

#define CLI_BUFFER_SIZE      (512)
static uint8_t uartbuffer[CLI_BUFFER_SIZE];
static uint8_t rx_data = 0;

#define CLI_PRINT_BUF_MAX 256
char print_buffer[CLI_PRINT_BUF_MAX];

static uint32_t cliAvailable(void);
static uint8_t cliRead(void);
static uint32_t cliWrite(uint8_t *p_data, uint32_t length);

bool cliInit(void)
{
  bool ret = false;
  ret = cliOpen(115200);
  delay(100);
  return ret;
}

bool cliOpen(uint32_t baud)
{
  bool ret = false;
  ret = uartOpen(_DEF_UART1_DBG, baud, uartbuffer, CLI_BUFFER_SIZE);
  return ret;
}

uint8_t cli_len = 0;
bool cliMain(void)
{
  cli_len = cliAvailable();
  if (cli_len > 0)
  {
    for(int i = 0; i< cli_len; i++)
    {
      rx_data = cliRead();
    }
  }
  return true;
}

static uint32_t cliAvailable(void)
{
  return uartAvailable(_DEF_UART1_DBG);
}

static uint8_t cliRead(void)
{
  return uartRead(_DEF_UART1_DBG);
}

static uint32_t cliWrite(uint8_t *p_data, uint32_t length)
{
  return uartWrite(_DEF_UART1_DBG, p_data, length);
}

void cliPrintf(const char *fmt, ...)
{
  va_list arg;
  va_start (arg, fmt);
  int32_t len;
  len = vsnprintf(print_buffer, 256, fmt, arg);
  va_end (arg);

  cliWrite((uint8_t *)print_buffer,len);
}
