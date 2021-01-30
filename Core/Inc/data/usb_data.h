/*
 * usb_data.h
 *
 *  Created on: Jan 29, 2021
 *      Author: nov11
 */

#include "main.h"

#ifndef INC_DATA_USB_DATA_H_
#define INC_DATA_USB_DATA_H_

struct UsbDataObj {
	uint32_t length;
	uint8_t* buffer;
};

#endif /* INC_DATA_USB_DATA_H_ */
