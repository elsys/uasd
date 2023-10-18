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

Node *getAt(DList *l, int index)
{
    int i = 0;
    Node *it = l->head;

    while (it != NULL && i < index)
    {
        it = it->next;
        i++;
    }

    if (i == index)
    {
        return it;
    }

    // handle error
    printf("Index out of range");
    exit(1);
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

void insertAfter(DList *l, Node *it, Node *val)
{
    if (it == NULL)
    {
        printf("Invalid insert position\n");
        exit(1);
    }

    val->next = it->next;
    val->prev = it;

    if (it->next != NULL)
    {
        it->next->prev = val;
    }
    else
    {
        l->tail = val;
    }

    it->next = val;
}

void insertBefore(DList *l, Node *it, Node *val)
{
    if (it == NULL)
    {
        printf("Invalid insert position\n");
        exit(1);
    }

    val->next = it;
    val->prev = it->prev;

    if (it->prev != NULL)
    {
        it->prev->next = val;
    }
    else
    {
        l->head = val;
    }

    it->prev = val;
}

Node *removeAt(DList *l, Node *val)
{
    if (val->prev != NULL)
    {
        val->prev->next = val->next;
    }
    else
    {
        l->head = val->next;
    }

    if (val->next != NULL)
    {
        val->next->prev = val->prev;
    }
    else
    {
        l->tail = val->prev;
    }

    val->next = NULL;
    val->prev = NULL;

    return val;
}
