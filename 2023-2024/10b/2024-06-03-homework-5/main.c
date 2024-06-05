#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

uint8_t* lz77_compress(
    uint8_t* data, 
    size_t length,
    size_t* out_length,
    unsigned short window_size, 
    unsigned short lookahead_size
) {
    // unsigned int length = strlen(data);

    uint8_t* result = NULL;
    unsigned int result_length = 0;

    for(int idata = 0; idata < length; idata++) {
        uint8_t match_start = 0;
        uint8_t longest_match = 0;

        for(uint8_t i = 1; i < window_size && idata - i >= 0; i++) {
            uint8_t prev_index = idata - i;

            if(data[prev_index] == data[idata]) {
                uint8_t match_length = 1;
                for(; match_length < lookahead_size; match_length++)
                    if(data[prev_index + match_length] != data[idata + match_length])
                        break;

                if(match_length > longest_match) {
                    match_start = i;
                    longest_match = match_length;
                }
            }
        }

        if(longest_match > 0) {
            idata += longest_match - 1;

            result = realloc(result, result_length + 5);

            result[result_length++] = '(';
            result[result_length++] = match_start;
            result[result_length++] = ',';
            result[result_length++] = longest_match;
            result[result_length++] = ')';
        } else {
            result = realloc(result, result_length + 6);
            // result_length += 6;

            result[result_length++] = '(';
            result[result_length++] = 0;
            result[result_length++] = ',';
            result[result_length++] = 0;
            result[result_length++] = ')';
            result[result_length++] = data[idata];
        }
    }

    *out_length = result_length;
    return result;
}

int main() {
    uint8_t arr[] = {1,2,3,4,1,2,3,4,1,2,3,4};
    char* str = "ABCABCD";

    size_t compressed_length = 0;
    uint8_t* compressed = lz77_compress(arr, 7, &compressed_length, 5, 5);

    for(int i = 0; i < compressed_length; i++) {
        printf("c[%u] = %u %c\n", i, compressed[i], compressed[i]);
    }
    return 0;
}