/*
 * cmd_0x05.c
 *
 *  Created on: Jan 29, 2021
 *      Author: nov11
 */
#include "feature/cmd_0x05.h"
#include "config.h"
#include "main.h"
#include "crypto/vmpc.h"
#include "feature/common.h"

void OnCommand0x05(uint8_t recv){
	 ResetVMPC();
	 VMPCInitKey(Password, InitVector, PasswordLength, IV_LENGTH);
	 currentCommand = 0x0;
}
