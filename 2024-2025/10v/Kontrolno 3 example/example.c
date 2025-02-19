#include<stdio.h>
#include<stdlib.h>

typedef enum Color {
    BLACK,
    RED
} Color;

struct Node {
    int val;
    struct Node* left;
    struct Node* right;
    struct Node* parent;
    Color color;
};

typedef struct Node Node;

Node* initNode(int val) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    if(!newNode) {
        exit(1);
    }
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->parent = NULL;
    newNode->val = val;
    newNode->color = RED;
    return newNode;
}

void leftRotation(Node** root, Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;


    if (!x->parent){
        *root = y;
    } else if(x->parent->left == x) {
        x->parent->left = y;
    } else {
        x->parent->right = y;
    }
    y->parent = x->parent;

    x->parent = y;

    x->right = T2;
    y->left = x;

    if(T2) {
        T2->parent = x;
    }
}

/*
     y      RightRotation     x
    / \     ------------->   / \
   x  T3                    T1  y
  / \       <-------------     / \
 T1 T2       LeftRotation     T2 T3
*/

void rightRotation(Node** root, Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    if(!y->parent) {
        *root = x;
    } else if (y->parent->left == y) {
        y->parent->left = x;
    } else {
        y->parent->right = x;
    }

    x->parent = y->parent;
    y->parent = x;

    x->right = y;

    y->left = T2;

    if(T2) {
        T2->parent = y;
    }

}

void treeFixUp(Node** root, Node* node) { // log(n)
    Node* grandparent = NULL;
    Node* uncle = NULL;
    while(node != (*root) && node->parent && node->parent->color == RED) {
        grandparent = node->parent->parent;
        if(node->parent == grandparent->left) {
            uncle = grandparent->right;
            if(uncle && uncle->color == RED) {
                node->parent->color = BLACK;
                grandparent->color = RED;
                uncle->color = BLACK;

                node = grandparent;
            } else {
                if(node->parent->right == node) {
                    node = node->parent;
                    leftRotation(root, node);
                }
                grandparent->color = RED;
                node->parent->color = BLACK;
                rightRotation(root, grandparent);
            }
        } else {
            uncle = grandparent->left;
            if(uncle && uncle->color == RED) {
                node->parent->color = BLACK;
                grandparent->color = RED;
                uncle->color = BLACK;

                node = grandparent;
            } else {
                if(node->parent->left == node) {
                    node = node->parent;
                    rightRotation(root, node);
                }
                grandparent->color = RED;
                node->parent->color = BLACK;
                leftRotation(root, grandparent);
            }
        }
    }

    (*root)->color = BLACK;
}


void insert(Node**root, int val) {
    Node* newNode = initNode(val);
    Node* current = *root;

    if (!current) {
        newNode->color = BLACK;
        *root = newNode;
        return;
    }

    while(1) {
        if(val < current->val) {
            if(!current->left) {
                break;
            }
            current = current->left;
        } else {
            if(!current->right) {
                break;
            }
            current = current->right;
        }
    }

    if(val < current->val) {
        current->left = newNode;
    } else {
        current->right = newNode;
    }
    newNode->parent = current;

    treeFixUp(root, newNode);
}

void printTreePreorder(Node* root) {
    if (!root) {
        return;
    }

    printf("%d(%c) ", root->val, root->color == BLACK ? 'B' : 'R');
    printTreePreorder(root->left);
    printTreePreorder(root->right);
}

void printTreeInorder(Node* root) {
    if (!root) {
        return;
    }
    printTreeInorder(root->left);
    printf("%d(%c) ", root->val, root->color == BLACK ? 'B' : 'R');
    printTreeInorder(root->right);
}


// int getBH(Node *root) {
//     if (root == NULL) {
//         return 1;
//     }
//     int leftBH = getBH(root->left);
//     int rightBH = getBH(root->right);
//     if (leftBH == -1 || rightBH == -1 || leftBH != rightBH) {
//         return -1;
//     }
//     return (root->color == BLACK) ? leftBH + 1 : leftBH;
// }

// 1
int getBH(Node *root) {
    int bh = 0;
    while (root) {
        if (root->color == BLACK) {
            bh++;
        }
        root = root->left;
    }
    return bh;
}
 
