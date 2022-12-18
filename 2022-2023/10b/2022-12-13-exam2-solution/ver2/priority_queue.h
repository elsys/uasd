struct priority_queue_t {
  struct list_node_t** subqueues;
  int size;
};

struct priority_queue_t* init_queue();

void push_queue(struct priority_queue_t* q, int value, int priority);

int pop_queue(struct priority_queue_t* q);

void print_queue(struct priority_queue_t* q);