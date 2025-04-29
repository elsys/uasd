#include<stdio.h>
#include<stdlib.h>
#include "pqueue.h"

struct HuffmanTreeNode {
    char c;
    int freq;
    struct HuffmanTreeNode* left;
    struct HuffmanTreeNode* right;
};

typedef struct HuffmanTreeNode HuffmanTreeNode;

HuffmanTreeNode* initHuffmanTreeNode(char c, int freq) {
    HuffmanTreeNode* newNode = (HuffmanTreeNode*) malloc(sizeof(HuffmanTreeNode));
    newNode->c = c;
    newNode->freq = freq;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

HuffmanTreeNode* huffmanTree(char* text) {
    int freq[256] = {0};
    for(int i = 0; text[i] != '\0'; i++) {
        freq[text[i]]++;
    }

    PQueue* pq = init_pq();

    for(int i = 0; i < 256; i++) {
        if (freq[i] > 0) {
            HuffmanTreeNode* node = initHuffmanTreeNode(i, freq[i]);
            pqInsert(pq, node, freq[i]);
        }
    }

    while (pq->size > 1) {
        HuffmanTreeNode* left = (HuffmanTreeNode* ) deleteMin(pq)->data;
        HuffmanTreeNode* right = (HuffmanTreeNode* ) deleteMin(pq)->data;

        HuffmanTreeNode* parent = initHuffmanTreeNode(0, left->freq + right->freq);

        parent->left = left;
        parent->right = right;

        pqInsert(pq, parent, parent->freq);
    }

    return (HuffmanTreeNode*) deleteMin(pq)->data;
}

void printCodes(HuffmanTreeNode* root, int arr[], int top) {
    if (root->left) {
        arr[top] = 0;
        printCodes(root->left, arr, top+1);
    }
    
    if (root->right) {
        arr[top] = 1;
        printCodes(root->right, arr, top+1);
    }

    if(!root->left && !root->right) {
        printf("%c, %d: ", root->c, root->freq);
        for (int i = 0; i < top; i++) {
            printf("%d",arr[i]);
        }
        printf("\n");
    }
}


int main() {
    char text[] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Donec hendrerit lectus vitae tellus congue dapibus. Cras auctor auctor pellentesque. Phasellus consequat lacus ipsum. Maecenas sit amet massa lacinia, malesuada diam in, gravida odio. Sed consequat lorem tortor, elementum ornare enim gravida sed. In molestie condimentum sapien, vel finibus turpis eleifend semper. Nam ac lorem rhoncus, pellentesque dui a, tincidunt lectus. Ut fermentum velit gravida neque condimentum, sed porttitor nunc facilisis. Donec rhoncus ornare venenatis. Quisque sed placerat felis, ac laoreet ante. Quisque sit amet ipsum ac quam imperdiet volutpat vitae id ipsum.";
    // char text[] = "AAAABBBVGGDKKK";
    HuffmanTreeNode* root = huffmanTree(text);
    int arr[100];
    int top = 0;
    printCodes(root, arr, top);
}