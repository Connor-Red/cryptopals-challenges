#include "../utils/converters.h"
#include "../utils/useful_func.h"
/**
 *  XOR will be done using binary strings
*/

int main(){
    char *input_string = "1c0111001f010100061a024b53535009181c";
    char *xor_string = "686974207468652062756c6c277320657965";
    char *expected_string = "746865206b696420646f6e277420706c6179";
    char *bin_input = hex_to_binary(input_string);
    char *bin_xor_str = hex_to_binary(xor_string);
    char *actual_bin = bin_xor(bin_input, bin_xor_str);
    char *actual_string = binary_to_hex(actual_bin);
    printf("Actual output: %s\n", actual_string);
    if(strcmp(expected_string, actual_string) == 0){
        puts("Output matches");
    }else{
        puts("Output does not match");
    }
    return 0;
}