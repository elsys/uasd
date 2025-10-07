#ifndef _LIST_H_
#define _LIST_H_

typedef struct  Node {
    int val;
    struct Node* next;
    struct Node* prev;
} Node;

typedef struct LList {
    Node* head;
    Node* tail;
} LList;

Node* init_node(int val);
LList* init_llist();
void insertHead(LList* list, int val);
int popHead(LList* list);
void printList(LList* list);
void printListReverse(LList* list);
int getAt(LList* list, int index);

#endif