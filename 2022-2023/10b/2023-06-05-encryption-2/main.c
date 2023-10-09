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
        int y = i / a;
        int x = x % a;

        int y2 = x;
        int x2 = y;

        int n = y2 * (strlen(str) / a) + x2;
        out[n] = str[i];

        // int n = (x % a) * (strlen(str) / a) + (i / a);
        // out[(x % a) * (strlen(str) / a) + (i / a)] = str[i];
    }

    out[strlen(str) + 1] = '\0';
    return out;
}

int main() {
    unsigned char* str = "hello 10b";

    unsigned char* out_1 = add_int(str, 3);
    unsigned char* out_2 = table_method(str, 4);
    unsigned char* out_3 = table_method(
        add_int(str, 3), 
        4
    );

    printf("\"%s\"\n", str);
    printf("\"%s\"\n", out_1);
    printf("\"%s\"\n", out_2);
    printf("\"%s\"\n", out_3);

    return 0;
}