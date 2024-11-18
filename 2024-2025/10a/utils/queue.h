#ifndef QUEUE_H
#define QUEUE_H

#include "tree.h"

typedef struct QNode
{
    Node* val;
    struct QNode *next;
} QNode;

typedef struct Queue
{
    QNode *front;
    QNode *rear;
} Queue;


QNode *create_qnode(Node* val);
Queue *init_queue();
void enqueue(Queue *queue, Node* val);
Node* dequeue(Queue *queue);
void clear_queue(Queue *queue);
void print_queue(Queue *queue);

#endif