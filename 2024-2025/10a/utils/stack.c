#include <stdio.h>
#include <stdlib.h>
#include "stack.h"


Stack *init_stack()
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->top = NULL;
}

void push(Stack *stack, int val)
{
    StackNode *node = create_node(val);
    node->next = stack->top;
    stack->top = node;
}

int pop(Stack *stack)
{
    if (stack->top == NULL)
    {
        printf("Stack is empty.\n");
        exit(1);
    }

    int val = stack->top->val;
    StackNode *tmp = stack->top;
    stack->top = stack->top->next;
    free(tmp);

    return val;
}

void clear_stack(Stack *stack)
{
    while (stack->top != NULL)
    {
        pop(stack);
    }

    free(stack);
}

void print_stack(Stack *stack)
{
    StackNode *it = stack->top;
    printf("S: ");
    while (it != NULL)
    {
        printf("%d -> ", it->val);
        it = it->next;
    }
    printf("NULL\n");
}