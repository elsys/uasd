#pragma once

struct map_t {
    struct list_t** hash_arr;
    unsigned int hash_arr_size;
    unsigned int size;
};

struct map_node_t {
    char* key;
    void* value;
};

typedef struct map_t map_t;

map_t* init_map(unsigned int size);

int map_has_key(map_t* map, char* key);

void map_add(map_t* map, char* key, void* value);
void map_remove(map_t* map, char* key);
void* map_get(map_t* map, char* key);