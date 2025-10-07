#include <stdlib.h>
#include "list.h"

Node* init_node(int val) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->val = val;
    node->next = NULL;
    node->prev = NULL;
    
    return node;
}
LList* init_llist() {
    LList* list = (LList*)malloc(sizeof(LList));
    list->head = NULL;
    list->tail = NULL;
    
    return list;
}

void insertHead(LList* list, int val) {
    Node* new_node = init_node(val);
    new_node->next = list->head;
    
    if (list->head == NULL) {
        list->tail = new_node;
    } else {
        list->head->prev = new_node;
    }
    
    list->head = new_node;
}

int popHead(LList* list) {
    if (list->head == NULL) {
        printf("List already empty");
        exit(1);
    }
    
    Node* currentHead = list->head;
    int res = currentHead->val;
    if (currentHead->next != NULL) {
        currentHead->next->prev = NULL;
    }
    list->head = currentHead->next;
    free(currentHead);
    
    if (list->head == NULL) {
        list->tail = NULL;
    }
    
    return res;
}

void printList(LList* list) {
    Node* it = list->head;
    
    while(it != NULL) {
        printf("%d ", it->val);
        it = it->next;
    }
    printf("\n");
}

void printListReverse(LList* list) {
    Node* it = list->tail;
    
    while(it != NULL) {
        printf("%d ", it->val);
        it = it->prev;
    }
    printf("\n");
}

int getAt(LList* list, int index) {
    Node* it = list->head;
    int currentIndex = 0;
    
    while (it != NULL) {
        if (currentIndex == index) {
            return it->val;
        }
        currentIndex++;
        it = it->next;
    }
    
    printf("Index out of bounds\n");
    exit(1);
}