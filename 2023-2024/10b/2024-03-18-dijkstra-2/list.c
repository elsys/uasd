#include <stdlib.h>

#include "list.h"

list_t* init_list() {
    list_t* list = (list_t*)malloc(sizeof(list_t));

    list->value = NULL;
    list->next = NULL;

    return list;
}

list_t* push_list(list_t* list, void* value) {
    // List is empty - create new node and return it
    if(list == NULL) {
        list_t* new_head = init_list();
        new_head->value = value;
        return new_head;
    }

    // End of the list - create new node and attach it
    if(list->next == NULL) {
        list->next = push_list(list->next, value);
        return list;
    }

    // Middle of the list - continue recursively to the end
    push_list(list->next, value);
    return list;
}

void* pop_list(list_t** list) {
    if(*list == NULL) {
        return NULL;
    }

    list_t* old_head = *list;

    void* result = (*list)->value;
    *list = (*list)->next;

    free(old_head);

    return result;
}

void* list_get_at(
    list_t* list,
    unsigned int index
) {
    int len = list_length(list);
    if(len < index) return NULL;

    list_t* curr = list;
    int i = 0;

    while(i < index) {
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

void destroy_list(list_t* list) {
    while(list != NULL) {
        list_t* tmp = list;
        list = list->next;

        free(tmp);
    }
}