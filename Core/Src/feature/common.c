/*
 * common.c
 *
 *  Created on: Jan 29, 2021
 *      Author: nov11
 */
#include "main.h"

uint8_t currentCommand = 0x0;

// Password, max 256 bytes
uint8_t Password[256];

// Password length, max 256
uint8_t PasswordLength = 0;
