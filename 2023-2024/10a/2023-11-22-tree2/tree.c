#include <stdlib.h>
#include <stdio.h>
#include "../utils/vector.h"

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

void fillVector(vector_t *v, Node *tree)
{
    if (tree == NULL)
    {
        return;
    }

    fillVector(v, tree->left);
    push_back(v, tree->val);
    fillVector(v, tree->right);
}

Node *buildTreeRec(vector_t *v, int start, int end)
{
    if (start > end)
    {
        return NULL;
    }

    int mid = (start + end) / 2;
    Node *node = create_node(v->arr[mid]);
    node->left = buildTreeRec(v, start, mid - 1);
    node->right = buildTreeRec(v, mid + 1, end);

    return node;
}

Node *buildTree(vector_t *v)
{
    Node *root = NULL;
    root = buildTreeRec(v, 0, v->size - 1);

    return root;
}

/*
Balance factor = Height(T1) - Height(T2)
Bf E [-1, 0, 1]

    .
   / \
  .   .
  /\
 .  .
  \.
*/

void printTree2(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    printf("%d ", root->val);
    printTree2(root->left);
    printTree2(root->right);
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

    insert(tree, -20);
    insert(tree, -12);
    insert(tree, -5);
    insert(tree, 0);
    insert(tree, 6);
    insert(tree, 10);
    insert(tree, 12);
    insert(tree, 15);
    insert(tree, 30);
    insert(tree, 123);

    printTree(tree);
    deleteNode(tree, 0);
    printf("\n");
    printTree(tree);

    vector_t *v = init_vector();       // 1
    fillVector(v, tree);               // n
    Node *balancedTree = buildTree(v); // n   Total: O(n)
    printf("\n");
    printTree(balancedTree);

    printf("\n");
    printTree2(tree);
    printf("\n");
    printTree2(balancedTree);

    printf("Unbalanced height: %d\nBalanced height: %d", height(tree), height(balancedTree));
}