#include <stdio.h>
#include <stdlib.h>
#include "list.h"


void allSums(Node* current, int currentSum) {
    if (current == NULL) {
        printf("%d\n", currentSum);
        return;
    }
    
    allSums(current->next, currentSum+current->val);
    allSums(current->next, currentSum);
}


int main() {
    LList* list = init_llist();
    insertHead(list, 5);
    insertHead(list, 6);
    insertHead(list, 7);
    printList(list);
    allSums(list->head, 0);


    return 0;
}