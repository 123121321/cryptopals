#ifndef SINGLEXOR_H
#define SINGLEXOR_H
#include <stdint.h>

typedef uint8_t Byte;
// if these dont work, rate spaces (32) as having higher score than 
// e, and digits/punctuation marks as something in between 't' and 'a'
static const char engFreqChars[] = {'e', 't', 'a', 'o', 'i', 'n',
                                    's', 'h', 'r', 'd', 'l', 'c',
                                    'u', 'm', 'w', 'f', 'g', 'y',
                                    'p', 'b', 'v', 'k', 'j', 'x',
                                    'q', 'z'};

static const Byte engFreqNums[]  = { 130, 91, 82, 75, 70, 67,
                                      63, 61, 60, 43, 40, 28,
                                      28, 24, 24, 24, 22, 20,
                                      19, 15, 10,  8,  2,  2,
                                       1, 1};

char *single_byte_xor_hex(const char *hexString);
Byte *single_byte_xor_bytes(const Byte *bytes);
#endif
