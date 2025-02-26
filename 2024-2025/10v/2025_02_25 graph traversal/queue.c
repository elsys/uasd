#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

QNode* createQnode(int val) {
    QNode* node = (QNode* )malloc(sizeof(QNode));
    node->val = val;
    node->next = NULL;

    return node;
}

Queue* initQueue() {
    Queue* queue = (Queue* )malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;
}

int isEmpty(Queue* queue) {
    if(queue->front) {
        return 1;
    }
    return 0;
}

void push(Queue* queue, int val) {
    QNode* node = createQnode(val);
    if (queue->front == NULL) {
        queue->rear = queue->front = node;
        return;
    }

    queue->rear->next = node;
    queue->rear = node;
}

int pop(Queue* queue) {
    if (!queue->front) {
        printf("Queue is empty.\n");
        exit(1);
    }

    QNode* front = queue->front;

    int val = front->val;
    QNode* tmp = front;
    queue->front = front->next;
    free(tmp);

    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    return val;
}

void clearQueue(Queue* queue) {
    while (queue->front != NULL) {
        pop(queue);
    }

    free(queue);
}

void printQueue(Queue* queue) {
    QNode* it = queue->front;
    printf("Q: ");
    while (it != NULL) {
        printf("%d -> ", it->val);
        it = it->next;
    }
    printf("NULL\n");
}