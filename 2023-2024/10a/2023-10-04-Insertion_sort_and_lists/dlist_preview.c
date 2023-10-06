#include <stdio.h>
#include "dlist.h"

int main()
{
    DList *l = init_dlist();
    printDList(l); // EMPTY
    insertBegin(l, 1);
    printDList(l); // 1
    popFront(l);
    printDList(l); // EMPTY
    insertEnd(l, 5);
    printDListReverse(l); // 5

    insertBegin(l, 2);
    insertBegin(l, 3);
    insertBegin(l, 4);
    printDList(l); // 4 3 2 5

    int val = popFront(l);
    printf("popped = %d\n", val); // popped = 4
    printDList(l);                // 3 2 5

    val = pop(l);
    printf("popped = %d\n", val); // popped = 5
    printDListReverse(l);         // 2 3

    printf("at 3 = %d ", getAt(l, 1)); // 2

    clear(l);

    return 0;
}