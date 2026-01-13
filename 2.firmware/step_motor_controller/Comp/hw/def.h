/*
 * def.h
 *
 *  Created on: 2026. 1. 4.
 *      Author: jaehyun
 */

#ifndef HW_DEF_H_
#define HW_DEF_H_

// 서비스 파라미터 보관
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define __vo volatile

#define MAX(a,b)  ((a) > (b) ? (a) : (b))
#define MIN(a,b)  ((a) < (b) ? (a) : (b))

#define SECOND(sec)   ((sec) * 1000)
#define MINUTE(min)   ((min) * SECOND(60))


#endif /* HW_DEF_H_ */
