#include <stdio.h>
#include <stdlib.h>

#include "dLinkedList.h"

Dlist initList() {
    Dlist newList = {
        .head = NULL,
        .tail = NULL,
        .size = 0,
    };
    return newList;
}

Node* createNode(int val) {
    Node* newNode = (Node*) malloc (sizeof(Node));
    if(newNode == NULL) {
        printf("Couldn't allocate memory for node\n");
        exit(1);
    }
    newNode->val = val;
    return newNode;
}

void pushFront(Dlist* list, int val) {
    Node* newNode = createNode(val);

    if(list->size != 0) {
        list->head->prev = newNode;
    } else {
        list->tail = newNode;
    }
    newNode->prev = NULL;
    newNode->next = list->head;
    list->head = newNode;

    list->size++;
}
void pushBack(Dlist* list, int val) {
    Node* newNode = createNode(val);

    if(list->size != 0) {
        list->tail->next = newNode;
    } else {
        list->head = newNode;
    }
    newNode->next = NULL;
    newNode->prev = list->tail;
    list->tail = newNode;

    list->size++;
}

void pushAt(Dlist* list, int val, int idx) {
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
    Node* newNode = createNode(val);

    Node* curr = getAt(list, idx - 1);

    newNode->next = curr->next;
    newNode->prev = curr;
    curr->next = newNode;
    newNode->next->prev = newNode;
    list->size++;
}

void popFront(Dlist* list) {
    if(list->size == 0) {
        printf("List is empty, can't pop\n");
        return;
    }
    Node* temp = list->head;
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

    Node* temp = list->tail; 
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

    Node* curr = getAt(list, idx);
    curr->next->prev = curr->prev;
    curr->prev->next = curr->next;
    free(curr);
    list->size--;
}

Node* getAt(Dlist* list, int idx) {
    Node* curr;
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

void printFromHead(Dlist* list) {
    Node* curr = list->head;
    for(int i = 0; i < list->size; i++) {
        printf("%d ", curr->val);
        curr = curr->next;
    }
    printf("\n");

}
void printFromTail(Dlist* list) {
    Node* curr = list->tail;
    for(int i = 0; i < list->size; i++) {
        printf("%d ", curr->val);
        curr = curr->prev;
    }
    printf("\n");
}

void release(Dlist* list) {
    while(list->size) {
        popFront(list);
    }
}