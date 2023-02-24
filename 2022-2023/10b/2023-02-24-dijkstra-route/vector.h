struct vector_t {
	void** values;
	int size;
};

void vector_add(struct vector_t* vec, void* value);
void* vector_get(struct vector_t* vec, int index);
struct vector_t* vector_init();
void vector_reverse(struct vector_t* vec);
