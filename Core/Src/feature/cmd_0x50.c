/*
 * cmd_0x50.c
 *
 *  Created on: Jan 29, 2021
 *      Author: nov11
 */
#include "main.h"
#include "crypto/vmpc.h"
#include "feature/common.h"
#include "peripheral/usb.h"


void OnCommand0x50(uint8_t recv)
{
	// Dump encryption data, P, s, n
	for (uint16_t q = 0; q < 256; q++)
		usb_write(P[q]);
	usb_write(s);
	usb_write(n);
	usb_tx();
	currentCommand = 0x0;
}
