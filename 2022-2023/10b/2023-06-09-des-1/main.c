#include <stdio.h>

// Initial permutation for the data
uint8_t IP_TABLE[64] = {
    6, 2, 7, 0, 3, 4, 1, 5
//   58, 50, 42, 34, 26, 18, 10, 2,
//   60, 52, 44, 36, 28, 20, 12, 4,
//   62, 54, 46, 38, 30, 22, 14, 6,
//   64, 56, 48, 40, 32, 24, 16, 8,
//   57, 49, 41, 33, 25, 17,  9, 1,
//   59, 51, 43, 35, 27, 19, 11, 3,
//   61, 53, 45, 37, 29, 21, 13, 5,
//   63, 55, 47, 39, 31, 23, 15, 7
};

uint8_t* encrypt(
    uint8_t* data, // 64 bits
    uint8_t* key // 56 bits
) {
    // I = IP(data)
    // L0, R0 = split(I)
    // ...
    // R = join(L0, R0)
    // O = FP(R)

    uint8_t d = data[0];
    uint8_t r = 0;

    for(int i = 0; i < 8; i++) {
        // r[i] = d[IP_TABLE[i]];
        r << 1;
        r |= (d >> (7 - IP_TABLE[i])) & 1;
    }
}


int main() {
    return 0;
}