/*
 * cmd_0xF0.h
 *
 *  Created on: Jan 29, 2021
 *      Author: nov11
 */

#include "main.h"

#ifndef INC_FEATURE_CMD_0XF0_H_
#define INC_FEATURE_CMD_0XF0_H_

uint8_t isSupported(uint8_t offset);
void OnCommand0xF0(uint8_t recv);

#endif /* INC_FEATURE_CMD_0XF0_H_ */
