#include "vector.h"
#include <stdlib.h>

void add_to_vector(struct vector_t* vec, int value) {
  vec->values = realloc(
    vec->values, 
    sizeof(int) * (vec->count + 1)
  );
  vec->values[vec->count] = value;
  vec->count++;
}
