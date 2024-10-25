#ifndef H_LIST_
#define H_LIST_

typedef struct Node {
    int val;
    struct Node* next;
    struct Node* prev;
} Node;

typedef struct LList {
    Node* head;
    Node * tail; 
} LList;

Node* init_node(int val);
LList* init_llist();

void insertBegin(LList* l, int val);
int popBegin(LList* l);
Node* getAt(LList* l, int i);

void printList(LList *l);
void clear(LList* l);
void freeList(LList* l);
void insertEnd(LList* l, int val);
int popEnd(LList* l);
void insertionSort(LList* l);

#endif