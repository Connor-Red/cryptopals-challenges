#include "../utils/converters.h"
#include "../utils/useful_func.h"
/**
 *  XOR will be done using binary strings
*/

int main(){
    char *input_string = "1c0111001f010100061a024b53535009181c";
    char *xor_string = "686974207468652062756c6c277320657965";
    char *expected_string = "746865206b696420646f6e277420706c6179";
    size_t bin_input_len = get_bin_len(input_string);
    size_t bin_xor_len = get_bin_len(xor_string);
    byte *bin_input = hex_to_bin(input_string, bin_input_len);
    byte *bin_xor_str = hex_to_bin(xor_string, bin_xor_len);
    bin_xor(bin_input, bin_xor_str, bin_input_len, bin_xor_len);
    char *actual_string = bin_to_hex(bin_input, bin_input_len);
    printf("Actual output: %s\n", actual_string);
    if(strcasecmp(expected_string, actual_string) == 0){
        puts("Output matches");
    }else{
        puts("Output does not match");
    }
    return 0;
}