/*
 * motor_control.h
 *
 *  Created on: 2026. 1. 8.
 *      Author: jojae
 */

#ifndef MOTOR_CONTROL_H_
#define MOTOR_CONTROL_H_

#include "hw_def.h"

void motorInit(void);
void motorMain(void);
float getMotorAngle(void);
float getMotorDegree(void);
void  printMotorDegree(void);

#endif /* MOTOR_CONTROL_H_ */
