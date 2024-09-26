#ifndef DLIST_H
#define DLIST_H
#define HASH_SIZE 8

// Chaining implementation of a hash map
typedef struct EntryNode
{
    char *key;
    void *val;
    struct EntryNode *next;
} EntryNode;

typedef struct HashMap
{
    EntryNode **array;
} HashMap;

EntryNode *init_entry(char *key, void *val);
HashMap *init_hash_map();
int hash(char *key);
void set(HashMap *hash_map, char *key, void *val);
void *get(HashMap *hash_map, char *key);
void setInt(HashMap *hash_map, char *key, int val);
int getInt(HashMap *hash_map, char *key);

#endif