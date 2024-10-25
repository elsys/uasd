#ifndef SKIPLIST_H
#define SKIPLIST_H

#define MAX_LEVEL 4

struct Node {
    int val;
    struct Node* next[MAX_LEVEL];
};

typedef struct Node Node;
Node* createNode(int val);

typedef struct SkipList {
    Node* head;
} SkipList;

SkipList init();
void insert(SkipList* list, int val);
void printList(SkipList* list);

void release(SkipList* list);


#endif