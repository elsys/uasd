#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "skiplist.h"

int main() {
    srand(time(NULL));
    SkipList myList = init();

    insert(&myList, 1);
    insert(&myList, 1);
    insert(&myList, 3);
    insert(&myList, 5);
    insert(&myList, 8);
    insert(&myList, 10);
    insert(&myList, 15);
    printList(&myList);
    insert(&myList, 6);
    printf("\n\n\n");
    printList(&myList);

    release(&myList);
}