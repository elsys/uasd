#ifndef DLIST_H
#define DLIST_H

typedef struct Node
{
    int value;
    struct Node *next;
    struct Node *prev;
} Node;
typedef struct DList
{
    Node *head;
    Node *tail;
} DList;

DList *init_dlist();
void insertBegin(DList *, int);
void insertEnd(DList *, int);

Node *getAt(DList *, int);
void clear(DList *);
int pop(DList *);
void printDList(DList *);
void printDListReverse(DList *);
int popFront(DList *);

void insertAt(DList *, Node *, Node *);
Node *removeAt(DList *, Node *);

Node *createNode(int val);
void insertBefore(DList *l, Node *it, Node *val);
void insertAfter(DList *l, Node *it, Node *val);
Node *removeAt(DList *l, Node *val);
#endif
