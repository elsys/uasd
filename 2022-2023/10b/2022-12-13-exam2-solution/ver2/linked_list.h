struct list_node_t {
  struct list_node_t* next;
  struct list_node_t* tail;
  int value;
};

struct list_node_t* push_list(struct list_node_t* head, int value);

int pop_list(struct list_node_t** head);