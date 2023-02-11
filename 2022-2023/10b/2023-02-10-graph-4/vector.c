#include <stdlib.h>

#include "vector.h"

void vector_add(struct vector_t* vec, void* value) {
  vec->values = realloc(vec->values, (vec->size + 1) * sizeof(void*));
  vec->values[vec->size] = value;
  vec->size++;
}

void* vector_get(struct vector_t* vec, int index) {
  if(index > vec->size) return NULL;
  return vec->values[index];
}
