#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* I think it would be easier to convert the hex string to a binary string, then convert
*  the binary string to a base 64 string. Bitwise operations are a pain in C.
*/

//Base 64 table in order
#define BASE_64_TABLE "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"

// really ugly function to convert hex to binary
char* hex_to_binary(char hexDigit) {
    switch(hexDigit) {
        case '0': return "0000";
        case '1': return "0001";
        case '2': return "0010";
        case '3': return "0011";
        case '4': return "0100";
        case '5': return "0101";
        case '6': return "0110";
        case '7': return "0111";
        case '8': return "1000";
        case '9': return "1001";
        case 'A': return "1010";
        case 'B': return "1011";
        case 'C': return "1100";
        case 'D': return "1101";
        case 'E': return "1110";
        case 'F': return "1111";
        case 'a': return "1010";
        case 'b': return "1011";
        case 'c': return "1100";
        case 'd': return "1101";
        case 'e': return "1110";
        case 'f': return "1111";
        default: return NULL;
    }
}

char *hex_to_64(char *hex_str){
    int binary_length = 4 * strlen(hex_str);
    char *binary_string = malloc(sizeof(char) * binary_length + 1);
    int calculated_length = (binary_length / 6);
    if(calculated_length % 6 != 0){
        calculated_length++;
    }
    char *calculated_string = malloc(sizeof(char) * calculated_length);
    // First convert the hex string to a binary string
    for(int i = 0; hex_str[i] != '\0'; i++){
        char *binary_char = hex_to_binary(hex_str[i]);
        strncat(binary_string, binary_char, 4);
    }
    binary_string[binary_length + 1] = '\0';
    int j = 0;
    // Then convert binary string to an int
    while(binary_length > 5){
        char *endptr;
        char selected[7];
        for(int i = 0; i < 6; i++){
            selected[i] = binary_string[(j * 6) + i];
        }
        int binary_num = strtol(selected, &endptr, 2);
        // Look up the int value of the base 64 character
        calculated_string[j] = BASE_64_TABLE[binary_num];
        calculated_string[j + 1] = '\0';
        j++;
        binary_length -= 6;
    }
    // If there is leftovers, fill it with zeroes
    if(binary_length > 0){
        char selected[7];
        char *endptr;
        for(int i = 0; i < binary_length; i++){
            selected[i] = binary_string[(j * 6) + i];
        }
        for(int i = binary_length; i < 6; i++){
            selected[i] = '0';
        }
        int binary_num = strtol(selected, &endptr, 2);
        calculated_string[j] = BASE_64_TABLE[binary_num];
        calculated_string[j + 1] = '\0';
    }
    return(calculated_string);
}

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