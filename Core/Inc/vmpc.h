/*
 * vmpc.h
 *
 *  Created on: Nov 28, 2020
 *      Author: Patryk Pastuszka
 */

#ifndef INC_VMPC_H_
#define INC_VMPC_H_

extern uint8_t P[256];
extern uint8_t s;
extern uint8_t n;

void ResetP();
void ResetVMPC();
void VMPCInitKeyRound(uint8_t Data[], uint8_t Len);
void VMPCInitKey(uint8_t Key[], uint8_t Vec[], uint8_t KeyLen, uint8_t VecLen) ;
uint8_t VMPCEncrypt(uint8_t data);

#endif /* INC_VMPC_H_ */
