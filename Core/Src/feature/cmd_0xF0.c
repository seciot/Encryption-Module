/*
 * cmd_0xF0.c
 *
 *  Created on: Jan 29, 2021
 *      Author: nov11
 */
#include "feature/cmd_0xF0.h"
#include "main.h"
#include "peripheral/usb.h"
#include "feature/common.h"
#include "feature/cmd_0xF0.h"

void OnCommand0xF0(uint8_t recv)
{
	for(uint8_t byte = 0; byte < 32; byte++)
	{
		usb_write(isSupported(byte));
	}
	usb_tx();
	currentCommand = 0x0;
}


// Grabs supported byte
uint8_t isSupported(uint8_t offset)
{
	if(offset == 0)
	{
		return 0b10001111;
	}
	else if(offset <= 9)
	{
		return 0x0;
	}
	else if(offset == 10)
	{
		return 0b11000000;
	}
	else if(offset < 30)
	{
		return 0x0;
	}
	else if(offset == 30)
	{
		return 0b11100000;
	}
	else
	{
		return 0x0;
	}
}
