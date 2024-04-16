#include <stdlib.h>
#include <string.h>

#include "map.h"
#include "list.h"

map_t* init_map(unsigned int size) {
    map_t* new_map = malloc(sizeof(map_t));

    new_map->size = 0;
    new_map->hash_arr_size = size;
    // new_map->hash_arr = malloc(size * struct list_t*);
    new_map->hash_arr = calloc(sizeof(struct list_t*), size);

    return new_map;
}

unsigned int hash_func(char* key) {
    unsigned int hash = 0;
    for(int i = 0; i < strlen(key); i++) hash += key[i];
    return hash;
}

int map_has_key(map_t* map, char* key) {
  // key -> hash  
  // hash_arr[hash] ?
  // hash_arr[hash] has key ?
  unsigned int hash = hash_func(key);

  if(map->hash_arr[hash] == NULL) return 0;

  struct list_t* list = map->hash_arr[hash];
  while(list != NULL) {
    struct map_node_t* kvp = list->value;
    if(strcmp(kvp->key, key) == 0) return 1;

    list = list->next;
  }

  return 0;
}

void map_add(map_t* map, char* key, void* value) {
  unsigned int hash = hash_func(key);

  if(map->hash_arr[hash] == NULL) {
    map->hash_arr[hash] = init_list();
  }

  struct list_t* list = map->hash_arr[hash];
  while(list != NULL) {
    struct map_node_t* kvp = list->value;
    if(strcmp(kvp->key, key) == 0) {
        kvp->value = value;
        return;
    }

    list = list->next;
  }

  struct map_node_t* new_kvp = malloc(sizeof(struct map_node_t));
  new_kvp->key = key;
  new_kvp->value = value;

  push_list(list, new_kvp);
}

void map_remove(map_t* map, char* key);
void* map_get(map_t* map, char* key);