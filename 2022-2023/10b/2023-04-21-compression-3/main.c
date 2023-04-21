#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int code_exists(vector_t* codes, uint8_t* data) {
  for(int i =0; i < codes->length; i++) {
    uint8_t* tmp = vector_get(codes, i);
    for(int j = 0; j < ???; j++) {
      if(tmp[j] != data[j]) break;
    }
    return 1;
  }

  return 0;
}

uint8_t* compress(uint8_t* data, uint32_t size) {
  vector_t* codes = vector_init();
  
  for(uint32_t i = 0; i < size; i++) {
    uint8_t tmp[1];
    tmp[0] =  data[i];
    
    if(!code_exists(codes, tmp))
      vector_add(codes, tmp);
  }
  
  for(uint32_t l = 2; l < size/2; l++)
    for(uint32_t i = 0; i < size - 1; i++) {
      uint8_t tmp[l];
      memcpy(tmp, data + i, l);
      
      for(uint32_t j = i + l; j < size - 1; j++) {
        uint8_t tmp2[l];
        memcpy(tmp2, data + j, l);
        
        if(arr_compare(tmp, tmp2) && !code_exists(codes, tmp)) {
          vector_add(codes, tmp);
          break;
        }
      }
    }

  uint8_t* out = malloc(100);
  vector_t* used_codes;
  for(uint32_t i = 0; i < size; i++) {
    for(int len = 10; len > 1; len--) {
      uint8_t tmp[len];
      memcpy(tmp, data + i, len);
      if(code_exists(codes, tmp)) {
        // sequence is found and is the longest possible starting at i
        out[outLen++] = vector_index_of(codes, tmp);
        i += len;
        vector_add(used_codes, tmp);
        break;
      }
    }
  }

  out[outLen++] = 0;
  for(uint8_t i = 0; i < used_codes->length; i++) {
    uint8_t* code = vector_get(used_codes, i);
    out[outLen++] = length(code);
    memcpy(out + outLen, code, length(code));
    outLen += length(code);
    out[outLen++] = i;
  }

  return out;
}

int main() {
	return 0;
};
