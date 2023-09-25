struct vector_t {
    int* arr;
    unsigned int count;
};

typedef struct vector_t vector_t;

vector_t* init_vector();
void push_vector(vector_t* vec, int value);
int vector_get_at(vector_t* vec, unsigned int index);