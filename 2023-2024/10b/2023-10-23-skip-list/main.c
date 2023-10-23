#include <stdio.h>
#include <stdlib.h>

struct list_t {
    int value;
    struct list_t* next;
    struct list_t* skip;
};
typedef struct list_t list_t;

list_t* init_list(int value) {
    list_t* list = (list_t*)malloc(sizeof(list_t));

    list->value = value;
    list->next = NULL;
    list->skip = NULL;

    return list;
}

void push_list(list_t* list, int value) {
    if(list->next == NULL) {
        list->next = init_list(value);
    } else {
        push_list(list->next, value);
        if(list->skip != NULL && list->next != NULL && list->next->next != NULL)
            list->skip = list->next->next;
    }
}

int main() {
    list_t* list = init_list(1);
    // list->next = init_list(2);
    // list->next->next = init_list(3);
    // push_list(list, 2);
    // push_list(list, 3);
    
    list_t* head = list;
    for(int i = 2; i < 6; i++) {
        push_list(list, i);
        // head = head->next;
    }

    head = list;
    for(int i = 0; i < 5; i++) {
        printf("list[%d](%p) = %d next=%p skip=%p\n", i, head, head->value, head->next, head->skip);
        head = head->next;
    }

    return 0;
}