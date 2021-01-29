/*
 * usb.c
 *
 *  Created on: Jan 29, 2021
 *      Author: nov11
 */

#include "main.h"
#include "usbd_cdc_if.h"
#include "data/usb_data.h"

#define USB_QUEUE_SIZE 32

// USB Data Queue
struct UsbDataObj queue[USB_QUEUE_SIZE];
uint8_t usbQueueIterator = 0;
uint8_t last_data = USB_QUEUE_SIZE - 1;


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

struct UsbDataObj usb_create_struct(uint8_t* buffer, uint32_t len)
{
	struct UsbDataObj data;
	data.buffer = buffer;
	data.length = len;
	return data;
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
	if(last_data > USB_QUEUE_SIZE - 1)
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

uint8_t write_usb_data(uint8_t* buffer, uint32_t len)
{

	// No space
	if(get_space() <= 0)
		return 0;

	queue[usbQueueIterator++] = usb_create_struct(buffer, len);

	// Free old buffer memory - do it after it is processed
	//free(buffer);

	return 1;
}


