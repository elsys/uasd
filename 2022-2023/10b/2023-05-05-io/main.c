#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 1. Using console arguments; converting from string to int; read/write to formatted strings
/*
int main(int argc, char** argv) {
    for(int i = 0; i < argc + 5; i++) {
        printf("argv[%d] = '%s'\n", i, argv[i]);
    }
    if(strcmp(argv[1], "arg1") == 0) {
        puts("Same");
    } else {
        puts("Not Same");
    }
    printf("%d\n", atoi(argv[4]));
    printf("%d\n", atoi(argv[2]));

    int tmp;
    // scanf("%d", &tmp);
    if(sscanf(argv[4], "%d", &tmp) != 1) {
        puts("Error at 4");
    }
    if(sscanf(argv[2], "%d", &tmp) != 1) {
        puts("Error at 2");
    }

    // char* str1 = "asd";
    // char* str2 = "123";

    // strcpy(str1, str2); // str1 = "123"
    // strcat(str1, str2); // str1 = "asd123"!
    // sprintf(str1, "%s", str2); // str1 = "123"
    // sprintf(str1, "%s%s", str1, str2); // str1 = "asd123"!

    return 0;
}
*/

// 2. Open, use, close file; read and write to file 
// int main() {
//     FILE* fout = fopen("out.txt", "w");
//     if(fout == NULL) {
//         puts("Failed to open");
//     } else {
//         fputs("Hello\n", fout);

//         int a = 10;
//         fprintf(fout, "%d", a);

//         fclose(fout);
//         fout = NULL;
//     }

//     FILE* fin = fopen("out.txt", "r");
//     if(fin == NULL) {
//         puts("Failed to open");
//     } else {
//         char str[10];
//         fgets(str, 10, fin);

//         int a = 0;
//         fscanf(fin, "%d", &a);

//         fclose(fin);
//         fin = NULL;

//         printf("%s\n%d\n", str, a);
//     }

//     return 0;
// }

// 3. Read and write raw data and bytes to binary files
struct my_type_t {
    int a;
    float b;
    char c;
};

int main() {
    // Open some file in "write + binary" mode
    FILE* fout = fopen("demo.bin", "wb");
    if(fout == NULL) {
        puts("Failed to open");
        return 1;
    }

    int a = 5;
    char* b = "test";
    struct my_type_t c = {1, 2.0f, 'a'};
    int d[4] = {1,2,3,4};

    // Write the 4 bytes of a single int
    fwrite(&a, sizeof(int), 1, fout);
    // Write all 4 characters of the string + the \0 at the end
    fwrite(&b, sizeof(char), strlen(b) + 1, fout);
    // All data types are dumped in the same shape they are represented in memory
    fwrite(&c, sizeof(struct my_type_t), 1, fout);
    // Dump an array of 4 consecutive ints
    fwrite(&d, sizeof(int), 4, fout);

    fclose(fout);
    fout = NULL;

    FILE* fin = fopen("demo.bin", "rb");
    if(fin == NULL) {
        puts("Failed to open");
        return 1;
    }

    int a2;
    // We need a way to know beforehand how much data we're expecting to read
    char* b2 = malloc(sizeof(char) * 5);
    struct my_type_t c2;
    int d2[4];

    // Read 4 bytes as a single int
    fread(&a2, sizeof(int), 1, fin);
    // Read an array of 5 consecutive items, each 1 byte long
    fread(&b2, sizeof(char), 5, fin);
    // All the bytes are copied into the struct and will work if it's represented the same way in memory
    fread(&c2, sizeof(struct my_type_t), 1, fin);
    // Read an array of 4 items, each 4 bytes long
    fread(&d2, sizeof(int), 4, fin);

    printf("a2=%d\n", a2);
    printf("b2=%s strlen(b2)=%lu\n", b2, strlen(b2));
    printf("c2={%d, %f, %c}\n", c2.a, c2.b, c2.c);
    for(int i = 0; i < 4; i++)
        printf("d2[%d]=%d\n", i, d2[i]);

    fclose(fin);
    fin = NULL;

    return 0;
}