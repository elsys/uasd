#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "hashmap.h"
 
HashMap* init_hashmap() {
    HashMap* map = (HashMap*)malloc(sizeof(HashMap));
    map->arr = (EntryNode**)malloc(sizeof(EntryNode*)*HASH_MAP_SIZE);
    for (int i = 0; i < HASH_MAP_SIZE; i++) {
        map->arr[i] = NULL;
    }
 
    return map;    
}
 
EntryNode* init_entry(char* key, void* val) {
    EntryNode* entry = (EntryNode*)malloc(sizeof(EntryNode));
    entry->key = key;
    entry->val = val;
 
    return entry;
}
 
int hash(char* key) {
    int sum = 0;
    for (int i = 0; i < strlen(key); i++) {
        sum += key[i];
    }
    return sum % HASH_MAP_SIZE;
}
 
void set(HashMap* map, char* key, void* val) {
    EntryNode* map_entry = map->arr[hash(key)];
    EntryNode* it = map_entry;
 
    while (it != NULL) {
        if (strcmp(key, it->key) == 0) {
            it->val = val;
            return;
        }   
 
        it = it->next;
    }
    EntryNode* new_entry = init_entry(key, val);
    new_entry->next = map_entry;
    map->arr[hash(key)] = new_entry;
}
 
void* get(HashMap* map, char* key) {
    EntryNode* it = map->arr[hash(key)];
 
    while (it != NULL) {
        if (strcmp(key, it->key) == 0) {
            return it->val;
        }   
 
        it = it->next;
    }
 
    return NULL;
}

void setInt(HashMap* map, char* key, int val) {
    int* val_ptr = (int*)malloc(sizeof(int));
    *val_ptr = val;
    set(map, key, val_ptr);
}

int getInt(HashMap* map, char* key) {
    int* val_ptr = (int*)get(map, key);
    if (val_ptr == NULL) {
        return 0; // or some other default value
    }
    return *val_ptr;
}
