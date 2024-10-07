#include "list.h"
#include <stdio.h>

int main () {
    LList* l = init_llist();
    insertBegin(l, 1);
    insertBegin(l, 2);
    insertBegin(l, 3);

    printList(l);

    int headVal = popBegin(l);
    printf("Head: %d\n", headVal);
    printList(l);

    printf("At 1: %d\n", getAt(l, 1)->val);

    freeList(l);


    return 0;
}