/*
 * config.h
 *
 *  Created on: 22 Jan 2021
 *      Author: h1m4w4r1
 */

#ifndef INC_CONFIG_H_
#define INC_CONFIG_H_

#define IV_LENGTH 64


// VMPC Initialization Vector, can be changed, go to config.c
extern unsigned char InitVector[IV_LENGTH];

// Size of stream chunk. Will return data after this value is reached. Equal to amount of bytes returned.
// MAX (recommended): 32767.
// Can be changed inside config.c
const uint16_t STREAM_CHUNK_SIZE;


#endif /* INC_CONFIG_H_ */
