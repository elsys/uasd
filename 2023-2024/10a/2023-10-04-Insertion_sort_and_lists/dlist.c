#include "dlist.h"
#include <stdlib.h>
#include <stdio.h>

DList *init_dlist()
{
    DList *l = (DList *)malloc(sizeof(DList));
    l->head = NULL;
    l->tail = NULL;

    return l;
}

Node *createNode(int val)
{
    Node *n = (Node *)malloc(sizeof(Node));
    n->value = val;
    n->next = NULL;
    n->prev = NULL;
}

void insertBegin(DList *l, int val)
{
    Node *n = createNode(val);

    // при празен лист и head и tail са NULL, а при един елемент той е едновременно и head и tail.
    if (l->head == NULL)
    {
        l->head = n;
        l->tail = n;

        return;
    }

    n->next = l->head;
    l->head->prev = n;
    l->head = n;
}

void insertEnd(DList *l, int val)
{
    Node *n = createNode(val);

    if (l->tail == NULL)
    {
        l->head = n;
        l->tail = n;

        return;
    }

    n->prev = l->tail;
    l->tail->next = n;
    l->tail = n;
}

int getAt(DList *l, int index)
{
    return 0;
}

void insertAt(DList *l, int index, int val)
{
}

int removeAt(DList *l, int index)
{
    return 0;
}

int popFront(DList *l)
{
    if (l->head == NULL)
    {
        printf("Cannot pop from EMPTY\n");
        exit(1);
    }

    int val = l->head->value;
    Node *head = l->head;

    // Ако списъка има само един елемент го правим на празен списък
    if (l->head->next == NULL)
    {
        l->head = NULL;
        l->tail = NULL;
    }
    else
    {
        l->head->next->prev = NULL;
        l->head = l->head->next;
    }

    free(head);

    return val;
}

int pop(DList *l)
{
    if (l->tail == NULL)
    {
        printf("Cannot pop from EMPTY\n");
        exit(1);
    }

    int val = l->tail->value;
    Node *tail = l->tail;

    if (l->tail->prev == NULL)
    {
        l->head = NULL;
        l->tail = NULL;
    }
    else
    {
        l->tail->prev->next = NULL;
        l->tail = l->tail->prev;
    }

    free(tail);

    return val;
}

void printDList(DList *l)
{
    if (l->head == NULL)
    {
        printf("EMPTY\n");
        return;
    }

    Node *it = l->head;

    while (it != NULL)
    {
        printf("%d ", it->value);
        it = it->next;
    }

    printf("\n");
}

void printDListReverse(DList *l)
{
    if (l->tail == NULL)
    {
        printf("EMPTY\n");
        return;
    }

    Node *it = l->tail;

    while (it != NULL)
    {
        printf("%d ", it->value);
        it = it->prev;
    }

    printf("\n");
}

void clear(DList *l)
{
    Node *it = l->head;

    while (it != NULL)
    {
        Node *tmp = it;
        it = it->next;
        free(tmp);
    }

    free(l);
}