#include<stdio.h>
#include "dLinkedList.h"

int main() {
    Dlist myList = initList();
    pushBack(&myList, 1);
    pushBack(&myList, 2);
    pushBack(&myList, 3);
    pushBack(&myList, 4);
    pushBack(&myList, 5);
    printf("%d\n", getAt(&myList, 3)->val);
    pushAt(&myList, 10, 3);
    popAt(&myList, 3);
    printFromHead(&myList);
    popBack(&myList);
    popBack(&myList);
    popBack(&myList);
    popBack(&myList);
    popBack(&myList);
    printFromHead(&myList);
}