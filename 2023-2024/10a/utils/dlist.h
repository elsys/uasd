#ifndef DLIST_H
#define DLIST_H

typedef struct Node
{
    void *value;
    struct Node *next;
    struct Node *prev;
} Node;
typedef struct DList
{
    Node *head;
    Node *tail;
} DList;

DList *init_dlist();
void insertBegin(DList *, void *);
void insertEnd(DList *, void *);

Node *getAt(DList *, void *);
void clear(DList *);
void *pop(DList *);
void printDList(DList *);
void printDListReverse(DList *);
void *popFront(DList *);

void insertAt(DList *, Node *, Node *);
Node *removeAt(DList *, Node *);

Node *createNode(void *val);
void insertBefore(DList *l, Node *it, Node *val);
void insertAfter(DList *l, Node *it, Node *val);
Node *removeAt(DList *l, Node *val);
#endif
