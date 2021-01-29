/*
 * usb.c
 *
 *  Created on: Jan 29, 2021
 *      Author: nov11
 */

#include "main.h"
#include "usbd_cdc_if.h"

// USB TX Buffer
uint8_t buffer[16384];

// Current length of data in buffer
uint16_t len = 0;

// Writes data to USB buffer
void usb_write(uint8_t b){
	*(buffer + len) = b;
	len++;
}

// Sends USB buffer onto CDC port
void usb_tx(){
	if(len > 0){
		CDC_Transmit_FS(buffer, len);
		len = 0;
	}
}
