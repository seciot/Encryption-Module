/*
 * cmd_0x00.c
 *
 *  Created on: Jan 29, 2021
 *      Author: nov11
 */
#include "main.h"
#include "feature/common.h"

void OnCommand0x00(uint8_t recv)
{
	if (recv == CMD_DOE_NOT || recv == CMD_SET_PWD || recv == CMD_INI_ALG || recv == CMD_ENC_SEQ
	        		|| recv == CMD_LOA_DAT || recv == CMD_DMP_DAT || recv == CMD_ENC_STR || recv == CMD_ISF_SUP
					|| recv == CMD_CFG_GET || recv == CMD_CFG_SET) {
	            currentCommand = recv;
	}
}
