/*
 * simple_cli.h
 *
 *  Created on: 2026. 1. 13.
 *      Author: jojae
 */

#ifndef SIMPLE_CLI_H_
#define SIMPLE_CLI_H_

#ifdef _USE_SIMPLE_CLI

#include "hw_def.h"

bool cliInit(void);
bool cliMain(void);
bool cliOpen(uint32_t baud);

void cliPrintf(const char *fmt, ...);

#endif

#endif /* SIMPLE_CLI_H_ */
