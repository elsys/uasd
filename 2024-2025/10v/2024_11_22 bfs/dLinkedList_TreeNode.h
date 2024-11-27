#ifndef DLIST_H
#define DLIST_H

struct TreeNode {
    struct TreeNode* left;
    struct TreeNode* right;
    int val;
};

typedef struct TreeNode TreeNode;

typedef TreeNode* DataType;

struct ListNode {
    struct ListNode* next;
    struct ListNode* prev;
    DataType val;
};

typedef struct ListNode ListNode;

typedef struct Dlist {
    struct ListNode* head;
    struct ListNode* tail;
    int size;
} Dlist;

Dlist initList();

ListNode* createListNode(DataType val);

void pushFront(Dlist* list, DataType val);
void pushBack(Dlist* list, DataType val);
void pushAt(Dlist* list, DataType val, int idx);

void popFront(Dlist* list);
void popBack(Dlist* list);
void popAt(Dlist* list, int idx);

ListNode* getAt(Dlist* list, int idx);

void printFromHead(Dlist* list);
void printFromTail(Dlist* list);

void release(Dlist* list);

#endif