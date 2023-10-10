#include <stdio.h>

// Initial permutation for the data
uint8_t IP_TABLE[64] = {
    // 6, 2, 7, 0, 3, 4, 1, 5
  58, 50, 42, 34, 26, 18, 10, 2,
  60, 52, 44, 36, 28, 20, 12, 4,
  62, 54, 46, 38, 30, 22, 14, 6,
  64, 56, 48, 40, 32, 24, 16, 8,
  57, 49, 41, 33, 25, 17,  9, 1,
  59, 51, 43, 35, 27, 19, 11, 3,
  61, 53, 45, 37, 29, 21, 13, 5,
  63, 55, 47, 39, 31, 23, 15, 7
};

// Final permutation for the data
uint8_t FP_TABLE[64] = {
  40, 8, 48,  16,  56, 24,  64, 32,
  39, 7, 47,  15,  55, 23,  63, 31,
  38, 6, 46,  14,  54, 22,  62, 30,
  37, 5, 45,  13,  53, 21,  61, 29,
  36, 4, 44,  12,  52, 20,  60, 28,
  35, 3, 43,  11,  51, 19,  59, 27,
  34, 2, 42,  10,  50, 18,  58, 26,
  33, 1, 41,   9,  49, 17,  57, 25
};

// The message half is 32 bits and the key is 48 so we need to expand the message
uint8_t EXPANSION_TABLE[48] = {
  32,  1,  2,  3,  4,  5,
   4,  5,  6,  7,  8,  9,
   8,  9, 10, 11, 12, 13,
  12, 13, 14, 15, 16, 17,
  16, 17, 18, 19, 20, 21,
  20, 21, 22, 23, 24, 25,
  24, 25, 26, 27, 28, 29,
  28, 29, 30, 31, 32,  1
};

uint8_t* permutation(uint8_t* table, uint8_t* data, uint8_t size) {
    uint8_t* result = malloc(size / 8);

    for(int i = 0; i < size; i++) {
        int bit_index = (table[i] - 1) % 8;
        int byte_index = (table[i] - 1) / 8;

        uint8_t d = data[byte_index];
        uint8_t* r = result + (i / 8);

        *r <<= 1;
        *r |= (d >> (7 - bit_index)) & 1;
    }

    return result;
}

void apply_feistel(uint8_t* L, uint8_t* R, uint8_t* K) {
    // expanded = E(R0)
    // xored = xor(expanded, K0)
    // substituted = S0(xored) + S1(xored) + ... + S7(xored)
    // permutted = P(substituted)
    // L0 = xor(L0, permutted)

    uint8_t* expanded = permutation(EXPANSION_TABLE, R, 48);
    
}

uint8_t* encrypt(
    uint8_t* data, // 64 bits
    uint8_t* key // 56 bits
) {
    // I = IP(data)
    // L0, R0 = split(I)

    // expanded = E(R0)
    // xored = xor(expanded, K0)
    // substituted = S0(xored) + S1(xored) + ... + S7(xored)
    // permutted = P(substituted)
    // L0 = xor(L0, permutted)

    // R = join(L0, R0)
    // O = FP(R)

    // uint8_t d = data[0];
    // uint8_t r = 0;

    // for(int i = 0; i < 8; i++) {
    //     // r[i] = d[IP_TABLE[i]];
    //     r << 1;
    //     r |= (d >> (7 - IP_TABLE[i])) & 1;
    // }

    // uint8_t* result = malloc(8);

    // for(int i = 0; i < 64; i++) {
    //     int bit_index = (IP_TABLE[i] - 1) % 8;
    //     int byte_index = (IP_TABLE[i] - 1) / 8;

    //     uint8_t d = data[byte_index];
    //     uint8_t* r = result + (i / 8);

    //     *r <<= 1;
    //     *r |= (d >> (7 - bit_index)) & 1;
    // }

    uint8_t* I = permutation(IP_TABLE, data, 64);

    uint8_t* L0 = I;
    uint8_t* R0 = I + 4;

    apply_feistel();

    uint8_t* O = permutation(FP_TABLE, I, 64);

    return O;
}


int main() {
    return 0;
}