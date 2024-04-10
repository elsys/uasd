#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define HASH_SIZE 8

// Chaining implementation of a hash map
typedef struct EntryNode
{
    char *key;
    int val;
    struct EntryNode *next;
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

void set(HashMap *hash_map, char *key, int val)
{
    int index = hash(key);
    EntryNode *entry = init_entry(key, val);

    if (hash_map->array[index] == NULL)
    {
        hash_map->array[index] = entry;
    }
    else
    {
        EntryNode *it = hash_map->array[index];

        while (it->next != NULL)
        {
            if (strcmp(it->key, key) == 0)
            {
                it->val = val;
                // free entry;
                return;
            }

            it = it->next;
        }

        it->next = entry;
    }
}

int get(HashMap *hash_map, char *key)
{
    int index = hash(key);

    if (hash_map->array[index] == NULL)
    {
        return -1;
    }

    EntryNode *it = hash_map->array[index];

    while (it != NULL)
    {
        if (strcmp(it->key, key) == 0)
        {
            return it->val;
        }
        it = it->next;
    }

    return -1;
}

int main()
{
    HashMap *hash_map = init_hash_map();
    set(hash_map, "age", 23);
    set(hash_map, "ega", 34);

    printf("Age is: %d\n ega: %d", get(hash_map, "age"), get(hash_map, "ega"));
    printf("Doesnt exist: %d\n", get(hash_map, "a"));

    return 0;
}