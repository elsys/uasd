#include "queue.h"
#include <stdlib.h>
#include <stdio.h>

QueueNode *create_node(Node *val)
{
    QueueNode *node = (QueueNode *)malloc(sizeof(QueueNode));
    node->val = val;
    node->next = NULL;

    return node;
}

Queue *init_queue()
{
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;
}

void enqueue(Queue *queue, Node *val)
{
    QueueNode *node = create_node(val);
    if (queue->front == NULL)
    {
        queue->rear = queue->front = node;
        return;
    }

    queue->rear->next = node;
    queue->rear = node;
}

Node *dequeue(Queue *queue)
{
    if (queue->front == NULL)
    {
        printf("Queue is empty.\n");
        exit(1);
    }

    QueueNode *front = queue->front;

    Node *val = front->val;
    QueueNode *tmp = front;
    queue->front = front->next;
    // free(tmp);

    if (queue->front == NULL)
    {
        queue->rear = NULL;
    }

    return val;
}

void clear_queue(Queue *queue)
{
    while (queue->front != NULL)
    {
        dequeue(queue);
    }

    free(queue);
}