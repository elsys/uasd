#ifndef _VECTOR_H_
#define _VECTOR_H_

typedef struct vector {
    int *data;
    int size;
    int capacity;
} vector;

vector* init_vector();

void push(vector* v, int val);
int pop(vector* v);

void pushFront(vector* v, int val);
int popFront(vector* v);

void print_vector(vector* v);

void free_vector(vector* v);

#endif