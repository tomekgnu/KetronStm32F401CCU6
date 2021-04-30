/*
 * input.c
 *
 *  Created on: Apr 25, 2021
 *      Author: Tomek
 */

#include "main.h"
#include "stm32f4xx_hal_adc.h"
#include "input.h"
#include "string.h"
#include "tm_stm32f4_keypad.h"

struct Joystick joyold;
struct Encoder encold;

static void ADC_SetActiveChannel(ADC_HandleTypeDef *hadc, uint32_t AdcChannel);

void initControls(struct Joystick *joycur,struct Encoder *enccur){

	extern ADC_HandleTypeDef hadc1;

	joycur->x = joyold.x = 0;
	joycur->y = joyold.y = 0;
	joycur->button = joyold.button = 0;
	enccur->position = encold.position = 0;
	enccur->button = encold.button = FALSE;
	ADC_SetActiveChannel(&hadc1, ADC_CHANNEL_0);
}

BOOL joystickPressed(struct Joystick *joy){

	extern ADC_HandleTypeDef hadc1;

	if (HAL_ADC_PollForConversion(&hadc1, 10) == HAL_OK) {
		joy->x = HAL_ADC_GetValue(&hadc1) >> 1;
		ADC_SetActiveChannel(&hadc1, ADC_CHANNEL_1);
		HAL_ADC_Start(&hadc1);
	}
	if (HAL_ADC_PollForConversion(&hadc1, 10) == HAL_OK) {
		joy->y = HAL_ADC_GetValue(&hadc1) >> 1;
		ADC_SetActiveChannel(&hadc1, ADC_CHANNEL_0);
		HAL_ADC_Start(&hadc1);
	}
	if(HAL_GPIO_ReadPin(JOY_SW_GPIO_Port, JOY_SW_Pin) == GPIO_PIN_RESET)
		joy->button = TRUE;
	else
		joy->button = FALSE;

	if(joy->button != joyold.button){
		joyold.button = joy->button;
		return joy->button;
	}

	return FALSE;
}

BOOL encoderChanged(struct Encoder *enc){

	extern TIM_HandleTypeDef htim1;
	uint16_t pulse_count = htim1.Instance->CNT;
	enc->position = pulse_count / 4;
	if(HAL_GPIO_ReadPin(ENC_SW_GPIO_Port, ENC_SW_Pin) == GPIO_PIN_RESET)
		enc->button = TRUE;
	else
		enc->button = FALSE;

	if(enc->position != encold.position && enc->position != 128){
		encold.position = enc->position;
		return TRUE;
	}
	if(enc->button != encold.button){
		encold.button = enc->button;
		return encold.button;
	}

	return FALSE;
}

static void ADC_SetActiveChannel(ADC_HandleTypeDef *hadc, uint32_t AdcChannel) {
	ADC_ChannelConfTypeDef sConfig = { 0 };
	sConfig.Channel = AdcChannel;
	sConfig.Rank = 1;
	sConfig.SamplingTime = ADC_SAMPLETIME_3CYCLES;
	if (HAL_ADC_ConfigChannel(hadc, &sConfig) != HAL_OK) {
		Error_Handler();
	}
}
