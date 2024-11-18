#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

QNode *create_qnode(Node* val)
{
    QNode *node = (QNode *)malloc(sizeof(QNode));
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

void enqueue(Queue *queue, Node* val)
{
    QNode *node = create_qnode(val);
    if (queue->front == NULL)
    {
        queue->rear = queue->front = node;
        return;
    }

    queue->rear->next = node;
    queue->rear = node;
}

Node* dequeue(Queue *queue)
{
    if (queue->front == NULL)
    {
        printf("Queue is empty.\n");
        exit(1);
    }

    QNode *front = queue->front;

    Node* val = front->val;
    QNode *tmp = front;
    queue->front = front->next;
    free(tmp);

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
void print_queue(Queue *queue)
{
    QNode *it = queue->front;
    printf("Q: ");
    while (it != NULL)
    {
        printf("%d -> ", it->val->val);
        it = it->next;
    }
    printf("NULL\n");
}