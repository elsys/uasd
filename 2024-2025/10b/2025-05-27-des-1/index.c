#include <stdio.h>
#include <stdint.h>

#include "helpers.h"

// Always uses the rightmost size bits of input and output
// With input 0b0000000010101010 and perm { 1, 3, 5, 7, 2, 4, 6, 8 }
// The output will be 0b0000000011110000
uint64_t permute(uint64_t input, uint8_t *perm, uint8_t size) {
  uint64_t output = 0;

  for(int i = 0; i < size; i++)  {
    uint64_t bit = (input >> (size - perm[i])) & 1;
    output |= (bit << (size - i - 1));
  }

  return output;
}

int main() {
  uint64_t input = 0b10101010; // 170
  uint8_t perm[] = { 1, 3, 5, 7, 2, 4, 6, 8 };
  uint8_t size = 8;
  uint64_t expected = 0b11110000; // 240;

  uint64_t result = permute(input, perm, size);

  printf("Input: %lu (0x%lx)\n", input, input);
  printBits(sizeof(input), &input);
  printf("Expected: %lu (0x%lx)\n", expected, expected);
  printBits(sizeof(expected), &expected);
  printf("Result: %lu (0x%lx)\n", result, result);
  printBits(sizeof(result), &result);

  return 0;
}
