/*
 * usb.c
 *
 *  Created on: Jan 29, 2021
 *      Author: nov11
 */

#include "main.h"
#include "usbd_cdc_if.h"
#include "data/usb_data.h"

#define USB_QUEUE_SIZE 128

// USB Data Queue
struct UsbDataObj queue[USB_QUEUE_SIZE];
uint8_t usbQueueIterator = 0;
uint8_t last_data = USB_QUEUE_SIZE - 1;

// USB TX Buffer
uint8_t buffer[64];

// Current length of data in buffer
uint16_t len = 0;

void usb_cdc_system_init()
{
	for(uint8_t i = 0; i < USB_QUEUE_SIZE; i++){
		uint8_t* buffer = malloc(sizeof(uint8_t) * APP_RX_DATA_SIZE);
		struct UsbDataObj data;
		data.buffer = buffer;
		data.length = len;
		queue[i] = data;
	}
}

// Sends USB buffer onto CDC port
void usb_tx(){
	if(len > 0){
		CDC_Transmit_FS(buffer, len);
		len = 0;
	}
}


// Writes data to USB buffer
void usb_write(uint8_t b){
	*(buffer + len) = b;
	len++;
	if(len == 64)
		usb_tx();
}



uint8_t has_data()
{
	return usbQueueIterator != last_data;
}

void increase_counter()
{
	// Increase iterator
	last_data++;

	// If over iteration, then return to beginning of array
	if(last_data >= USB_QUEUE_SIZE)
		last_data = 0;
}

uint8_t* get_data_buffer()
{
	return queue[last_data].buffer;
}

uint32_t get_data_size()
{
	return queue[last_data].length;
}

uint8_t get_space()
{
	uint8_t space = 0;
	if(usbQueueIterator > last_data)
	{
		space = usbQueueIterator - last_data;
	}
	else
	{
		space = last_data - usbQueueIterator;
	}
	return USB_QUEUE_SIZE - space;
}

uint8_t has_space()
{
	return get_space() > 0;
}

uint8_t* get_new_buffer()
{
	return queue[(usbQueueIterator + 1) % USB_QUEUE_SIZE].buffer;
}

uint8_t write_usb_data(uint8_t* buffer, uint32_t len)
{

	// No space
	if(get_space() <= 0)
		return 0;

	struct UsbDataObj* obj = &queue[usbQueueIterator];
	obj->buffer = buffer;
	obj->length = len;
	usbQueueIterator++;
	if(usbQueueIterator >= USB_QUEUE_SIZE)
		usbQueueIterator = 0;

	return 1;
}


