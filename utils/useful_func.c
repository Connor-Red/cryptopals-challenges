#include "useful_func.h"

// Calculates xor for a single binary char
char char_xor(char target, char comp){
    if(target == '0' && comp == '0'){
        return '0';
    }
    if(target == '0' && comp == '1'){
        return '1';
    }
    if(target == '1' && comp == '0'){
        return '1';
    }
    if(target == '1' && comp == '1'){
        return '0';
    }
    return 'x';
}

// Calculates xor for two binary strings
char *bin_xor(char * target, char * comp){
    if(strlen(target) != strlen(comp)){
        return NULL;
    }
    char *result = malloc((strlen(target) + 1) * sizeof(char));
    for(int i = 0; i < (int)strlen(target); i++){
        result[i] = char_xor(target[i], comp[i]);
    }
    result[strlen(target) + 1] = '\0';
    return(result);
}