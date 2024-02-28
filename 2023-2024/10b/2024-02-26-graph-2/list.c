#include <stdlib.h>

#include "list.h"

list_t* init_list() {
    list_t* list = (list_t*)malloc(sizeof(list_t));

    list->value = NULL;
    list->next = NULL;

    return list;
}

void push_list(list_t* list, void* value) {
    if(list->next == NULL) {
        list->next = init_list();
        list->next->value = value;
    } else {
        push_list(list->next, value);
    }
}

void* list_get_at(
    list_t* list, 
    unsigned int index
) {
    list_t* curr = list;
    int i = 0;

    while(i<index) {
        curr = curr->next;
        i++;
    }

    return curr->value;
}

int list_length(list_t* list) {
    int count = 0;
    while(list != NULL) {
        count++;
        list = list->next;
    }

    return count;
}