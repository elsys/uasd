#ifndef LIST_H
#define LIST_H

typedef struct Node
{
    int value;
    struct Node *next;
} Node;

typedef struct List
{
    Node *head;
} List;

List *init_list();
void insertBegin(List *, int);
int getAt(List *, int);
void clear(List *);
int pop(List *);
void printList(List *);
int popFront(List *);
#endif
