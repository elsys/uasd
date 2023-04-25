#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

uint8_t* compress(uint8_t* data, uint32_t size) {
  vector_t* codes = vector_init();

  for(uint32_t i = 0; i < 3; i++) {
    uint8_t tmp[1];
    tmp[0] = 'a' + i;
    
    vector_add(codes, tmp);
  }

  uint8_t* out = malloc(size);
  for(uint32_t i = 0; i < size; i++) {
    vector_t* tmp = vector_init();
    vector_add(tmp, data[i]);

    while(code_exists(codes, tmp->value)) {
      vector_add(tmp, data[i + ?]);
    }

    vector_add(codes, tmp->value);

    vector_pop(tmp);
    out[outLen++] = vector_index_of(codes, tmp->value);
    i += ?;
  }

  return out;
}

uint8_t* decompress(uint8_t* data, uint32_t size) {
  return NULL;
}

int main() {
  uint8_t* data = "aaaaabcabc";

  uint8_t* compressed = compress(data, 10);
  uint8_t* decompressed = decompress(compressed, 10);

  printf("Input: %s\n", data);
  printf("Compressed: %s\n", compressed);
  printf("Decmpressed: %s\n", decompressed);

  return 0;
}