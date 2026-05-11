#include <stdio.h>
#include <stdint.h>

void print_binary(unsigned char n) {
  for (int i = 7; i >= 0; i--) {
    printf("%d", (n >> i) & 1);
  }
}

int main() {
  // unsigned char a = 0;
  // uint8_t b = 0;

  // print_binary(a);
  // putchar('\n');
  // print_binary(b);
  // putchar('\n');

  char* data = "ABCAABBD";
  unsigned char table[4][2] = {
    {'A', 0b00000000},
    {'B', 0b00000001},
    {'C', 0b00000010},
    {'D', 0b00000011}
  };

  uint8_t compressed[8] = {0};
  int n = 0;
  int b = 0;
  for (int i = 0; data[i] != '\0'; i++) {
    unsigned char c = data[i];
    uint8_t code = 0;
    for (int j = 0; j < 4; j++) {
      if (table[j][0] == c) {
        code = table[j][1];
        break;
      }
    }
    // compressed[i] = code;
    // For every 4 characters (8 bits), we can store 4 codes (2 bits each) from left to right in a single byte.
    uint8_t shifted = code << (3 - (n % 4)) * 2;
    compressed[b] |= shifted;
    // After the byte is full (4 codes), we move to the next byte().
    if(++n == 4) {
      n = 0;
      b++;
    }
  }

  for (int i = 0; i < 8; i++) {
    printf("Byte %d: ", i);
    print_binary(compressed[i]);
    putchar('\n');
  }

  return 0;
}
