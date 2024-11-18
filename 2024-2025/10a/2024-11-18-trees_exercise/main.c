#include "../utils/tree.h"
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "../utils/queue.h"

int find_min(Node* root) {
    Node* it = root;
    while (it->left != NULL) {
        it = it->left;
    }

    return it->val;
}

int find_max(Node *root) {
    if (root->right == NULL) {
        return root->val;
    } 

    return find_max(root->right);
}

int isBSTR(Node* root, int *prev) {
    if (root == NULL) {
        return 1;
    }

    if (! isBSTR(root->left, prev)) {
        return 0;
    }
    
    if (!(root->val >= *prev)) {
        return 0;
    }
    *prev = root->val;


    if (! isBSTR(root->right, prev)) {
        return 0;
    }

    return 1;
}

int isBST(Node *root) {
    int min = INT_MIN;

    return isBSTR(root, &min); 
}


void BFS(Node *root) {
    Queue *queue = init_queue();

    enqueue(queue, root);

    while (queue->front != NULL) {
        Node* node = dequeue(queue);

        printf("%d ", node->val);

        if (node->left != NULL) {
            enqueue(queue, node->left);
        }
        if (node->right != NULL) {
            enqueue(queue, node->right);        
        }
    }
    printf("\n");

    clear_queue(queue);
}


int main() {
      Node* root = create_node(10);
    bst_insert(root, 5);
    bst_insert(root, 7);
    bst_insert(root, 15);
    bst_insert(root, 30);
    bst_insert(root, 0);
    bst_insert(root, 4);
    bst_insert(root, 26);


    
    // printTree(root);  

    printf("min: %d, max: %d \n", find_min(root), find_max(root));
    
    //root->left->right->val = 20;
    if (isBST(root)) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    BFS(root);
    return 0;
}