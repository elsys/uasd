#include<stdio.h>
#include<stdlib.h>
#include "set.h"

#define INITAL_CAPACITY 16

Set* initSet() {
    Set* newSet = (Set*)malloc(sizeof(Set));
    newSet->size = 0;
    newSet->capacity = INITAL_CAPACITY;
    newSet->data = (int*)malloc(sizeof(int) * INITAL_CAPACITY);
    return newSet;
}

int setContains(Set* set, int val) {
    for(int i = 0; i < set->size; i++) {
        if(set->data[i] == val) {
            return 1;
        }
    }
    return 0;
}

void setAdd(Set* set, int val) {
    if(setContains(set, val)) {
        return;
    }
    if(set->size >= set->capacity) {
        set->capacity*=2;
        set->data = realloc(set->data, sizeof(int) * set->capacity);
        if(!set->data) {
            exit(1);
        }
    }
    set->data[set->size] = val;
    set->size++;
}

void printSet(Set* set) {
    for(int i = 0; i < set->size; i++) {
        printf("%d ", set->data[i]);
    }
    printf("\n");
}