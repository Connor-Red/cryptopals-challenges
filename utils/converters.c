#include "converters.h"



// really ugly function to convert hex to binary
char* hex_char_to_binary(char hexDigit) {
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

// Nicer function to convert a 4 character binary string to hex
char binary_char_to_hex(char *binary_str){
    char* hex_str = malloc(2 * sizeof(char));
    // Scans the 4 character binary string into an int
    int decimal = strtol(binary_str, NULL, 2);
    sprintf(hex_str, "%X", decimal);
    char hex_char = hex_str[0];
    free(hex_str);
    // Apparently the hex values are in lowercase so a conversion is needed
    if(hex_char >= 'A' && hex_char <= 'Z'){
        hex_char = hex_char + ('a' - 'A');
    }
    return hex_char;
}

// Converts a binary string of any length to hex
char *binary_to_hex(char *binary_str){
    int binary_length = strlen(binary_str);
    int calculated_length = binary_length + (4 - binary_length % 4) % 4;
    char *adjusted_binary = malloc((calculated_length + 1) * sizeof(char));
    // Add leading zeroes if its not divisible by 4
    if(binary_length != calculated_length){
        for(int i = 0; i < calculated_length - binary_length; i++){
            adjusted_binary[i] = '0';
        }
    }
    // Adjusted string as follows
    strcat(adjusted_binary, binary_str);
    
    char *hex_str = malloc((calculated_length / 4 + 1) * sizeof(char));
    for(int i = 0; i < calculated_length; i += 4){
        char group[5];
        for(int j = 0; j < 4; j++){
            group[j] = adjusted_binary[j + i];
        }
        group[4] = '\0';
        hex_str[i/4] = binary_char_to_hex(group);
    }
    hex_str[calculated_length / 4 + 1] = '\0';
    return hex_str;
}

char *hex_to_binary(char *hex_str){
    int binary_length = 4 * strlen(hex_str);
    char *binary_string = malloc(sizeof(char) * binary_length + 1);

    for(int i = 0; hex_str[i] != '\0'; i++){
        char *binary_char = hex_char_to_binary(hex_str[i]);
        strncat(binary_string, binary_char, 4);
    }
    binary_string[binary_length + 1] = '\0';
    return binary_string;
}

char *hex_to_64(char *hex_str){
    int binary_length = 4 * strlen(hex_str);
    int calculated_length = (binary_length / 6);
    if(calculated_length % 6 != 0){
        calculated_length++;
    }
    char *calculated_string = malloc(sizeof(char) * calculated_length);
    // First convert the hex string to a binary string
    char *binary_string = hex_to_binary(hex_str);
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