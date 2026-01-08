/*
 * _can.c
 *
 *  Created on: 2026. 1. 4.
 *      Author: jaehyun
 */


#include "_can.h"

extern CAN_HandleTypeDef hcan;

typedef struct{


}can_tbl_t;

CAN_FilterTypeDef filter;
CAN_TxHeaderTypeDef tx_header;

void canInit(void)
{
  HAL_CAN_ConfigFilter(&hcan, &filter);
}

//TODO 송신


//TODO 수신

