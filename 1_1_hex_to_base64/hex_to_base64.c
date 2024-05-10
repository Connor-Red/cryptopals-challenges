#include <stdio.h>
#include "../utils/converters.h"

/* I think it would be easier to convert the hex string to a binary string, then convert
*  the binary string to a base 64 string. Bitwise operations are a pain in C.
*/

int main(){
    char *hex_string = "49276d206b696c6c696e6720796f75722\
0627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d";
    char *expected_string = "SSdtIGtpbGxpbmcgeW91ciBicmFpbiBs\
aWtlIGEgcG9pc29ub3VzIG11c2hyb29t";
    printf("Input: %s\n", hex_string);
    printf("Expected: %s\n", expected_string);
    char *actual_string = hex_to_64(hex_string);
    printf("Actual output: %s\n", actual_string);
    if(strcmp(expected_string, actual_string) == 0){
        puts("Output matches");
    }else{
        puts("Output does not match");
    }
    return 0;
}