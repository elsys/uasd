#pragma once

struct queue_t {
    void** nodes;
    int size;
    int (*compare)(void*, void*);
};

typedef struct queue_t queue_t;

queue_t* priority_queue(int (*compare)(void*, void*)) {
    queue_t* q = malloc(sizeof(queue_t));
    q->nodes = NULL;
    q->size = 0;
    q->compare = compare;

    return q;
}

void push_queue(queue_t* q, void* value) {
    q->size++;
    q->nodes = realloc(q->nodes, q->size * sizeof(void*));
    q->nodes[q->size-1] = value;
}

void* pop_queue(queue_t* q) {
    int smallest_index = 0;

    for(int i = 1; i < q->size; i++)
        if(q->compare(
            q->nodes[i],
            q->nodes[smallest_index]
        ) < 0)
            smallest_index = i;

    void* value = q->nodes[smallest_index];

    for(int i = smallest_index + 1; i < q->size; i++)
        q->nodes[i-1] = q->nodes[i];

    q->size--;

    return value;
}

// int a = 5;
// int* b = &a;
// int *c = &a;
// int* d, e, f;
// int *d, e, f;

// void a() {}
// void (*b)() = &a;

// int c(int a1, char a2) {}
// int (*d)(int, char) = c;