Node* joinTrees(Node* t1, Node* t2, int x) {
    if (!t1 && !t2) {
        Node* newNode = initNode(x);
        newNode->color = BLACK;
        return newNode;
    }
    if (!t1) {
        insert(&t2, x); 
        return t2;
    }
    if (!t2) {
        insert(&t1, x); 
        return t1;
    }

    int bh1 = getBH(t1); // log(n)
    int bh2 = getBH(t2); // log(n)

    //2
    if (bh1 < bh2) {
        Node* temp = t1;
        t1 = t2;
        t2 = temp;
        int tempBh = bh1;
        bh1 = bh2;
        bh2 = tempBh;
    }

    Node* y = t1;
    int currentBh = bh1;

    while (y) { // log(n)
        int nextBh = currentBh - (y->color == BLACK ? 1 : 0);
        
        if (nextBh >= bh2) {
            y = y->right;
            currentBh = nextBh;
        } 
        else {
            break;
        }
    } 

    if (!y) return NULL;

    // 3
    Node* xNode = initNode(x);
    xNode->color = RED;

    if (y->parent) {
        y->parent->right = xNode;        
        xNode->parent = y->parent;
    } else {
        t1 = xNode;
        xNode->parent = NULL;
    }

    xNode->left = y;
    y->parent = xNode;
    xNode->right = t2;
    if (t2) t2->parent = xNode;

    // 4
    if (xNode->parent && xNode->parent->color == RED) {
        treeFixUp(&t1, xNode); // log(n)
    }

    t1->color = BLACK;

    return t1;
}

// 6
int checkRedChildren(Node* node) {
    if (!node) return 1;
    if (node->color == RED) {
        if ((node->left && node->left->color == RED) || 
            (node->right && node->right->color == RED)) {
            return 0;
        }
    }
    return checkRedChildren(node->left) && checkRedChildren(node->right);
}

int checkBlackHeight(Node* node, int current, int* bh) {
    if (!node) {
        current += 1;
        if (*bh == -1) {
            *bh = current;
            return 1;
        }
        return current == *bh;
    }
    int newCurrent = current + (node->color == BLACK ? 1 : 0);
    return checkBlackHeight(node->left, newCurrent, bh) && 
           checkBlackHeight(node->right, newCurrent, bh);
}

int isRBTree(Node *root) {
    if (!root) return 1;
    if (root->color != BLACK) return 0;
    if (!checkRedChildren(root)) return 0;
    int bh = -1;
    return checkBlackHeight(root, 0, &bh);
}
 
int main()
{
    struct Node *root = NULL;
 
    insert(&root, 7);
    insert(&root, 3);
    insert(&root, 18);
    insert(&root, 28);
    insert(&root, 32);
    insert(&root, 52);
    insert(&root, 41);
    insert(&root, 35);
    insert(&root, 65);
    insert(&root, 27);
    insert(&root, 17);
    insert(&root, 99);
    insert(&root, 88);
 
 
    struct Node *root2 = NULL;
 
    insert(&root2, 101);
    insert(&root2, 150);
    insert(&root2, 180);
    insert(&root2, 280);
    insert(&root2, 320);
    insert(&root2, 520);
    insert(&root2, 410);
 
    struct Node *joined = joinTrees(root, root2, 100);
 
    printTreeInorder(joined);
    
    if (isRBTree(joined)) {
      printf("yes");
    }
 
    return 0;
}
 
/*
Задача1:
 node x винаги ще се добавя като червен, за да не нарушава баланса спрямо черната височина.
 каква е сложността на join-а?

// 5
 намирането на височините е log(n), 
 намирането на y е log(n) и ако е нужен fixUp, той е log(n), 
 останалите операции са константни. 
 => общата сложност на функцията е O(log(n))
Задача2:
 за AVL дървото:
    да, това е валидно AVL дърво, тъй като balanceFactor-а на всеки един от възлите е в диапазона [-1;1].
 за RB дървото:
    най-късия път до листо ни е с дължина 3, а най-дългия 7, което е повече от 2 пъти по-голяма дължина
Задача3:
    броя връзки е от 0 до 5. 
    Понеже сме премахнали всички червени възли, 
    а преди това е било валидно червено-черно дърво, 
    то всички листа ще са на еднаква дължбочина в дървото.
Задача4:
    1) Коренът винаги е черен
    2) Червени върхове не могат да имат червени деца
    3) Всеки път от node до което и да е листо под него съдържа равен брой черни върхове
    4) Всички NULL върхове (листа) са черни
    Според тези правила, един червен връх НЕ може да има само едно дете.
Задача5:
 за RB дървото:
    20(B), 10(R), 30(B), 5(B), 15(B), 13(R), 17(R)
 за AVL дървото:
    8, 5, 12, 4, 11, 18, 17
*/