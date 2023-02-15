#include <stdlib.h>

#include "vector.h"

struct vector_t* vector_init() {
	struct vector_t* new_vec = malloc(sizeof(struct vector_t));
	
	new_vec->size = 0;
	new_vec->values = NULL;
	
	return new_vec;
}

void vector_add(struct vector_t* vec, void* value) {
  vec->values = realloc(vec->values, (vec->size + 1) * sizeof(void*));
  vec->values[vec->size] = value;
  vec->size++;
}

void* vector_get(struct vector_t* vec, int index) {
  if(index > vec->size) return NULL;
  return vec->values[index];
}
