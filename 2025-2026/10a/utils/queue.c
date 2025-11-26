#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

Node *create_node(int val)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->val = val;
    node->next = NULL;

    return node;
}

Queue *init_queue()
{
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;

    return queue;
}

void enqueue(Queue *queue, int val)
{
    Node* new_node = create_node(val);
    if (queue->rear == NULL) {
        queue->front = new_node;
    } else {
        queue->rear->next = new_node;
    }
    queue->rear = new_node;
}

int dequeue(Queue *queue)
{
    if (queue->front == NULL) {
        printf("Empty queue\n");
        exit(1);
    }

    Node* front = queue->front;
    int res = front->val;

    queue->front = queue->front->next;

    if(queue->front == NULL) {
        queue->rear = NULL;
    }

    free(front);
    return res;
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
    Node *it = queue->front;
    printf("Q: ");
    while (it != NULL)
    {
        printf("%d -> ", it->val);
        it = it->next;
    }
    printf("NULL\n");
}