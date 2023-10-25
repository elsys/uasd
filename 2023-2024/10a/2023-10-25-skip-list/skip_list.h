#ifndef SKIP_LISTH
#define SKIP_LISTH

#define MAX_LEVEL 16

typedef struct Node
{
    int value;
    struct Node *next[MAX_LEVEL];
} Node;

typedef struct SkipList
{
    Node *head;
} SkipList;

SkipList *init_list();
void clear(SkipList *list);
void printList(SkipList *list);

void sl_insert(SkipList *list, int val);
Node *sl_search(SkipList *list, int val);
Node *sl_remove(SkipList *list, int val);

#endif