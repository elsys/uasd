struct huffman_node {
  char c;
  int freq;
  char code;
};

list_t* count_frequency(const char *input) {
  list_t* chars = list_create();
  for (int i = 0; i < strlen(input); i++) {
    char c = input[i];
    struct huffman_node* node = list_find(chars, c);
    if(node != NULL) {
      node->freq++;
    } else {
      node = malloc(sizeof(struct huffman_node));
      node->c = c;
      node->freq = 1;
      node->code = 0;
      list_add(chars, node);
    }
  }
  return chars;
}

tree_node_t* build_huffman_tree(list_t* chars) {
  queue_t* queue = queue_create();
  for (int i = 0; i < chars->size; i++) {
    struct huffman_node* node = list_get(chars, i);
    queue_enqueue(queue, node);
  }

  while(queue->size > 1) {
    struct huffman_node* left = queue_dequeue(queue);
    struct huffman_node* right = queue_dequeue(queue);
    struct huffman_node* parent = malloc(sizeof(struct huffman_node));
    parent->c = 0;
    parent->freq = left->freq + right->freq;
    parent->code = 0;
    tree_node_t* parent_node = malloc(sizeof(tree_node_t));
    parent_node->data = parent;
    parent_node->left = left;
    parent_node->right = right;
    queue_enqueue(queue, parent);
  }

  tree_node_t* root = queue_dequeue(queue);
  return root;
}

list_t* generate_codes(tree_node_t* root) {
  list_t* codes = list_create();
  queue_t* queue = queue_create();
  queue_enqueue(queue, root);

  while(queue->size) {
    tree_node_t* node = queue_dequeue(queue);

    if(node->left != NULL) {
      node->left->data->code = node->data->code << 1;
      queue_enqueue(queue, node->left);
    }
    if(node->right != NULL) {
      node->right->data->code = (node->data->code << 1) | 1;
      queue_enqueue(queue, node->right);
    }

    // if(node->data->c != 0) {
    if(node->left == NULL && node->right == NULL) {
      list_add(codes, node->data);
    }
  }

  return codes;
}

char* encode(const char *input, list_t* codes) {
  char* encoded = malloc(strlen(input) * 2); // Allocate enough space for the encoded string
  int index = 0;
  for (int i = 0; i < strlen(input); i++) {
    struct huffman_node* node = list_find(codes, input[i]);

    // encoded[i] = node->code;
    char code = node->code;
    while(code != 0) {
      encoded[index] << 1;
      encoded[index] |= (code & 1);
      code >>= 1;
    }
  }

  return encoded;
}

char* huffman_encode(const char *input) {
  list_t* chars = count_frequency(input);
  tree_node_t* tree = build_huffman_tree(chars);
  list_t* codes = generate_codes(tree);
  return encode(input, codes);
}


int main() {
  return 0;
}