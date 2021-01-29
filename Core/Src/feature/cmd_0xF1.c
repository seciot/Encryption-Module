/*
 * cmd_0xF0.c
 *
 *  Created on: Jan 29, 2021
 *      Author: nov11
 */

#include "feature/cmd_0xF1.h"
#include "main.h"
#include "config.h"
#include "config_ids.h"
#include "feature/common.h"
#include "peripheral/usb.h"

int8_t cfgIndex = -1;

// CFG_GetStreamChunkSize
void GetStreamChunkSize(uint8_t recv)
{
	usb_write((uint8_t)(STREAM_CHUNK_SIZE >> 8));
	usb_write((uint8_t)(STREAM_CHUNK_SIZE & 255));
	usb_tx();
	currentCommand = 0x0;
	cfgIndex = -1;
}

void OnCommand0xF1(uint8_t recv)
{
	if(cfgIndex < 0)
		cfgIndex = recv;
	else
	{
		// Index [0] - STREAM_CHUNK_SIZE
		if(cfgIndex == CFG_STREAM_CHUNK_SIZE)
		{
			GetStreamChunkSize(recv);
		}
	}
}

