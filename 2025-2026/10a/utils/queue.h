#ifndef QUEUE_H
#define QUEUE_H

typedef struct Node
{
    int val;
    struct Node *next;
} Node;

typedef struct Queue
{
    Node *front;
    Node *rear;
} Queue;

Node *create_node(int val);
Queue *init_queue();
void enqueue(Queue *queue, int val);
int dequeue(Queue *queue);
void clear_queue(Queue *queue);
void print_queue(Queue *queue);

#endif