/*
 * usb.h
 *
 *  Created on: Jan 29, 2021
 *      Author: nov11
 */
#include "data/usb_data.h"


#ifndef INC_PERIPHERAL_USB_H_
#define INC_PERIPHERAL_USB_H_

void usb_write(uint8_t b);
void usb_tx();

// Create structure from USB buffer
struct UsbDataObj usb_create_struct(uint8_t* buffer, uint16_t len);

// Check if has data to process
uint8_t has_data();

// Get data to process
void increase_counter();
uint8_t write_usb_data(uint8_t* buffer, uint16_t len);

uint32_t get_data_size();
uint8_t* get_data_buffer();

#endif /* INC_PERIPHERAL_USB_H_ */
