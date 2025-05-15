#ifndef _HASHMAP_H_
#define _HASHMAP_H_

#define HASHMAP_SIZE 16

typedef struct EntryNode {
    char* key;
    void* val;
    struct EntryNode* next;
} EntryNode;

EntryNode* init_entry(char* key, void* val);
typedef struct HashMap {
    EntryNode** entries;
} HashMap;

HashMap* init_hashmap();
int hash(char* key);
void* get(HashMap* hashmap, char* key);
void set(HashMap* hashmap, char* key, void* val);
#endif