struct list_node_t {
  int value;
  struct list_node_t *next;
};

void print_list(struct list_node_t *head);
struct list_node_t * push_front(struct list_node_t *head, int new_value);
struct list_node_t * push_back(struct list_node_t *head, int new_value);