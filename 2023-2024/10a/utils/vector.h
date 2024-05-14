#ifndef VECTOR
#define VECTOR

typedef struct vector_t
{
    void **arr;
    unsigned int size;
    unsigned int capacity;
} vector_t;

vector_t *init_vector();
void push_back(vector_t *, void *);
int pop(vector_t *);
void clear(vector_t *);

int getAt(vector_t *, void *);
int getSize(vector_t *);

void printVector(vector_t *);
#endif