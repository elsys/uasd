#ifndef DLIST_H
#define DLIST_H

struct Node {
    struct Node* next;
    struct Node* prev;
    int val;
};

typedef struct Node Node;

typedef struct Dlist {
    struct Node* head;
    struct Node* tail;
    int size;
} Dlist;

Dlist initList();

Node* createNode(int val);

void pushFront(Dlist* list, int val);
void pushBack(Dlist* list, int val);
void pushAt(Dlist* list, int val, int idx);

void popFront(Dlist* list);
void popBack(Dlist* list);
void popAt(Dlist* list, int idx);

Node* getAt(Dlist* list, int idx);

void printFromHead(Dlist* list);
void printFromTail(Dlist* list);

void release(Dlist* list);

#endif