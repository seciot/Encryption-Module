#include "main.h"

// VMPC variables
uint8_t P[256];
uint8_t s, n;

// Reset VMPC permutation table
void ResetP(){
  for(int x = 0; x < 256; x++){
    P[x] = x;
  }
}

// Reset VMPC
void ResetVMPC()
{
  s = 0;
  n = 0;
  ResetP();
}

// Initialize VMPC Key (internal method)
void VMPCInitKeyRound(uint8_t Data[], uint8_t Len)
{
	uint8_t k=0;
  n=0;
  for (int x=0; x<768; x++)
  {
    s=P[ (s + P[n] + Data[k]) & 255];
    uint8_t t=P[n];  P[n]=P[s];  P[s]=t;
    k++;  if (k==Len) k=0;
    n++;
  }
}

// VMPC init key
void VMPCInitKey(uint8_t Key[], uint8_t Vec[], uint8_t KeyLen, uint8_t VecLen)   //KeyLen, VecLen = 1,2,3,...,64
{
  VMPCInitKeyRound(Key, KeyLen);
  VMPCInitKeyRound(Vec, VecLen);
  VMPCInitKeyRound(Key, KeyLen);
}

// VMPC Encrypt data
uint8_t VMPCEncrypt(uint8_t data)
{
    s=P[(s + P[n]) & 255];
    data ^= P[(P[P[ s ]] + 1) & 255];
    uint8_t t = P[n];  P[n]=P[s];  P[s]=t;
    n++;
    return data;
}
