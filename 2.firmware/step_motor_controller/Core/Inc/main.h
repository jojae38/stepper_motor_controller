/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define ADC_ENC_Pin GPIO_PIN_4
#define ADC_ENC_GPIO_Port GPIOA
#define MT6816_CSN_Pin GPIO_PIN_0
#define MT6816_CSN_GPIO_Port GPIOB
#define WS2812B_SIGNAL_Pin GPIO_PIN_10
#define WS2812B_SIGNAL_GPIO_Port GPIOB
#define IN_B_M_Pin GPIO_PIN_12
#define IN_B_M_GPIO_Port GPIOB
#define IN_B_P_Pin GPIO_PIN_13
#define IN_B_P_GPIO_Port GPIOB
#define IN_A_M_Pin GPIO_PIN_14
#define IN_A_M_GPIO_Port GPIOB
#define IN_A_P_Pin GPIO_PIN_15
#define IN_A_P_GPIO_Port GPIOB
#define VREF_PWM_A_Pin GPIO_PIN_8
#define VREF_PWM_A_GPIO_Port GPIOA
#define VREF_PWM_B_Pin GPIO_PIN_9
#define VREF_PWM_B_GPIO_Port GPIOA
#define LED1_Pin GPIO_PIN_15
#define LED1_GPIO_Port GPIOA
#define LED2_Pin GPIO_PIN_3
#define LED2_GPIO_Port GPIOB
#define BTN1_Pin GPIO_PIN_4
#define BTN1_GPIO_Port GPIOB
#define BTN2_Pin GPIO_PIN_5
#define BTN2_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
