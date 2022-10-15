#ifndef BYTES_H
#define BYTES_H
#include <stdint.h>

typedef uint8_t Byte;

// reserve 1 byte at the very beginning of every byte array
// for the num of digits. anything from 0 to (2^8)^(2^8) - 1 digits
// should be more than enough for our purposes

Byte *hex_to_bytes(const char *hexString);
Byte *b64_to_bytes(const char *b64String);
char *bytes_to_hex(const Byte *bytes);
char *bytes_to_b64(const Byte *bytes);

Byte _hex_digit_value(const char hexDigit);
Byte _b64_digit_value(const char b64Digit);
#endif
