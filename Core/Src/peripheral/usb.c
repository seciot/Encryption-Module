/*
 * usb.c
 *
 *  Created on: Jan 29, 2021
 *      Author: nov11
 */

#include "main.h"
#include "usbd_cdc_if.h"


#define RX_BUFFER_SIZE (16384 + 128)


// USB Data Queue
uint8_t rxBuffer[RX_BUFFER_SIZE];

uint32_t usbQueueIterator = 0;
uint32_t last_data = RX_BUFFER_SIZE - 1;

// USB TX Buffer
uint8_t txBuffer[64];

// Current length of data in buffer
uint16_t len = 0;

// Sends USB buffer onto CDC port
void usb_tx(){
	if(len > 0){
		CDC_Transmit_FS(txBuffer, len);
		len = 0;
	}
}


// Writes data to USB buffer
void usb_write(uint8_t b){
	*(txBuffer + len) = b;
	len++;
	if(len == 64)
		usb_tx();
}

uint8_t has_data()
{
	return usbQueueIterator != last_data;
}

uint8_t get_data()
{
	return rxBuffer[last_data];
}

void increase_counter()
{
	// Increase iterator
	last_data++;

	// If over iteration, then return to beginning of array
	if(last_data >= RX_BUFFER_SIZE)
		last_data = 0;
}

uint8_t write_usb_data(uint8_t* buffer, uint32_t length)
{
	for(uint32_t i = 0; i < length; i++)
	{
		rxBuffer[usbQueueIterator] = buffer[i];
		usbQueueIterator++;
		if(usbQueueIterator >= RX_BUFFER_SIZE)
			usbQueueIterator = 0;
	}

	return 1;
}


