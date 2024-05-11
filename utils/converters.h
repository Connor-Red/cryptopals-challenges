#ifndef CONVERTERS_H
#define CONVERTERS_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

//Base 64 table in order
#define BASE_64_TABLE "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"

typedef unsigned char byte;

extern size_t get_bin_len(char *);

extern byte *hex_to_bin(char *, size_t);

extern char *bin_to_hex(byte *, size_t);

extern char *bin_to_b64(byte *, size_t);

extern size_t b64_encoded_size(size_t);

#endif