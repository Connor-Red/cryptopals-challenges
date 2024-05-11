#include "converters.h"

size_t get_bin_len(char *hex_len){
    size_t bin_len = strlen(hex_len)/2;
    if(strlen(hex_len) % 2 != 0){
        bin_len++;
    }
    return bin_len;
}

byte *hex_to_bin(char *hex_org, size_t bin_len){
    size_t hex_len = strlen(hex_org);
    char *hex_str = malloc((hex_len + 1) * sizeof(char));
    strcpy(hex_str, hex_org);
    // if the hex string is not divisible by 2, add a leading 0
    if((hex_len % 2) != 0){
        hex_str = realloc(hex_str, (hex_len + 2) * sizeof(char));
        for(int i = hex_len; i >= 0; i--){
            hex_str[i+1] = hex_str[i];
        }
        hex_str[0] = '0';
        hex_len ++;
    }
    byte *bin_arr = malloc(bin_len);
    for(size_t i = 0; i < bin_len; i++){
        // Read in 2 hex characters at a time then convert it to binary as long
        char buf[3] = {hex_str[i * 2], hex_str[i * 2 + 1], '\0'};
        bin_arr[i] = strtol(buf, NULL, 16);
    }
    free(hex_str);
    return bin_arr;
}

char *bin_to_hex(byte *bin_arr, size_t bin_len){
    char *output = malloc(bin_len * 2 + 1);
    char *arr_ptr = &output[0];

    for(size_t i = 0; i < bin_len; i++){
        // In this line, basically print 2 characters in hex, then advance the
        // pointer by 2 characters
        arr_ptr += sprintf(arr_ptr, "%02X", bin_arr[i]);
    }

    return output;
}

/** Code taken from https://nachtimwald.com/2017/11/18/base64-encode-and-decode-in-c/
* I have already written a working b64 encode and i'm lazy to write another one
* This works by turning 3 byte sequences into 4 chars
*/
char *bin_to_b64(byte *in, size_t len)
{
	char   *out;
	size_t  elen;
	size_t  i;
	size_t  j;
	size_t  v;

	if (in == NULL || len == 0)
		return NULL;

	elen = b64_encoded_size(len);
	out  = malloc(elen+1);
	out[elen] = '\0';

	for (i=0, j=0; i<len; i+=3, j+=4) {
		v = in[i];
		v = i+1 < len ? v << 8 | in[i+1] : v << 8;
		v = i+2 < len ? v << 8 | in[i+2] : v << 8;

		out[j]   = BASE_64_TABLE[(v >> 18) & 0x3F];
		out[j+1] = BASE_64_TABLE[(v >> 12) & 0x3F];
		if (i+1 < len) {
			out[j+2] = BASE_64_TABLE[(v >> 6) & 0x3F];
		} else {
			out[j+2] = '=';
		}
		if (i+2 < len) {
			out[j+3] = BASE_64_TABLE[v & 0x3F];
		} else {
			out[j+3] = '=';
		}
	}

	return out;
}

// Returns the size of the b64 string
size_t b64_encoded_size(size_t inlen)
{
	size_t ret;

	ret = inlen;
	if (inlen % 3 != 0)
		ret += 3 - (inlen % 3);
	ret /= 3;
	ret *= 4;

	return ret;
}