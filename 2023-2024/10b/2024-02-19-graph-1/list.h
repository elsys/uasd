#pragma once

struct list_t {
    struct list_t* next;
    void* value;
};

typedef struct list_t list_t;

list_t* init_list();
void push_list(list_t* vec, void* value);
void* list_get_at(list_t* vec, unsigned int index);