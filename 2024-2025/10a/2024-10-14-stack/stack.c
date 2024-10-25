#include "stack.h"
#include <stdlib.h>
#include <stdio.h>

Node* init_node(int val) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->next = NULL;
    node->val = val;

    return node;
};

Stack* init_stack() {
    Stack* l = (Stack*)malloc(sizeof(Stack));

    l->top = NULL;

    return l;
};

void push(Stack* l, int val) {
    Node* newNode = init_node(val);

    newNode->next = l->top;
    l->top = newNode;
};

int isEmpty(Stack *l) {
    return l->top == NULL;
}

int pop(Stack* l) {
    if (isEmpty(l)) {
        printf("Cannot pop from empty list");
        exit(1);
    }

    int val = l->top->val;
    Node* tmp = l->top;
    l->top = l->top->next;

    free(tmp);

    return val;
}