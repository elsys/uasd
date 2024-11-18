#ifndef STACK_H
#define STACK_H

typedef struct StackNode
{
    int val;
    struct StackNode *next;
} StackNode;

typedef struct Stack
{
    StackNode *top;
} Stack;

Stack *init_stack();
void push(Stack *stack, int val);
int pop(Stack *stack);
void clear_stack(Stack *stack);
void print_stack(Stack *stack);

#endif