#include <stdio.h>
#include "bytes.h"

int main(){
    const char *hexString = "49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d";
    const char *b64String = "SSdtIGtpbGxpbmcgeW91ciBicmFpbiBsaWtlIGEgcG9pc29ub3VzIG11c2hyb29t";
    Byte *byteString = hex_to_bytes(hexString);
    char *attemptString = bytes_to_b64(byteString);
    printf("the hex string:\n%s\n", hexString);
    printf("should produce the base64 string:\n%s\n", b64String);
    printf("attempt:\n%s\n", attemptString);
    return 0;
}
