struct list_t {
    list_t* next;
    int value;
};

typedef struct list_t list_t;

list_t* init_list();
void push_list(list_t* vec, int value);
int list_get_at(list_t* vec, unsigned int index);