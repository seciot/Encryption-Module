/*
 * cmd_0x07.c
 *
 *  Created on: Jan 29, 2021
 *      Author: nov11
 */
#include "main.h"
#include "crypto/vmpc.h"
#include "feature/common.h"
#include "peripheral/usb.h"

// Length of chunk, max 16384
uint16_t ChunkLength;

// Iterator running around chunk
uint16_t chunkIterator = 0;

// Defines if chunk length is set
uint8_t isChunkLenSet = 0;


void OnCommand0x07(uint8_t recv){
	// Loading length, max 2 bytes, MSB first
	if (isChunkLenSet < 2) {
		if (isChunkLenSet > 0) {
			ChunkLength *= 256;
		} else {
			ChunkLength = 0;
		}

		ChunkLength += recv;
		isChunkLenSet++;
		chunkIterator = 0;
	}
	// Sequence data encryption
	else {
		uint8_t enc1 = VMPCEncrypt(recv);
		usb_write(enc1);
		chunkIterator++;
		if (chunkIterator >= ChunkLength) {
			currentCommand = 0x0;
			// Send encrypted data back over USB
			usb_tx();
			isChunkLenSet = 0;
		}
	}
}


