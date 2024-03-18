#pragma once

struct list_t {
    struct list_t* next;
    void* value;
};

typedef struct list_t list_t;

list_t* init_list();

list_t* push_list(list_t* list, void* value);
void* pop_list(list_t** list);

void* list_get_at(list_t* list, unsigned int index);
int list_length(list_t* list);

void destroy_list(list_t* list);