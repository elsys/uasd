#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned char* add_int(unsigned char* str, int a) {
    unsigned char* out = malloc(strlen(str) + 1);

    for(int i = 0; i < strlen(str); i++) {
        out[i] = (str[i] + a) % 256;
    }

    out[strlen(str) + 1] = '\0';
    return out;
}



unsigned char* table_method(unsigned char* str, int a) {
    unsigned char* out = malloc(strlen(str) + 1);

    for(int i = 0; i < strlen(str); i++) {
        out[i] = str[i + (i*a)];
    }

    out[strlen(str) + 1] = '\0';
    return out;
}

int main() {
    unsigned char* str = "hello 10b";

    unsigned char* out_1 = add_int(str, 3);

    printf("\"%s\"\n", str);
    printf("\"%s\"\n", out_1);

    return 0;
}