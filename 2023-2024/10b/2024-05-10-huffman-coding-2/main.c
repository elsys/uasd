#include <stdio.h>
#include "map.h"

void huffman_encode(char* str, map_t* letters) {
    char* result = malloc(strlen(str));

    int byte_count = 0;
    int bit_count = 0;
    for(int i = 0; i < strlen(str); i++) {
        char curr_value = str[i];
        char code = map_get(letters, curr_value);
        short code_length = 3;

        // result[byte_count] <<= 3;
        // char code_left = code >> 2;
        // char code_right = code & 0b00000011;
        // result[byte_count] = result[byte_count] | code_left;
        // result[++byte_count] |= code_right;

        // 00000101 << 5 = 10100000
        // 00000101 << 2 = 00010100
        short remaining_bits = 8 - bit_count;
        char code_left = code;
        if(remaining_bits >= code_length)
            code_left <<= (remaining_bits - code_length); 
        else
            code_left >>= (code_length - remaining_bits);
        result[byte_count] |= code_left;

        if(remaining_bits >= code_length) {
            bit_count += code_length;
            if(bit_count >= 8) {
                bit_count = 0;
                byte_count++;
            }
        } else {
            bit_count = 0;
            byte_count++;
            code_length = code_length - remaining_bits;

            char code_right = code << (8 - code_length);
            result[byte_count] |= code_right;
            bit_count = code_length;
        }
    }

    result = realloc(result, byte_count);
}

int main() {
    map_t* letters = init_map(10);

    map_add(letters, "A", 0b000);
    map_add(letters, "B", 0b010);
    map_add(letters, "C", 0b110);
    map_add(letters, "D", 0b111);

    char* str = "ABCDAAB";

    huffman_encode(str, letters);

    return 0;
}