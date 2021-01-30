/*
 * cmd_0xF0.c
 *
 *  Created on: Jan 29, 2021
 *      Author: nov11
 */
#include "feature/cmd_0xF2.h"
#include "main.h"
#include "config.h"
#include "config_ids.h"
#include "feature/common.h"
#include "peripheral/usb.h"


int8_t cfgIndex_f2 = -1;

uint16_t cfgIterator = 0;

// CFG_SetStreamChunkSize
void SetStreamChunkSize(uint8_t recv){
	if(cfgIterator == 0)
	{
		STREAM_CHUNK_SIZE = recv;
		STREAM_CHUNK_SIZE *= 256;
		cfgIterator++;
	}
	else{
		STREAM_CHUNK_SIZE += recv;
		currentCommand = 0x0;
		cfgIndex_f2 = -1;
		cfgIterator = 0;
	}
}

void OnCommand0xF2(uint8_t recv)
{
	if(cfgIndex_f2 < 0)
		cfgIndex_f2 = recv;
	else
	{
		if(cfgIndex_f2 == CFG_STREAM_CHUNK_SIZE){
			SetStreamChunkSize(recv);
		}
	}
}

