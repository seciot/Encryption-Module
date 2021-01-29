/*
 * cmd_0x06.c
 *
 *  Created on: Jan 29, 2021
 *      Author: nov11
 */
#include "main.h"
#include "config.h"
#include "crypto/vmpc.h"
#include "peripheral/usb.h"


uint16_t stream_len = 0x0;


void OnCommand0x06(uint8_t recv)
{
	// Encrypt data and store it in return buffer.
    uint8_t enc1 = VMPCEncrypt(recv);
    usb_write(enc1);
    stream_len++;

    // If reached end of packet then send it and create new packet.
    if(stream_len == STREAM_CHUNK_SIZE){
    	stream_len = 0;
    	usb_tx();
    }
}
