#include <stdlib.h>
#include <string.h>
#include "hashmap.h"
#define HASHMAP_SIZE 16

EntryNode* init_entry(char* key, void* val) {
    EntryNode* entry = (EntryNode*)malloc(sizeof(EntryNode));
    entry->key = strdup(key);
    entry->val = val;
    entry->next = NULL;

    return entry;
}

HashMap* init_hashmap() {
    HashMap* hashmap = (HashMap*)malloc(sizeof(HashMap));
    hashmap->entries = (EntryNode**)calloc(HASHMAP_SIZE, sizeof(EntryNode*));

    return hashmap;
}

int hash(char* key) {
    int sum = 0;
    for (int i = 0; i < strlen(key); i++) {
        sum += key[i];
    }

    return sum % HASHMAP_SIZE;
}

void* get(HashMap* hashmap, char* key) {
    int index = hash(key);

    EntryNode* it = hashmap->entries[index];
    while(it != NULL) {
        if (!strcmp(it->key, key)) {
            return it->val;
        }
        it = it->next;
    }

    return -1;
}

void set(HashMap* hashmap, char* key, void* val) {
    int index = hash(key);

    EntryNode* entry = init_entry(key, val);
    EntryNode* it = hashmap->entries[index];

    while(it != NULL) {
        if (!strcmp(it->key, key)) {
            it->val = val;
            return;
        }

        it = it->next;
    }

    entry->next = hashmap->entries[index];
    hashmap->entries[index] = entry;
}