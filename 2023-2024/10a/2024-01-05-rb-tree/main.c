#include <stdlib.h>
#include <stdio.h>

typedef enum Color
{
    RED,
    BLACK
} Color;

typedef struct Node
{
    int val;
    Color color;
    struct Node *parent;
    struct Node *left;
    struct Node *right;
} Node;

Node *create_tree_node(int val)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    node->parent = NULL;
    node->color = RED;

    return node;
}

void inorderTraversal(Node *root)
{
    if (root != NULL)
    {
        inorderTraversal(root->left);
        printf("%d(%c) ", root->val, (root->color == BLACK ? 'B' : 'R'));

        inorderTraversal(root->right);
    }
}

void preorder(Node *root)
{
    if (root != NULL)
    {
        printf("%d(%c) ", root->val, (root->color == BLACK ? 'B' : 'R'));
        preorder(root->left);
        preorder(root->right);
    }
}

void leftRotation(Node **root, Node *x)
{
    Node *y = x->right;
    Node *T2 = y->left;

    x->right = T2;
    y->left = x;

    y->parent = x->parent;

    if (x->parent == NULL)
    {
        (*root) = y;
    }
    else if (x->parent->left == x)
    {
        x->parent->left = y;
    }
    else
    {
        x->parent->right = y;
    }

    x->parent = y;

    if (T2 != NULL)
    {
        T2->parent = x;
    }
}

/*
     x                               y
    / \     Right Rotation          /  \
   y   T3   - - - - - - - >        T1   x
  / \       < - - - - - - -            / \
 T1  T2                               T2
*/

void rightRotation(Node **root, Node *y)
{
    Node *x = y->left;
    Node *T2 = x->right;

    y->left = T2;
    x->right = y;

    x->parent = y->parent;

    if (y->parent == NULL)
    {
        (*root) = x;
    }
    else if (y->parent->left == y)
    {
        y->parent->left = x;
    }
    else
    {
        y->parent->right = x;
    }

    y->parent = x;

    if (T2 != NULL)
    {
        T2->parent = y;
    }
}

void treeFixup(Node **root, Node *x)
{
    Node *gp = NULL;
    Node *uncle = NULL;

    while (x != (*root) && x->parent->color == RED)
    {
        gp = x->parent->parent;

        if (gp->left == x->parent)
        {
            uncle = gp->right;

            if (uncle != NULL && uncle->color == RED)
            {
                x->parent->color = BLACK;
                uncle->color = BLACK;
                gp->color = RED;

                x = gp;
            }
            else
            {
                if (x->parent->right == x)
                {
                    x = x->parent;
                    leftRotation(root, x);
                }

                x->parent->color = BLACK;
                gp->color = RED;
                rightRotation(root, gp);
            }
        }
        else
        {
            uncle = gp->left;

            if (uncle != NULL && uncle->color == RED)
            {
                x->parent->color = BLACK;
                uncle->color = BLACK;
                gp->color = RED;

                x = gp;
            }
            else
            {
                if (x->parent->left == x)
                {
                    x = x->parent;
                    rightRotation(root, x);
                }

                x->parent->color = BLACK;
                gp->color = RED;
                leftRotation(root, gp);
            }
        }
    }

    (*root)->color = BLACK;
}

void insert(Node **root, int val)
{
    Node *new_node = create_tree_node(val);
    Node *current = *root;

    if (current == NULL)
    {
        new_node->color = BLACK;
        *root = new_node;
        return;
    }

    while (1)
    {
        if (current->val > val)
        {
            if (current->left == NULL)
            {
                break;
            }
            current = current->left;
        }
        else
        {
            if (current->right == NULL)
            {
                break;
            }
            current = current->right;
        }
    }

    if (current->val > val)
    {
        current->left = new_node;
    }
    else
    {
        current->right = new_node;
    }

    new_node->parent = current;

    treeFixup(root, new_node);
}

int main()
{
    struct Node *root = NULL;

    insert(&root, 7);
    insert(&root, 3);
    insert(&root, 18);
    insert(&root, 18);
    insert(&root, 28);
    insert(&root, 32);
    insert(&root, 52);
    insert(&root, 41);

    inorderTraversal(root);
    printf("\n");
    preorder(root);
    printf("\n");

    // leftRotation(&root, root);
    // preorder(root);
    // printf("\n");

    // rightRotation(&root, root);
    // preorder(root);
    // printf("\n");

    return 0;
}