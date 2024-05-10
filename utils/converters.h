#ifndef CONVERTERS_H
#define CONVERTERS_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Base 64 table in order
#define BASE_64_TABLE "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"

extern char binary_char_to_hex(char *);

extern char *binary_to_hex(char *);

extern char* hex_char_to_binary(char);

extern char *hex_to_binary(char *);

extern char *hex_to_64(char *);

#endif