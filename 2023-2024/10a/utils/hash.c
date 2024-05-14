#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"

EntryNode *init_entry(char *key, void *val)
{
    EntryNode *entry = (EntryNode *)malloc(sizeof(EntryNode));
    entry->key = key;
    entry->val = val;
    entry->next = NULL;

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

void set(HashMap *hash_map, char *key, void *val)
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

        while (it != NULL)
        {
            if (strcmp(it->key, key) == 0)
            {
                it->val = val;
                // free entry;
                return;
            }

            if (it->next == NULL)
            {
                break;
            }
            it = it->next;
        }

        it->next = entry;
    }
}

void *get(HashMap *hash_map, char *key)
{
    int index = hash(key);

    if (hash_map->array[index] == NULL)
    {
        return NULL;
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

    return NULL;
}