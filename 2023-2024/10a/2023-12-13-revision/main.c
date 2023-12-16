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

Node *deleteNode(Node *root, int val)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (root->val == val)
    {
        if (root->left == NULL)
        {
            Node *temp = root;
            root = root->right;
            free(temp);
        }
        else if (root->right == NULL)
        {
            Node *temp = root;
            root = root->left;
            free(temp);
        }
        else
        {
            Node *rightIt = root->right;
            while (rightIt->left != NULL)
            {
                rightIt = rightIt->left;
            }

            root->val = rightIt->val;
            root->right = deleteNode(root->right, rightIt->val);
        }

        return root;
    }
    else if (root->val > val)
    {
        root->left = deleteNode(root->left, val);
    }
    else if (root->val < val)
    {
        root->right = deleteNode(root->right, val);
    }

    return root;
}

void preorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    printf("%d ", root->val);
    preorder(root->left);
    preorder(root->right);
}

int max(int a, int b)
{
    return a > b ? a : b;
}
/*
    .
   / \
  t1  t2
*/

int height(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    return 1 + max(height(root->right), height(root->left));
}

Node *flatten(Node *root)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (root->left == NULL && root->right == NULL)
    {
        return root;
    }
    if (root->left == NULL)
    {
        return flatten(root->right);
    }
    if (root->right == NULL)
    {
        root->right = root->left;
        return flatten(root->right);
    }

    Node *leftEnd = flatten(root->left);
    Node *rightEnd = flatten(root->right);

    leftEnd->right = root->right;
    root->right = root->left;
    root->left = NULL;

    return rightEnd;
    /*
           0
          /  \
         1    2
          \    \
           3    4
            \
             5
    */
}

int main()
{
    Node *tree = NULL;

    // Начина, по който е направено първото извикване трябва да е с присвояване към tree
    // Или можеше да започнем с Node *tree = create_node(3);
    tree = insert(tree, 3);

    /*
        3
        /  \
       NULL  6
         \
          -12
             \
              -5
               \
                0
    */

    insert(tree, 10);
    insert(tree, 1);
    insert(tree, 6);
    insert(tree, 12);
    insert(tree, 2);
    insert(tree, -12);
    insert(tree, 30);
    insert(tree, 123);
    insert(tree, 15);
    insert(tree, 0);
    insert(tree, 100);
    insert(tree, 99);
    insert(tree, -45);

    preorder(tree);
    printf("\n ");

    flatten(tree);
    Node *it = tree;
    while (it != NULL)
    {
        printf("%d ", it->val);
        it = it->right;
    }
    printf("\n ");
}