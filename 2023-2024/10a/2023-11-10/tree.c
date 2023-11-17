#include <stdlib.h>

typedef struct Node
{
    int val;
    Node *left;
    Node *right;
} Node;

Node *create_node(int val)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->val = val;
    node->left = NULL;
    node->right = NULL;

    return node;
}