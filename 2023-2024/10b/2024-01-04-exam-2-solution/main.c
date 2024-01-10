struct tree_node_t {
    struct tree_node_t* left;
    struct tree_node_t* right;
    struct tree_node_t* parent;

    char dir;
    int x;
    int y;
};

struct tree_node_t* init_node(char d, int x, int y, struct tree_node_t* parent) {
    struct tree_node_t* new_node = malloc(sizeof(struct tree_node_t));
    new_node->left = new_node->right = NULL;

    new_node->parent = parent;
    new_node->dir = d;
    new_node->x = x;
    new_node->y = y;

    return new_node;
}

// ═ 
//   in left -> out right: (x + 1, y), S
//   in right -> out left: (x - 1, y), S
//   0001 -> +1, 0, S
//   0010 -> -1, 0, S
// ╝ 
//   in left -> out top: (    x, y - 1), L
//   in top -> out left: (x - 1, y), R
//   0001 -> 0, -1, L
//   0100 -> -1, 0, R

═
    [
        [1, 0, 'S'],
        [-1, 0, 'S'],
        [],
        []
    ]
╝
    [
        [0, -1, 'L'],
        [],
        [-1, 0, 'R'],
        []
    ]

char* help_santa(char* maze, int start_x, int start_y) {
    struct tree_node_t* root = init_node('-', start_x, start_y, NULL);

    root->left = init_node('L', start_x - 1, start_y, root);
    root->right = init_node('R', start_x + 1, start_y, root);

    struct tree_node_t* curr = root->left;
    char cell = maze[curr->y][curr->x];



}
