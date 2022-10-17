#include <stdio.h>
#include "bytes.h"
#include "singleXOR.h"
// single byte xor cipher challenge

int main(){
    const char *encrypted = "1b37373331363f78151b7f2b783431333d78397828372d363c78373e783a393b3736";
    printf("encrypted: %s\n", encrypted);
    Byte *potBytes = single_byte_xor_bytes(hex_to_bytes(encrypted));
    printf("attempt: ");
    for (Byte i = 1; i <= potBytes[0]; i++){
        printf("%c", potBytes[i]);
    }
    printf("\n");
    return 0;
}
