// Implement queue as a single linked list
struct priority_queue_t {
  struct priority_queue_t* next;
  int value;
  int priority;
};

struct priority_queue_t* push(struct priority_queue_t* head, int value, int priority);

int pop(struct priority_queue_t** head);

void print_queue(struct priority_queue_t* head);
