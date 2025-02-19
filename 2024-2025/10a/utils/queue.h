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


QNode *create_qnode(int val);
Queue *init_queue();
void enqueue(Queue *queue, int val);
int dequeue(Queue *queue);
void clear_queue(Queue *queue);
void print_queue(Queue *queue);

#endif