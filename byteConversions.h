#ifndef BYTECONVERSIONS_H
#define BYTECONVERSIONS_H
#include <stdint.h>

typedef uint8_t Byte;

Byte *hex_to_bytes(const char *hexString);
Byte *b64_to_bytes(const char *b64String);
char *bytes_to_hex(const Byte *byteString);
char *bytes_to_b64(const Byte *byteString);

Byte _hex_digit_value(const char hexDigit);
Byte _b64_digit_value(const char b64Digit);
#endif
