struct list_node_t {
    int value;
    struct list_node_t* next;
};

struct list_node_t* create_node(int value) {
    struct list_node_t* new_node = malloc(..);
    new_node->value = value;
    new_node->next = NULL;

    return new_node;
}

struct list_node_t* push_front(struct list_node_t* head, int value) {
    struct list_node_t* new_node = create_node(value);

    new_node->next = head;
    head = new_node;

    return head;
}

struct list_node_t* my_list = ...;
my_list = push_front(my_list, 5);

void push_back(struct list_node_t* head, int value);