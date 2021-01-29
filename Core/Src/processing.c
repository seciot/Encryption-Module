/*
 * vmpc_proc.c
 *
 *  Created on: Jan 4, 2021
 *      Author: Patryk Pastuszka
 */
#include "main.h"
#include "feature/common.h"
#include "feature/cmd_0x00.h"
#include "feature/cmd_0x04.h"
#include "feature/cmd_0x05.h"
#include "feature/cmd_0x06.h"
#include "feature/cmd_0x07.h"
#include "feature/cmd_0x50.h"
#include "feature/cmd_0x51.h"
#include "feature/cmd_0xF0.h"
#include "feature/cmd_0xF1.h"
#include "feature/cmd_0xF2.h"

void OnPacketReceived(uint8_t recv)
{
	if (currentCommand == CMD_DOE_NOT)
		OnCommand0x00(recv);
	else if (currentCommand == CMD_SET_PWD)
		OnCommand0x04(recv);
	else if (currentCommand == CMD_INI_ALG)
		OnCommand0x05(recv);
	else if (currentCommand == CMD_ENC_STR)
		OnCommand0x06(recv);
	else if (currentCommand == CMD_ENC_SEQ)
		OnCommand0x07(recv);
	else if (currentCommand == CMD_DMP_DAT)
		OnCommand0x50(recv);
	else if (currentCommand == CMD_LOA_DAT)
		OnCommand0x51(recv);
	else if (currentCommand == CMD_ISF_SUP)
		OnCommand0xF0(recv);
	else if(currentCommand == CMD_CFG_GET)
		OnCommand0xF1(recv);
	else if(currentCommand == CMD_CFG_SET)
		OnCommand0xF2(recv);
}

