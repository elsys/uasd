#include <stdio.h>
#include <stdlib.h>

#define HASH_SIZE 8

typedef struct EntryNode
{
    char *key;
    int val;
} EntryNode;

typedef struct HashMap
{
    EntryNode **array;
} HashMap;

EntryNode *init_entry(char *key, int val)
{
    EntryNode *entry = (EntryNode *)malloc(sizeof(EntryNode));
    entry->key = key;
    entry->val = val;

    return entry;
}

HashMap *init_hash_map()
{
    HashMap *map = (HashMap *)malloc(sizeof(HashMap));
    map->array = (EntryNode **)calloc(HASH_SIZE, sizeof(EntryNode *));

    return map;
}

int hash(char *key)
{
    int sum = 0;
    for (int i = 0; key[i] != '\0'; i++)
    {
        sum += key[i];
    }

    return sum % HASH_SIZE;
}

void insert(HashMap *hash_map, char *key, int val)
{
    int index = hash(key);
    EntryNode *entry = init_entry(key, val);

    hash_map->array[index] = entry;
}

int get(HashMap *hash_map, char *key)
{
    int index = hash(key);

    if (hash_map->array[index] == NULL)
    {
        return -1;
    }

    return hash_map->array[index]->val;
}

int main()
{
    HashMap *hash_map = init_hash_map();
    insert(hash_map, "age", 23);
    insert(hash_map, "ega", 34);

    printf("Age is: %d\n", get(hash_map, "age"));
    printf("Doesnt exist: %d\n", get(hash_map, "a"));

    return 0;
}