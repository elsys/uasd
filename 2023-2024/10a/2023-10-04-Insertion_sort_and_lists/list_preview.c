#include <stdio.h>
#include "list.h"

int main()
{
    List *l = init_list();
    printList(l);
    insertBegin(l, 1);
    popFront(l);
    printList(l);

    insertBegin(l, 2);
    insertBegin(l, 3);
    insertBegin(l, 4);

    int val = popFront(l);
    printf("popped = %d\n", val);
    printList(l);

    val = pop(l);
    printf("popped = %d\n", val);
    printList(l);

    clear(l);

    return 0;
}