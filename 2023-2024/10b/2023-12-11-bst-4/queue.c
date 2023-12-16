#include <stdlib.h>

#include "queue.h"

queue_t* init_queue() {
    queue_t* q = (queue_t*)malloc(sizeof(queue_t));

    q->head = q->tail = NULL;

    return q;
}

int queue_empty(queue_t* q) {
    return q->head == NULL;
}

void queue_push(queue_t* q, void* value) {
    struct q_node_t* new_node = malloc(sizeof(struct q_node_t));
    new_node->next = NULL;
    new_node->value = value;

    if(q->tail != NULL) {
      q->tail->next = new_node;
      q->tail = new_node;
    } else {
        q->head = q->tail = new_node;
    }
}

void* queue_pop(queue_t* q) {
    void* value = q->head->value;
    struct q_node_t* old_head = q->head;

    q->head = q->head->next;
    if(q->head == NULL)
        q->tail = NULL;

    free(old_head);
    // old_head = NULL;

    return value;
}