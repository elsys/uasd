/*
    Аз компилирам с
    gcc tasks.c dlist.c && ./a.out

    ако желаете си направете Makefile или какъвто друг начин искате.
*/

#include <stdio.h>
#include <stdlib.h>
#include "dlist.h"

void InsertionSort(DList *l)
{
    if (l->head == NULL || l->head->next == NULL)
    {
        return;
    }

    Node *it = l->head->next;

    while (it != NULL)
    {
        Node *backIt = it->prev;
        Node *next = it->next;
        Node *current = removeAt(l, it);

        while (backIt != NULL && current->value < backIt->value)
        {
            backIt = backIt->prev;
        }

        if (backIt != NULL)
        {
            insertAfter(l, backIt, current);
        }
        else
        {
            insertBegin(l, current->value);
        }

        it = next;
    }
}

// за треата и четвърта не остана време, помислете ги малко сами преди да кача решения

int main()
{
    DList *l = init_dlist();
    insertEnd(l, 1);
    insertEnd(l, 2);
    insertEnd(l, 3);
    insertEnd(l, 4);

    Node *n = getAt(l, 0);
    Node *n2 = getAt(l, 2);
    Node *n3 = getAt(l, 3);

    printf("at 0 = %d \n", n->value);  // at 0 = 1
    printf("at 2 = %d \n", n2->value); // at 2 = 3
    printf("at 3 = %d \n", n3->value); // at 3 = 4

    insertBefore(l, n, createNode(0));
    insertBefore(l, n2, createNode(5));
    insertBefore(l, n3, createNode(6));

    printDList(l); // 0 1 2 5 3 6 4

    Node *removed = removeAt(l, l->head);
    printf("removed %d\n", removed->value); // removed 1
    free(removed);
    removed = removeAt(l, n2);
    printf("removed %d\n", removed->value); // removed 3
    free(removed);
    removed = removeAt(l, l->tail);
    printf("removed %d\n", removed->value); // removed 4
    free(removed);

    printDList(l); // 1 2 5 6

    insertBegin(l, -2);
    insertBegin(l, 10);
    insertBegin(l, -15);
    insertBegin(l, 100);

    printDList(l); // 100 -15 10 -2 1 2 5 6
    InsertionSort(l);
    printDList(l);        // -15 -2 1 2 5 6 10 100
    printDListReverse(l); // 100 10 6 5 2 1 -2 -15

    // printf("Mid elem = %d\n", getMid(l)->value); // 5
    // pop(l);
    // Node *mid = getMid(l);
    // printf("Mid elem = %d\n", mid->value); // 2

    // printf("Has cycle: %d\n", hasCycle(l)); // Has cycle: 0
    // l->tail->next = mid;
    // printf("Has cycle: %d\n", hasCycle(l)); // Has cycle: 1
}