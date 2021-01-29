/*
 * cmd_0x51.c
 *
 *  Created on: Jan 29, 2021
 *      Author: nov11
 */
#include "main.h"
#include "crypto/vmpc.h"
#include "feature/common.h"

// Dumped data loading iterator
uint16_t loadIterator;

void OnCommand0x51(uint8_t recv)
{
	if (loadIterator < 256) {
		P[loadIterator] = recv;
		loadIterator++;
	} else if (loadIterator == 256) {
		s = recv;
		loadIterator++;
	} else if (loadIterator == 257) {
		n = recv;
		loadIterator = 0;
		currentCommand = 0x0;
	}
}
