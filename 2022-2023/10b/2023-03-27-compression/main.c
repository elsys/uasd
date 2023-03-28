#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned char* compress(unsigned char* data) {
    unsigned char* data_out = malloc(strlen(data));
    int pos = 0;

    // abccccccc => abcx6
    for(int i = 0; i < strlen(data); i++) {
        data_out[pos] = data[i];
        pos++;

        unsigned char counter = 1;
        for(;
            data[i] == data[i + counter] && i + counter < strlen(data); 
            counter++
        );

        printf("%c => %d\n", data[i], counter);
        if(counter > 3) {
            data_out[pos++] = 'x';
            data_out[pos++] = counter;
            i += counter - 1;
        }
    }
    data_out[pos] = '\0';

    return data_out;
}

unsigned char* decompress(unsigned char* data) {
    unsigned char* data_out = malloc(1);
    int pos = 0;

    // abcx6 => abccccccc
    for(int i = 0; i < strlen(data); i++) {
        data_out[pos++] = data[i];
        data_out = realloc(data_out, pos + 1);

        if(i < strlen(data) - 2 && data[i+1] == 'x' && data[i + 2] < 50) {
            for(int j = 0; j < data[i + 2] - 1; j++) {
                data_out[pos++] = data[i];
                data_out = realloc(data_out, pos + 1);
            }

            i += 2;
        }
    }
    data_out[pos] = '\0';
    
    return data_out;
}

int main() {
    char* data_in = "abcccccdeeeeee";
    // char* data_in = "abcx deeeeee";
    char* compressed = compress(data_in);
    char* decompressed = decompress(compressed);

    printf("Data: '%s'\n", data_in);
    printf("Compressed: '%s'\n", compressed);
    for(int i = 0; i < strlen(compressed); i++)
        printf("%d ", compressed[i]);
    printf("\n");
    printf("Decompresed: '%s'\n", decompressed);
    printf("Ratio: %f\n", (float)strlen(compressed) / strlen(data_in));
    return 0;
}