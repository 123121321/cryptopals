#ifndef FIXEDXOR_H
#define FIXEDXOR_H
#include <stdint.h>

typedef uint8_t Byte;

char *fixed_xor_hex(const char *hex1, const char *hex2);
Byte *fixed_xor_bytes(const Byte *bytes1, const Byte *bytes2);

#endif
