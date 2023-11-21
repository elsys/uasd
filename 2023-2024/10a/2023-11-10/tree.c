#include <stdlib.h>
#include <stdio.h>

typedef struct Node
{
    int val;
    struct Node *left;
    struct Node *right;
} Node;

Node *create_node(int val)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->val = val;
    node->left = NULL;
    node->right = NULL;

    return node;
}

/*
 В час го направихме малко по-дълъг този код. Така като връщаме самия node накрая може да стане по-кратко
*/
Node *insert(Node *root, int val)
{
    if (root == NULL)
    {
        return create_node(val);
    }

    if (val < root->val)
    {
        root->left = insert(root->left, val);
    }
    else if (val > root->val)
    {
        root->right = insert(root->right, val);
    }

    return root;
}

void printTree(Node *root)
{
    // in order
    if (root == NULL)
    {
        return;
    }

    printTree(root->left);
    printf("%d ", root->val);
    printTree(root->right);
}

int main()
{
    Node *tree = NULL;

    // Начина, по който е направено първото извикване трябва да е с присвояване към tree
    // Или можеше да започнем с Node *tree = create_node(3);
    tree = insert(tree, 3);

    insert(tree, 12);
    insert(tree, 10);
    insert(tree, 0);
    insert(tree, -12);
    insert(tree, 123);
    insert(tree, 6);
    insert(tree, 15);
    insert(tree, 30);
    insert(tree, -20);
    insert(tree, -5);

    printTree(tree);
}