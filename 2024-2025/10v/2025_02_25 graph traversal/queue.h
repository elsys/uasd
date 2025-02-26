#ifndef QUEUE_H
#define QUEUE_H

typedef struct QNode
{
    int val;
    struct QNode *next;
} QNode;

typedef struct Queue
{
    QNode *front;
    QNode *rear;
} Queue;


QNode* createQnode(int val);
Queue* initQueue();
int isEmpty(Queue* queue);
void push(Queue* queue, int val);
int pop(Queue* queue);
void clearQueue(Queue* queue);
void printQueue(Queue* queue);

#endif