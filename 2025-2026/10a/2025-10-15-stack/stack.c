#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

Node* init_node(int val) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->val = val;
    node->next = NULL;
    
    return node;
}
Stack* init_stack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = NULL;
    
    return stack;
}

void push(Stack* stack, int val) {
    Node* new_node = init_node(val);
    new_node->next = stack->top;
    stack->top = new_node;
}

int pop(Stack* stack) {
    if (stack->top == NULL) {
        printf("List already empty");
        exit(1);
    }
    
    Node* currentTop = stack->top;
    int res = currentTop->val;
    stack->top = currentTop->next;
    free(currentTop);
    
    return res;
}

void printStack(Stack* stack) {
    Node* it = stack->top;
    
    while(it != NULL) {
        printf("%d ", it->val);
        it = it->next;
    }
    printf("\n");
}

bool isEmpty(Stack* stack) {
    return stack->top == NULL;
}