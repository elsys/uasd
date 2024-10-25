#include "list.h"
#include <stdio.h>

int main () {
    LList* l = init_llist();
    insertEnd(l, 1);
    insertEnd(l, 2);
    insertEnd(l, 3);

    printList(l);

    int headVal = popBegin(l);
    printf("Head: %d\n", headVal);
    printList(l);

    printf("At 1: %d\n", getAt(l, 1)->val);

    freeList(l);


    return 0;
}