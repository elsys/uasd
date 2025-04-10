#include <stdlib.h>
#include "hashmap.h"
#define HASHMAP_SIZE 16

EntryNode* init_entry(char* key, int val) {
    EntryNode* entry = (EntryNode*)malloc(sizeof(EntryNode));
    entry->key = strdup(key);
    entry->val = val;
    entry->next = NULL;

    return entry;
}

HashMap* init_hashmap() {
    HashMap* hashmap = (HashMap*)malloc(sizeof(HashMap));
    hashmap->entries = (EntryNode**)calloc(sizeof(EntryNode*), HASHMAP_SIZE);

    return hashmap;
}

int hash(char* key) {
    int sum = 0;
    for (int i = 0; i < strlen(key); i++) {
        sum += key[i];
    }

    return sum % HASHMAP_SIZE;
}

int get(HashMap* hashmap, char* key) {
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

void set(HashMap* hashmap, char* key, int val) {
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