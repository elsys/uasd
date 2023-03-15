struct queue_node_t {
    struct queue_node_t* next;
    void* value;
    int priority;
};

struct queue_t {
    struct queue_node_t* head;
    struct queue_node_t* tail;
};

struct queue_t* init_queue();
void queue_add(struct queue_t* q, void* value);
void* queue_remove(struct queue_t* q);