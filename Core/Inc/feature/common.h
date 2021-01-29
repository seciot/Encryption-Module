/*
 * common.h
 *
 *  Created on: Jan 29, 2021
 *      Author: nov11
 */
#include "main.h"
#include "commands.h"

#ifndef INC_FEATURE_COMMON_H_
#define INC_FEATURE_COMMON_H_

extern uint8_t currentCommand;

// Password, max 256 bytes
extern uint8_t Password[256];

// Password length, max 256
extern uint8_t PasswordLength;

#endif /* INC_FEATURE_COMMON_H_ */
