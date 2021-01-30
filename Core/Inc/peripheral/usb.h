/*
 * usb.h
 *
 *  Created on: Jan 29, 2021
 *      Author: nov11
 */
#include "main.h"

#ifndef INC_PERIPHERAL_USB_H_
#define INC_PERIPHERAL_USB_H_

void usb_write(uint8_t b);
void usb_tx();

extern uint8_t* newBuffer;

// Check if has data to process
uint8_t has_data();

// Get data to process
void increase_counter();
uint8_t write_usb_data(uint8_t* buffer, uint32_t length);

uint8_t get_data();

#endif /* INC_PERIPHERAL_USB_H_ */
