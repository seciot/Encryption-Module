#include "main.h"

// VMPC variables
uint8_t Key[256], Vec[64];
uint8_t P[256];
uint8_t s, n;

// VMPC Initialization Vector, can be changed
unsigned char InitVector[64] = {
0xf5, 0xb8, 0xe0, 0x36, 0x42, 0x20, 0x1a, 0xc9, 0x2d, 0x8d, 0xee, 0xd0, 0x4c, 0x5c, 0xfe, 0xb1,
0x19, 0xee, 0x2e, 0x01, 0xd3, 0x31, 0xcd, 0x7e, 0x14, 0xdb, 0x37, 0x71, 0xe9, 0xf2, 0x58, 0x94,
0xc5, 0x9e, 0xac, 0xed, 0x6e, 0xf9, 0x1b, 0x3d, 0x28, 0x8f, 0x31, 0x0c, 0xd2, 0x6a, 0x85, 0xaf,
0xe2, 0x12, 0xb5, 0x0a, 0xef, 0x68, 0x0d, 0xa9, 0x3a, 0xf7, 0xb9, 0x2a, 0xa0, 0x81, 0x77, 0xd8}; // Hardcoded

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
