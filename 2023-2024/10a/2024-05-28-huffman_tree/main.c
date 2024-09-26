#include <stdio.h>
#include <stdlib.h>


















typedef struct HuffmanTreeNode
{
    char c;
    int freq;
    struct HuffmanTreeNode *left, *right;
} HuffmanTreeNode;

HuffmanTreeNode *init_huffman_node(char c, int freq)
{
    HuffmanTreeNode *node = (HuffmanTreeNode *)malloc(sizeof(HuffmanTreeNode));
    node->c = c;
    node->freq = freq;
    node->left = NULL;
    node->right = NULL;
    return node;
}

HuffmanTreeNode *huffmanTree(char *text)
{
    int freq[256] = {0};

    for (int i = 0; text[i] != '\0'; i++)
    {
        freq[text[i]]++;
    }

    PQueue *pq = init_pq();
    for (int i = 0; i < 256; i++)
    {
        if (freq[i] > 0)
        {
            // printf("%c: %d\n", i, freq[i]);
            HuffmanTreeNode *node = init_huffman_node(i, freq[i]);
            pqInsert(pq, node, freq[i]);
        }
    }

    while (pq->size > 1)
    {
        HuffmanTreeNode *left = (HuffmanTreeNode *)(deleteMin(pq)->data);
        HuffmanTreeNode *right = (HuffmanTreeNode *)(deleteMin(pq)->data);

        // printf("Left: %c: %d\n", left->c, left->freq);
        HuffmanTreeNode *parent = init_huffman_node('\0', left->freq + right->freq);
        parent->left = left;
        parent->right = right;
        // printf("Parent: %c: %d\n", parent->c, parent->freq);

        pqInsert(pq, parent, parent->freq);
    }

    return (HuffmanTreeNode *)(deleteMin(pq)->data);
}

void printCodes(HuffmanTreeNode *root, int arr[], int top)
{
    if (root->left)
    {
        arr[top] = 0;
        printCodes(root->left, arr, top + 1);
    }

    if (root->right)
    {
        arr[top] = 1;
        printCodes(root->right, arr, top + 1);
    }

    if (!root->left && !root->right)
    {
        printf("%c: ", root->c);
        for (int i = 0; i < top; i++)
        {
            printf("%d", arr[i]);
        }
        printf("\n");
    }
}

int main()
{
    char text[] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed venenatis augue id magna blandit, nec venenatis tortor congue. Proin maximus pellentesque odio, ut aliquet enim mattis sit amet. Quisque condimentum vitae mauris eget euismod. Nunc ut purus sit amet nibh fermentum mattis id non arcu. Proin viverra velit quis ex tincidunt tempus. Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nulla facilisi. Aenean nisl dui, interdum sed sem id, efficitur euismod purus. Aliquam vulputate lacus in nisi venenatis congue. Vivamus sed dignissim sapien, sed iaculis mi. Quisque nisi diam, pulvinar ut condimentum et, imperdiet et nisl.";

    HuffmanTreeNode *root = huffmanTree(text);
    int arr[100], top = 0;
    printCodes(root, arr, top);

    return 0;
}