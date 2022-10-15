#include <stdlib.h>
#include "bytes.h"
#include "fixedXOR.h"

// we can assume by fixed that these are fixed length
// strings of equal length
char *fixed_xor_hex(const char *hex1, const char *hex2){
    Byte *bytes1 = hex_to_bytes(hex1);
    Byte *bytes2 = hex_to_bytes(hex2);
    Byte *xord = fixed_xor_bytes(bytes1, bytes2);
    return bytes_to_hex(xord);
}

Byte *fixed_xor_bytes(const Byte *bytes1, const Byte *bytes2){
    Byte *xord=NULL;
    Byte digits = bytes1[0], i = 0;
    xord = malloc(digits+1);
    xord[0] = digits;
    for (i = 1; i <= digits; i++){
        xord[i] = bytes1[i] ^ bytes2[i];
    }
    return xord;
}
