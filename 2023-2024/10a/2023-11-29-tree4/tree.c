#include <stdlib.h>
#include <stdio.h>
// #include "../utils/vector.h"
#include "queue.h"

Node *create_tree_node(int val)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;

    return node;
}

int max(int a, int b)
{
    return a > b ? a : b;
}
int height(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    return root->height;
}

int balanceFactor(Node *tree)
{
    return height(tree->left) - height(tree->right);
}

/*
 В час го направихме малко по-дълъг този код. Така като връщаме самия node накрая може да стане по-кратко
*/
Node *leftRotation(Node *x)
{
    Node *y = x->right;
    Node *T2 = y->left;

    x->right = T2;
    y->left = x;

    x->height = 1 + max(height(x->left), height(x->right));
    y->height = 1 + max(height(y->left), height(y->right));

    return y;
}

/*
     y                               x
    / \     Right Rotation          /  \
   x   T3   - - - - - - - >        T1   y
  / \       < - - - - - - -            / \
 T1  T2
*/
Node *rightRotation(Node *y)
{
    Node *x = y->left;
    Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = 1 + max(height(y->left), height(y->right));
    x->height = 1 + max(height(x->left), height(x->right));

    return x;
}

Node *insert(Node *root, int val)
{
    if (root == NULL)
    {
        return create_tree_node(val);
    }

    if (val < root->val)
    {
        root->left = insert(root->left, val);
    }
    else if (val > root->val)
    {
        root->right = insert(root->right, val);
    }

    root->height = 1 + max(height(root->left), height(root->right));

    // AVL balancing
    int bf = balanceFactor(root);

    if (bf < -1)
    {
        // right subtree has a bigger height
        if (val > root->right->val)
        {
            return leftRotation(root);
        }

        root->right = rightRotation(root->right);
        return leftRotation(root);
    }
    else if (bf > 1)
    {
        // left subtree has bigger height
        if (val < root->left->val)
        {
            return rightRotation(root);
        }

        root->left = leftRotation(root->left);
        return rightRotation(root);
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

    printf("Value: %d Height: %d\n", root->val, root->height);
    printTree2(root->left);
    printTree2(root->right);
}

// търсене в широчина
void BFS(Node *tree)
{
    Queue *queue = init_queue();
    enqueue(queue, tree);

    while (queue->front != NULL)
    {
        Node *front = dequeue(queue);
        printf("Node: %d Height: %d\n", front->val, front->height);

        if (front->left != NULL)
        {
            enqueue(queue, front->left);
        }
        if (front->right)
        {
            enqueue(queue, front->right);
        }
    }
}

int main()
{
    Node *tree = NULL;

    // Начина, по който е направено първото извикване трябва да е с присвояване към tree
    // Или можеше да започнем с Node *tree = create_tree_node(3);
    tree = insert(tree, 3);

    /*
         3
        /  \
       -20  6
         \   \
          -12  10
             \  \
              -5 12
               \  \
                0  15
                    \
                    30
    */

    tree = insert(tree, -20);
    tree = insert(tree, -12);
    tree = insert(tree, -5);
    tree = insert(tree, 0);
    tree = insert(tree, 6);
    tree = insert(tree, 10);
    tree = insert(tree, 12);
    tree = insert(tree, 15);
    tree = insert(tree, 30);
    tree = insert(tree, 123);

    printTree2(tree);
}