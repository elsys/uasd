#include <stdlib.h>

#include "list.h"

list_t* init_list() {
    list_t* list = (list_t*)malloc(sizeof(list_t));

    list->value = 0;
    list->next = NULL;

    return list;
}

void push_list(list_t* list, int value) {
    // list_t* new_node = init_list();
    // new_node->value = value;

    // // list_t* tmp = list;
    // while(list->next != NULL)
    //     list = list->next;

    // list->next = new_node;

    if(list->next == NULL) {
        list->next = init_list();
        list->next->value = value;
    } else {
        push_list(list->next, value);
    }
}

int list_get_at(
    list_t* vec, 
    unsigned int index
    // int* err
) {
    // if(vec->count <= index) {
    //     // return -1;
    //     // *err = 1;
    //     return 0;
    // }

    // // *err = 0;
    // return vec->arr[index];
    return -1;
}