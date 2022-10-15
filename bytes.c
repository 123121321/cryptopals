#include <stdlib.h>
#include <stdint.h>
#include "CRYPTOPALS_1.h"
#include "bytes.h"

// TODO deal with cases where num of bytes/hex/b64/whatever arent
// multiples of each other;
// finish other functions and rename this file/make

Byte *hex_to_bytes(const char *hexString){
    Byte *bytes = NULL;
    uint16_t digits = 0, i = 0;
    Byte value = 0;
    while (hexString[i] != '\0'){
        digits++;
        i++;
    }
    if (digits % 2 == 0){
        digits = digits/2;
        bytes = malloc(digits + 1);
        for (i = 0; i < digits; i++){
            value = 0;
            value += _hex_digit_value(hexString[2*i]) << 4;
            value += _hex_digit_value(hexString[2*i + 1]);
            bytes[i + 1] = value;
        }
    } else {
        digits++;
        digits = digits/2;
        bytes = malloc(digits + 1);
        bytes[1] = _hex_digit_value(hexString[0]);
        for (i = 1; i < digits; i++){
            value = 0;
            value += _hex_digit_value(hexString[2*i - 1]) << 4;
            value += _hex_digit_value(hexString[2*i]);
            bytes[i + 1] = value;
        }
    }
    bytes[0] = digits;
    return bytes;
}

Byte *b64_to_bytes(const char *b64String){
    Byte *bytes = NULL;
    return bytes;
}

char *bytes_to_hex(const Byte *bytes){
    char *hexString = NULL;
    uint16_t digits = bytes[0], i = 0;
    Byte value = 0;
    // 1 byte = 2 hex digits, much simpler than bytes to b64
    hexString = malloc(digits*2 + 1);
    for (i = 0; i < digits; i++){
        value = bytes[i + 1] >> 4;
        hexString[2*i] = hexChars[value];
        value = bytes[i + 1] << 4;
        value = value >> 4;
        hexString[2*i + 1] = hexChars[value];
    }
    hexString[digits*2] = 0;
    return hexString;
}

char *bytes_to_b64(const Byte *bytes){
    char *b64String = NULL;
    uint16_t digits = bytes[0], i = 0, blocs = 0;
    Byte value = 0, slice = 0;
    // 3 bytes to 4 b64 digits
    // bytes[] |   0   | |   1   | |   2   |, digits = 3
    // 0b      1011 1000 1111 0100 0000 1111
    // b64[]   |  0  ||  1  | |  2  ||  3  |, digits = 4 = (3 * 4)/3
    // bloc    |             0             |, digits = 1 = 3/3
    blocs = digits/3;
    b64String = malloc(blocs*4 + 1);
    // iterate through 3 bytes/4 digits/1 "bloc" each round
    // to maintain alignment
    for (i = 0; i < blocs; i++){
        // digit 0 
        slice = bytes[3*i + 1];
        value = slice >> 2;
        b64String[4*i] = b64Chars[value];
        // digit 1 
        value = slice << 6;
        value = value >> 2; 
        // shift slice after discarding leftmost bits
        // and adjusting value for sextet
        slice = bytes[3*i + 2];
        // discard rightmost bits
        value = value + (slice >> 4);
        b64String[4*i + 1] = b64Chars[value];
        // digit 2
        value = slice << 4;
        value = value >> 2;
        // shift slice after discarding leftmost bits, again
        slice = bytes[3*i + 3]; 
        // discard rightmost bits, again
        value = value + (slice >> 6);
        b64String[4*i + 2] = b64Chars[value];
        // digit 3, simply discard leftmost bits;
        value = slice << 2;
        value = value >> 2;
        b64String[4*i + 3] = b64Chars[value];
    }
    b64String[blocs*4] = 0;
    return b64String;
}

/* by standard ascii encoding, '0', '1', . . ., '9' lie in
 the interval [48, 57]. similarly, 'a', . . ., 'f' are in [97, 102].
 Thus, we can easily find the decimal value of a hex digit from
 its ascii value using interval testing. */
Byte _hex_digit_value(const char hexDigit){
    Byte value = (Byte)hexDigit;
    if (57 >= value  && value >= 48){
        return value - 48;
    } else {
        return value - 97 + 10;
    }
}

/* using the same interval technique as above, b64 digits are
 comprised of: A-Z; a-z; 0-9; +; and /.
 These are composed of the respective intervals/values:
 [65, 90]; [97, 122]; [48-57]; 43; and 47. */
Byte _b64_digit_value(const char b64Digit){
    Byte value = (Byte)b64Digit;
    if (90 >= value && value >= 65){
        return value - 65;
    } else if (122 >= value && value >= 97){
        return value - 97 + 26;
    } else if (57 >= value && value >= 48){
        return value - 48 + 52;
    } else if (value == 43){
        return 62;
    } else {
        return 63;
    }
}
