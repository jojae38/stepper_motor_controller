/*
 * cli.h
 *
 *  Created on: Jul 31, 2025
 *      Author: jojae
 */

#ifndef SERVICES_CLI_H_
#define SERVICES_CLI_H_

#include "hw_def.h"
#include "mt6816.h"

#ifndef _USE_SIMPLE_CLI

#define CLI_CMD_LIST_MAX      HW_CLI_CMD_LIST_MAX
#define CLI_CMD_NAME_MAX      HW_CLI_CMD_NAME_MAX

#define CLI_LINE_HIS_MAX      HW_CLI_LINE_HIS_MAX
#define CLI_LINE_BUF_MAX      HW_CLI_LINE_BUF_MAX


typedef struct
{
  uint16_t   argc;
  char     **argv;

  int32_t  (*getData)(uint8_t index);
  float    (*getFloat)(uint8_t index);
  char    *(*getStr)(uint8_t index);
  bool     (*isStr)(uint8_t index, char *p_str);
} cli_args_t;


bool cliInit(void);
bool cliOpen(uint8_t ch, uint32_t baud);
bool cliOpenLog(uint8_t ch, uint32_t baud);
bool cliMain(void);
void cliPrintf(const char *fmt, ...);
bool cliAdd(const char *cmd_str, void (*p_func)(cli_args_t *));
bool cliKeepLoop(void);
uint32_t cliAvailable(void);
uint8_t  cliRead(void);
uint32_t cliWrite(uint8_t *p_data, uint32_t length);

//추가된 명령어
void cliEmpty(cli_args_t *args);        //빈 CLI 명령어
void cliShowList(cli_args_t *args);     //help
void cliPwmChange(cli_args_t *args);    //pwm 변경
void cliMt6816Value(cli_args_t *args);  //MT6816 각도
void cliRotateMotor(cli_args_t *args);  //모터 회전

#endif

#endif /* SERVICES_CLI_H_ */
