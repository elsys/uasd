#include <stdio.h>
#include <stdlib.h>

struct vector_t {
  unsigned int capacity;
  unsigned int size;
  int *data;
};

struct vector_t init() {
  struct vector_t new_vector;

  new_vector.capacity = 0;
  new_vector.size = 0;
  new_vector.data = NULL;

  return new_vector;
}

void resize(struct vector_t* vec, unsigned int new_capacity) {
  vec->capacity = new_capacity;
  vec->data = realloc(vec->data, new_capacity * sizeof(int));
  if(new_capacity < vec->size)
    vec->size = new_capacity;
}

void push_back(struct vector_t* vec, int new_value) {
  if(vec->size == vec->capacity)
    resize(vec, vec->capacity * 2);

  vec->data[vec->size++] = new_value;
}

void pop_back(struct vector_t* vec) {
  if(vec->size == 0) return;

  vec->data[--vec->size] = 0;
}

void print_vec(struct vector_t* vec) {
  for(int i =0; i < vec->size; i++) {
    printf("[%d] %d\n", i, vec->data[i]);
  }
}

void insert_at(struct vector_t* vec, int new_value, unsigned int index) {
  if(index > vec->size + 1) return;

  if(vec->size == vec->capacity)
    resize(vec, vec->capacity * 2);

  for(int i = vec->size; i > index; i--) {
    vec->data[i] = vec->data[i - 1];
  }
  vec->data[index] = new_value;
  vec->size++;
}

int main() {
  struct vector_t v1 = init();

  push_back(&v1, 4);
  push_back(&v1, 5);
  push_back(&v1, 6);
  push_back(&v1, 8);

  resize(&v1, 100);

  pop_back(&v1);
  pop_back(&v1);

  print_vec(&v1);

  insert_at(&v1, 10, 0);
  print_vec(&v1);

  insert_at(&v1, 11, 2);
  print_vec(&v1);

  insert_at(&v1, 12, 4);
  print_vec(&v1);

  return 0;
}
