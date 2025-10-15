#ifndef _STACK_H_
#define _STACK_H_

#include <stdbool.h>

typedef struct  Node {
    int val;
    struct Node* next;
} Node;

typedef struct Stack {
    Node* top;
} Stack;

Node* init_node(int val);
Stack* init_stack();
void push(Stack* stack, int val);
int pop(Stack* stack);
void printStack(Stack* stack);
bool isEmpty(Stack* stack);

#endif