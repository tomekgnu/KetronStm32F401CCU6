/*
 * input.h
 *
 *  Created on: Apr 25, 2021
 *      Author: Tomek
 */

#ifndef INC_INPUT_H_
#define INC_INPUT_H_

#include "main.h"
#include "tm_stm32f4_keypad.h"

struct Joystick {
	uint16_t x;
	uint16_t y;
	BOOL button;
};

struct Encoder {
	uint8_t position;
	BOOL button;
};

void initControls(struct Joystick *joycur,struct Encoder *enccur);

BOOL joystickPressed(struct Joystick *joy);
BOOL encoderChanged(struct Encoder *);

#endif /* INC_INPUT_H_ */
