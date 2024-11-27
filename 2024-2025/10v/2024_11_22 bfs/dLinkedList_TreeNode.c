#include <stdio.h>
#include <stdlib.h>

#include "dLinkedList_TreeNode.h"

Dlist initList() {
    Dlist newList = {
        .head = NULL,
        .tail = NULL,
        .size = 0,
    };
    return newList;
}

ListNode* createListNode(DataType val) {
    ListNode* newListNode = (ListNode*) malloc (sizeof(ListNode));
    if(newListNode == NULL) {
        printf("Couldn't allocate memory for Listnode\n");
        exit(1);
    }
    newListNode->val = val;
    return newListNode;
}

void pushFront(Dlist* list, DataType val) {
    ListNode* newListNode = createListNode(val);

    if(list->size != 0) {
        list->head->prev = newListNode;
    } else {
        list->tail = newListNode;
    }
    newListNode->prev = NULL;
    newListNode->next = list->head;
    list->head = newListNode;

    list->size++;
}
void pushBack(Dlist* list, DataType val) {
    ListNode* newListNode = createListNode(val);

    if(list->size != 0) {
        list->tail->next = newListNode;
    } else {
        list->head = newListNode;
    }
    newListNode->next = NULL;
    newListNode->prev = list->tail;
    list->tail = newListNode;

    list->size++;
}

void pushAt(Dlist* list, DataType val, int idx) {
    if(idx == 0) {
        pushFront(list, val);
        return;
    }
    if(idx == list->size) {
        pushBack(list, val);
        return;
    }
    if(idx < 0 || idx > list->size) {
        printf("Invalid index for pushAt\n");
        return;
    }
    ListNode* newListNode = createListNode(val);

    ListNode* curr = getAt(list, idx - 1);

    newListNode->next = curr->next;
    newListNode->prev = curr;
    curr->next = newListNode;
    newListNode->next->prev = newListNode;
    list->size++;
}

void popFront(Dlist* list) {
    if(list->size == 0) {
        printf("List is empty, can't pop\n");
        return;
    }
    ListNode* temp = list->head;
    list->head = list->head->next;

    if(list->head != NULL) {
        list->head->prev = NULL;
    } else {
        list->tail = NULL;
    }

    free(temp);
    list->size--;
}

void popBack(Dlist* list) {
    if(list->size == 0) {
        printf("List is empty, can't pop\n");
        return;
    }

    ListNode* temp = list->tail; 
    list->tail = list->tail->prev;

    if(list->tail != NULL) {
        list->tail->next = NULL;
    } else {
        list->head = NULL;
    }

    free(temp);
    list->size--;
}

void popAt(Dlist* list, int idx) {
    if(idx == 0) {
        popFront(list);
        return;
    }
    if(idx == list->size - 1) {
        popBack(list);
        return;
    }
    if(idx < 0 || idx > list->size - 1) {
        printf("Invalid index for popAt\n");
        return;
    }

    ListNode* curr = getAt(list, idx);
    curr->next->prev = curr->prev;
    curr->prev->next = curr->next;
    free(curr);
    list->size--;
}

ListNode* getAt(Dlist* list, int idx) {
    ListNode* curr;
    if(idx < list->size/2) {
        curr = list->head;
        for(int i = 0; i < idx; i++) {
            curr = curr->next;
        }
    } else {
        curr = list->tail;
        for(int i = list->size - 1; i > idx; i--) {
            curr = curr->prev;
        }
    }
    return curr;
}

// void printFromHead(Dlist* list) {
//     ListNode* curr = list->head;
//     for(int i = 0; i < list->size; i++) {
//         printf("%d ", curr->val);
//         curr = curr->next;
//     }
//     printf("\n");

// }
// void printFromTail(Dlist* list) {
//     ListNode* curr = list->tail;
//     for(int i = 0; i < list->size; i++) {
//         printf("%d ", curr->val);
//         curr = curr->prev;
//     }
//     printf("\n");
// }

void release(Dlist* list) {
    while(list->size) {
        popFront(list);
    }
}