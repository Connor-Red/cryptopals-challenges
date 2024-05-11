#include "useful_func.h"

void bin_xor(unsigned char *bin_dest, unsigned char *bin_src,
size_t dest_size, size_t src_size){
    // TODO: implement cases when src is not the same length as dest
    if(dest_size != src_size){
        return;
    }
    for(size_t i = 0; i < dest_size; i++){
        bin_dest[i] = bin_dest[i] ^ bin_src[i];
    }
}