/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
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
#include "stm32f4xx_hal.h"

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

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define LED_Pin GPIO_PIN_13
#define LED_GPIO_Port GPIOC
#define JOY_X_Pin GPIO_PIN_0
#define JOY_X_GPIO_Port GPIOA
#define JOY_Y_Pin GPIO_PIN_1
#define JOY_Y_GPIO_Port GPIOA
#define JOY_SW_Pin GPIO_PIN_2
#define JOY_SW_GPIO_Port GPIOA
#define HD44780_RS_Pin GPIO_PIN_3
#define HD44780_RS_GPIO_Port GPIOA
#define HD44780_E_Pin GPIO_PIN_4
#define HD44780_E_GPIO_Port GPIOA
#define HD44780_D4_Pin GPIO_PIN_5
#define HD44780_D4_GPIO_Port GPIOA
#define HD44780_D5_Pin GPIO_PIN_6
#define HD44780_D5_GPIO_Port GPIOA
#define HD44780_D6_Pin GPIO_PIN_7
#define HD44780_D6_GPIO_Port GPIOA
#define HD44780_D7_Pin GPIO_PIN_0
#define HD44780_D7_GPIO_Port GPIOB
#define KEYPAD_ROW_4_Pin GPIO_PIN_12
#define KEYPAD_ROW_4_GPIO_Port GPIOB
#define KEYPAD_ROW_3_Pin GPIO_PIN_13
#define KEYPAD_ROW_3_GPIO_Port GPIOB
#define KEYPAD_ROW_2_Pin GPIO_PIN_14
#define KEYPAD_ROW_2_GPIO_Port GPIOB
#define ENC_SW_Pin GPIO_PIN_15
#define ENC_SW_GPIO_Port GPIOB
#define KEYPAD_ROW_1_Pin GPIO_PIN_10
#define KEYPAD_ROW_1_GPIO_Port GPIOA
#define PWM_Pin GPIO_PIN_15
#define PWM_GPIO_Port GPIOA
#define KEYPAD_COLUMN_1_Pin GPIO_PIN_4
#define KEYPAD_COLUMN_1_GPIO_Port GPIOB
#define KEYPAD_COLUMN_2_Pin GPIO_PIN_5
#define KEYPAD_COLUMN_2_GPIO_Port GPIOB
#define KEYPAD_COLUMN_3_Pin GPIO_PIN_6
#define KEYPAD_COLUMN_3_GPIO_Port GPIOB
#define KEYPAD_COLUMN_4_Pin GPIO_PIN_7
#define KEYPAD_COLUMN_4_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */
typedef enum{FALSE,TRUE} BOOL;
struct Settings {
	uint8_t family_left;
	uint8_t instrument_left;
	uint8_t family_right;
	uint8_t instrument_right;
};
/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
