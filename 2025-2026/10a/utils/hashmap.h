#ifndef HASHMAP_H
#define HASHMAP_H 

#define HASH_MAP_SIZE 16

typedef struct EntryNode {
    char* key;
    void* val;
    struct EntryNode* next;
} EntryNode;                       
 
typedef struct HashMap {
    EntryNode** arr;
} HashMap;
 
HashMap* init_hashmap();
 
EntryNode* init_entry(char* key, void* val);
int hash(char* key);
void set(HashMap* map, char* key, void* val);
void* get(HashMap* map, char* key);
void setInt(HashMap* map, char* key, int val);
int getInt(HashMap* map, char* key);

#endif