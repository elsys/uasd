#ifndef H_STACK_
#define H_STACK_

typedef struct Node {
    int val;
    struct Node* next;
} Node;

typedef struct Stack {
    Node* top; 
} Stack;

Node* init_node(int val);
Stack* init_stack();

void push(Stack* l, int val);
int pop(Stack* l);
int isEmpty(Stack *);
//void printList(LList *l);
// void clear(Stack* l);
// void freeList(LList* l);
// void insertEnd(LList* l, int val);
// int popEnd(LList* l);
// void insertionSort(LList* l);

#endif