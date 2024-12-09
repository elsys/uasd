#include <stdio.h>
#include "tree.h"

Node* flatten(Node* root) {
    if (root->right == NULL && root->left == NULL) {
        return root;
    }
    
    if (root->right == NULL) {
        root->right = root->left;
        root->left = NULL;
    }

    Node* rightEnd = flatten(root->right);

    if (root->left != NULL) {
        Node* leftEnd = flatten(root->left);
        leftEnd->right = root->right;
        root->right = root->left;
    }

    return rightEnd;
}

void preorder(Node* root) {
    if (root == NULL) {
        return;
    }

    printf("%d ", root->val);
    preorder(root->left);
    preorder(root->right);
}

int bstSumR(Node *root, int a, int b) {
    if (root == NULL) {
        return 0;
    }
    /*
        тук имаше един грешен else return. Проблема е че дори да сме извън интервала
        не значи че изцяло трябва да прекратим. Пример:
                10
               /
              5
               \ 
                6
        в интервала [6, 10]
        тръгвайки наляво от 10 не трябва веднага да спираме на 5.
        Реално махайки този else и оставайки нещата така,
        дори не ни трябва другата функцията за намиране на зона,
        в която сме в интервала. Малко безмислено го усложних в час. 

    */

    int sum = 0;
    if (root->val >= a && root->val <= b) {
        sum = root->val;
    }

    if (root->val >= a) {
        sum += bstSumR(root->left, a, b);
    }
    if (root->val <= b) {
        sum += bstSumR(root->right, a, b);
    }

    return sum;
}


// няма нужда от тази
int bstSum(Node *root, int a, int b) {
    Node *start = root;

    while (start != NULL && !(start->val >= a && start->val <= b)) {
        if (start->val < a) {
            start = start->right;
        } else {
            start = start->left;
        }
    }

    int sum = bstSumR(start, a, b);

    return sum;
}

int main() {
    Node *root = create_node(1);
    bst_insert(root, 6);
    bst_insert(root, 10);
    bst_insert(root, 15);
    bst_insert(root, 5);
    bst_insert(root, 8);
    bst_insert(root, 4);

    printf("Sum: %d\n", bstSumR(root, 5, 8));


    // root->left = create_node(2);
    // root->right = create_node(5);
    // root->right->right = create_node(6);
    // root->left->right = create_node(4);
    // root->left->left = create_node(3);

    // preorder(root);
    // flatten(root);

    // printf("\n");
    // Node *it = root;
    // while(it != NULL) {
    //     printf("%d ", it->val);
    //     it = it->right;
    // }


    return 0;
}