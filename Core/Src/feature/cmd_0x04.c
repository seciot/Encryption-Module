/*
 * cmd_0x04.c
 *
 *  Created on: Jan 29, 2021
 *      Author: nov11
 */
#include "feature/common.h"
#include "main.h"


// Iterator for running around password
uint8_t iterator = 0;

// Defines if length of password is set
uint8_t isLengthSet = 0;

void OnCommand0x04(uint8_t recv){
	// Set information about password length
	        if (isLengthSet == 0) {
	            PasswordLength = recv;
	            iterator = 0;
	            isLengthSet = 1;
	        }
	        // Load password bytes
	        else {
	            Password[iterator] = recv;
	            iterator++;
	            if (iterator >= PasswordLength) {
	                currentCommand = 0x0;
	                isLengthSet = 0;
	            }
	        }
}
