/*
 * cmd_0x10.c
 *
 *  Created on: Feb 1, 2021
 *      Author: nov11
 */
#include "main.h"
#include "feature/cmd_0x10.h"
#include "feature/commands.h"
#include "feature/common.h"
#include "crypto/vmpc.h"
#include "peripheral/usb.h"

void OnCommand0x10(uint8_t recv)
{
	usb_write((0xFF000000 & crc1) >> 24);
	usb_write((0x00FF0000 & crc1) >> 16);
	usb_write((0x0000FF00 & crc1) >> 8);
	usb_write((0x000000FF & crc1) >> 0);
	usb_write((0xFF000000 & crc2) >> 24);
	usb_write((0x00FF0000 & crc2) >> 16);
	usb_write((0x0000FF00 & crc2) >> 8);
	usb_write((0x000000FF & crc2) >> 0);
	usb_tx();
	currentCommand = 0x0;
}
