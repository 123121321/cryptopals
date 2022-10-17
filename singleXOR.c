#include <stdlib.h>
#include "bytes.h"
#include "singleXOR.h"

// this function isnt really needed for the problem in hindsight
// but ill leave it just to save mea minute or 2 of typing
// if its needed later

char *single_byte_xor_hex(const char *hexString){
    char *potText = NULL;
    Byte *work = hex_to_bytes(hexString);
    potText = bytes_to_hex(single_byte_xor_bytes(work));
    return potText;
}

Byte *single_byte_xor_bytes(const Byte *bytes){
    Byte potKey = 0, tempKey = 0, xor = 0, dig = bytes[0]; 
    Byte *potBytes = malloc(dig + 1);
    potBytes[0] = dig;
    uint32_t textScore = 0, tempScore = 0;
    for (uint16_t i = 0; i < 256 ; i++){
        tempKey = i;
        tempScore = 0;
        for (Byte j = 1; j <= dig; j++){
            xor = tempKey ^ bytes[j];
            if (90 >= xor && xor >= 65){
                for (Byte k = 0; k <= 25; k++){
                    if ( xor + 32 == engFreqChars[k]){
                        tempScore += engFreqNums[k];
                    }
                }
            } else if (122 >= xor && xor >= 97){
                for (Byte k = 0; k <= 25; k++){
                    if (xor == engFreqChars[k]){
                        tempScore += engFreqNums[k];
                    }
                }
            } else if (xor == 32){
                tempScore += 150;
            }
        }
        if (tempScore > textScore){
            potKey = tempKey;
            textScore = tempScore;
        }
    }
    for (Byte j = 1; j <= dig; j++){
        potBytes[j] = bytes[j] ^ potKey;
    }
    return potBytes;
}
