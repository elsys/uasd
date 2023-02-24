#include <stdlib.h>

#include "queue.h"

struct queue_t* init_queue() {
	struct queue_t* new_q = malloc(sizeof(struct queue_t));
	
	new_q->head = NULL;
	new_q->tail = NULL;
	
	return new_q;
}

void queue_add(struct queue_t* q, void* value, int priority) {
	struct queue_node_t* new_node = malloc(sizeof(struct queue_node_t));
    new_node->next = NULL;
    new_node->value = value;

    if(q->head == NULL) {
        q->head = q->tail = new_node;
    } else {
        struct queue_node_t* curr = q->head;
        for(; curr->priority < priority && curr != q->tail; curr = curr->next);

        curr->next = new_node;
        if(curr == q->tail)
            q->tail = new_node;
    }
}

void* queue_remove(struct queue_t* q) {
    if(q->head == NULL) return NULL;

    void* val = q->head->value;
    free(q->head);
    q->head = q->head->next;

    return val;
}
