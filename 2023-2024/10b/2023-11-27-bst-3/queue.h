struct queue_t {
    struct q_node_t* head;
    struct q_node_t* tail;
};

struct q_node_t {
    struct q_node_t* next;
    void* value;
};

typedef struct queue_t queue_t;

queue_t* init_queue();
int queue_empty(queue_t* q);
void queue_push(queue_t* q, void* value);
void* queue_pop(queue_t* q);