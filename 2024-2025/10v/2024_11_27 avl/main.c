#include<stdio.h>
#include<stdlib.h>

#include "avlTree.h"

struct Queue {
    void* top;
    struct Queue* next;
};
typedef struct Queue Queue;

Queue* createQueueNode(void* value) {
    Queue* new_node = malloc(sizeof(Queue));
    new_node->top = value;
    new_node->next = NULL;

    return new_node;
}

Queue* queuePush(Queue* q, void* value) {
    Queue* newNode = createQueueNode(value);

    if(!q) {
        return newNode;
    }

    Queue* curr = q;
    while(curr->next) {
        curr = curr->next;
    }
    curr->next = newNode;

    return q;
}

void* queuePop(Queue** q) {
    if(!(*q)) {
        return NULL;
    }
    void* value = (*q)->top;

    Queue* temp = *q;
    (*q) = (*q)->next;
    free(temp);

    return value;
}

void printTreeBfs(AVLNode* root) {
    if (!root) {
        return;
    }

    Queue* q = createQueueNode(root);
    while(q) {
        AVLNode* curr = queuePop(&q);
        if(!curr) {
            continue;
        }

        printf("%d ", curr->val);
        q = queuePush(q, curr->left);
        q = queuePush(q, curr->right);
    }
}


int main() {
    AVLNode* root = createNode(12);
    root = insert(root, 8);
    root = insert(root, 5);
    root = insert(root, 4);
    root = insert(root, 11);
    root = insert(root, 18);
    root = insert(root, 17);

    // printInOrder(root);
    printTreeBfs(root);
}