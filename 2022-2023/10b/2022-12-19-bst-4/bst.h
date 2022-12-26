struct node_t {
  int value;
  struct node_t *left;
  struct node_t *right;
};

struct node_t * create_node(int value);
void add(struct node_t *root, int value);
void print_dfs(struct node_t* root, int level);
struct node_t* balance_tree(struct node_t* root);

int find(struct node_t *root, int value);
