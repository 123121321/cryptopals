#include <stdio.h>
#include "fixedXOR.h"
#include "bytes.h"

int main(){
    const char *str1 = "1c0111001f010100061a024b53535009181c";
    const char *str2 = "686974207468652062756c6c277320657965";
    const char *xord = "746865206b696420646f6e277420706c6179";
    Byte *test = hex_to_bytes(str1);
    char *test2 = bytes_to_hex(test);
    char *attempt = fixed_xor_hex(str1, str2);
    printf("expected xor'd:\n%s\n", xord);
    printf("attempt: \n%s\n", attempt);
    return 0;
}
