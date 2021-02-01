/*
 * commands.h
 *
 *  Created on: Jan 29, 2021
 *      Author: nov11
 */

#ifndef INC_FEATURE_COMMANDS_H_
#define INC_FEATURE_COMMANDS_H_


// Command Do Nothing
#define CMD_DOE_NOT 0x0

// Command Set Password
#define CMD_SET_PWD 0x4

// Command Initialize Algorithm
#define CMD_INI_ALG 0x5

// Command Encrypt Stream
#define CMD_ENC_STR 0x6

// Command Encrypt Sequence
#define CMD_ENC_SEQ 0x7

// Command Dump CRC
#define CMD_DMP_CRC 0x10

// Command Dump Data
#define CMD_DMP_DAT 0x50

// Command Load Data
#define CMD_LOA_DAT 0x51

// Command check supported features
#define CMD_ISF_SUP 0xF0

// Command configuration get value
#define CMD_CFG_GET 0xF1

// Command configuration set value
#define CMD_CFG_SET 0xF2

#endif /* INC_FEATURE_COMMANDS_H_ */
