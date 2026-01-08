/*
 * cli.h
 *
 *  Created on: 2026. 1. 4.
 *      Author: jaehyun
 */

#ifndef CLI_H_
#define CLI_H_

#include "hw_def.h"

bool cliInit(void);
bool cliMain(void);
bool cliOpen(uint32_t baud);

void cliPrintf(const char *fmt, ...);

#endif /* CLI_H_ */
