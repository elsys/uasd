#include "list.h"
#include <stdlib.h>
#include <stdio.h>

List *init_list()
{
    List *l = (List *)malloc(sizeof(List));
    l->head = NULL;

    return l;
}

Node *createNode(int val)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->value = val;
    node->next = NULL;

    return node;
}

void insertBegin(List *l, int val)
{
    Node *node = createNode(val);
    node->next = l->head;
    l->head = node;
}

int popFront(List *l)
{
    if (l->head == NULL)
    {
        printf("List already empty\n");
        exit(1);
    }

    Node *node = l->head;
    l->head = l->head->next;

    int val = node->value;
    free(node);

    return val;
}

void clear(List *l)
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

int getAt(List *l, int index)
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
        return it->value;
    }

    // handle error
    printf("Index out of range");
    exit(1);
}

/*
    Виждаме, че без директен достъп до последния елемент на списъка pop-ване на последния елемент е доста неудобно.
    Реално дори да имахме указател към последния елемент това не ни стига. С едносвързан списък ни трябва и към предпоследния.
    Затова ако ни се налага да извършваме често такива операции е по-удобно да изпозлваме двусвързан списък. Допълнителната памет и работа
    за менежиране на два указателя са несъществени спрямо улеснението и забързаването, което ще получим.
*/
int pop(List *l)
{
    if (l->head == NULL)
    {
        printf("List already empty\n");
        exit(1);
    }
    if (l->head->next == NULL)
    {
        return popFront(l);
    }

    Node *it = l->head;

    while (it->next->next != NULL)
    {
        it = it->next;
    }

    Node *last = it->next;
    it->next = NULL;

    int val = last->value;
    free(last);

    return val;
}

void printList(List *l)
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