#include<stdio.h>
#include<stdlib.h>
#include "./stack/stack.h"

//Zad 1
struct Node {
    int val;
    struct Node* left;
    struct Node* right;
};

typedef struct Node Node;

Node* create_node(int val) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* bst_insert(Node* node, int val) {
    if(!node) {
        return create_node(val);
    }
    if(val < node->val) {
        node->left = bst_insert(node->left, val);
    } else if(val > node->val) {
        node->right = bst_insert(node->right, val);
    }
    return node;
}

//Zad 2
//Валидно решение на задачата, но ще доведе до проблеми, ако използваме t2 след нея
Node* mergeTwo(Node* t1, Node* t2) {
    if(!t1) {
        return t2;
    }
    if(!t2) {
        return t1;
    }

    t1->val += t2->val;
    t1->left = mergeTwo(t1->left, t2->left);
    t1->right = mergeTwo(t1->right, t2->right);
    return t1;
}

//Примерно решение чрез създаване на ново дърво
Node* mergeTwoIntoNew(Node* t1, Node* t2) {
    if (!t1 && !t2) return NULL;
    
    int val1 = t1 ? t1->val : 0;
    int val2 = t2 ? t2->val : 0;
    
    Node* t = create_node(val1 + val2);
    t->left = mergeTwoIntoNew(t1 ? t1->left : NULL, t2 ? t2->left : NULL);
    t->right = mergeTwoIntoNew(t1 ? t1->right : NULL, t2 ? t2->right : NULL);
    
    return t;
}

void print_preorder(Node* node) {
    if(!node) {
        return;
    }

    printf("%d ", node->val);
    print_preorder(node->left);
    print_preorder(node->right);
}

//Zad3
void zigzag_traverse(Node* node) {
    if(!node) {
        return;
    }
    Stack* currLevel = init_stack();
    Stack* nextLevel = init_stack();
    push(currLevel, node);
    int leftToRight = 1;

    while(currLevel->top) {
        Node* curr = pop(currLevel);
        printf("%d ", curr->val);

        if(leftToRight) {
            if(curr->left) {
                push(nextLevel, curr->left);
            }
            if(curr->right) {
                push(nextLevel, curr->right);
            }
        } else {
            if(curr->right) {
                push(nextLevel, curr->right);
            }
            if(curr->left) {
                push(nextLevel, curr->left);
            }
        }

        if(!currLevel->top) {
            Stack* tmp = nextLevel;
            nextLevel = currLevel;
            currLevel = tmp;
            leftToRight = !leftToRight;
        }
    }
    clear_stack(currLevel);
    clear_stack(nextLevel);
}

//Zad4
/*
a. 11 -> 8 -> 21 -> 1 -> 9 -> 17 -> 32 Е един примерен ред, но не е единствен.

b. Binary search tree е по-специален вариант на бинарно дърво, при който за всеки Node, 
   лявото му поддърво се състои от по-малки от него елементи, а дясното му поддърво от по-големи елементи.

c. 
    a) preorder:  25 20 10 5 12 22 36 30 28 40 38 48
    b) inorder:   5 10 12 20 22 25 28 30 36 38 40 48
    c) postorder: 5 12 10 22 20 28 30 38 48 40 36 25

d. a), b), 

*/
int main() {
    Node* tree = create_node(10);
    bst_insert(tree, 20);
    bst_insert(tree, 5);
    bst_insert(tree, 1);
    bst_insert(tree, 8);
    bst_insert(tree, 2);
    bst_insert(tree, 15);
    bst_insert(tree, 25);
    bst_insert(tree, 22);

    Node* t1 = create_node(1);
    t1->left = create_node(3);
    t1->right = create_node(2);
    t1->left->left = create_node(5);

    Node* t2 = create_node(2);
    t2->left = create_node(1);
    t2->right = create_node(3);
    t2->left->right = create_node(4);
    t2->right->right = create_node(7);

    Node* t3 = mergeTwoIntoNew(t1, t2);

    mergeTwo(t1, t2);

    print_preorder(t1);
    printf("\n");
    
    print_preorder(t3);
    printf("\n");

    zigzag_traverse(tree);
}