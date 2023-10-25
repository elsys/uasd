#include "skip_list.h"
#include <stdio.h>
#include <stdlib.h>

Node *create_node(int val)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->value = val;

    for (int i = 0; i < MAX_LEVEL; i++)
    {
        node->next[i] = NULL;
    }

    return node;
}

SkipList *init_list()
{
    Node *head = create_node(0);
    SkipList *list = (SkipList *)malloc(sizeof(SkipList));
    list->head = head;

    return list;
}

void clear(SkipList *list)
{
    Node *it = list->head;
    while (it != NULL)
    {
        Node *tmp = it;
        it = it->next[0];
        free(tmp);
    }

    free(list);
}

void printList(SkipList *list)
{
    for (int i = 0; i < MAX_LEVEL; i++)
    {
        Node *it = list->head;
        printf("%d H -> ", i);
        while (it != NULL)
        {
            it = it->next[i];
            if (it != NULL)
            {
                printf("%d -> ", it->value);
            }
        }
        printf("NULL\n");
    }
}

void sl_insert(SkipList *list, int val)
{
    Node *it[MAX_LEVEL] = {0};
    it[MAX_LEVEL - 1] = list->head;
    for (int i = MAX_LEVEL - 1; i >= 0; i--)
    {
        while (it[i]->next[i] != NULL && it[i]->next[i]->value < val)
        {
            it[i] = it[i]->next[i];
        }
        it[i - 1] = it[i];
    }

    Node *newNode = create_node(val);
    int connectLayer = 0;

    do
    {
        newNode->next[connectLayer] = it[connectLayer]->next[connectLayer];
        it[connectLayer]->next[connectLayer] = newNode;
        connectLayer++;
    } while (rand() < RAND_MAX / 2 && connectLayer < MAX_LEVEL);
}

Node *sl_search(SkipList *list, int val);
Node *sl_remove(SkipList *list, int val);
