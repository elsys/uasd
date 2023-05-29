#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "binary_tree.h"
#include "priority_queue.h"
#include "map.h"

map_t* find_frequencies(uint8_t* data, uint32_t size) {
    map_t* freq = init_map();

    for(int i = 0; i < size; i++) {
        if(map_has_key(freq, data[i])) {
            map_set(
                freq, 
                data[i], 
                map_get(freq, data[i]) + 1
            );
        } else {
            map_set(
                freq, 
                data[i], 
                1
            );
        }
    }

    return freq;
}

tree_node_t* generate_tree(map_t* freq, uint32_t size) {
    priority_queue_t* queue = init_queue();

    for(int i = 0; i < freq->size; i++) {
        uint8_t val = map_get_key(i);
        uint8_t count = map_get_value(i);
        float f = count / size;

        queue_push(
            queue, 
            init_tree_node(val, f);
        );
    }

    while(queue->size > 1) {
        tree_node_t* n1 = queue_pop(queue);
        tree_node_t* n2 = queue_pop(queue);

        tree_node_t* parent = init_tree_node(0, n1->f + n2->f);
        parent->left = n1;
        parent->right = n2;
        queue_push(queue, parent);
    }

    return queue_pop(queue);
}

void traverse_tree(tree_node_t* root, map_t* codes, uint16_t path) {
    if(root->left == NULL && root->right == NULL) {
        // leaf node
        map_set(codes, root->value, path);
    } else {
        // branch node
        if(root->left != NULL)
            traverse_tree(root->left, codes, path << 1);
        if(root->right != NULL)
            traverse_tree(root->right, codes, (path << 1) | 1);
    }
}

map_t* generate_codes(tree_node_t* root) {
    map_t* codes = init_map();
    traverse_tree(root, codes, 2);
    return codes;
}

uint8_t* compress_data(uint8_t* data, uint32_t size, map_t* codes) {
    uint8_t* data_out = malloc();

    unsigned int byte_index = 0;
    unsigned int bit_index = 0;

    for(int i = 0; i < size; i++) {
        //data_out += codes[data[i]];
        uint16_t code = map_get(data[i]);
        uint16_t leftmask = 1 << 15; // 0x1000000000000000;
        uint8_t code_length = 15;

        for(; code & leftmask == 0; code <<= 1, code_length--);
        code <<= 1;

        for(; code_length > 0; code <<= 1, code_length--) {
            uint8_t bit = code & leftmask >> 15; 

            data_out[byte_index] <<= 1;
            data_out[byte_index] |= bit;
            bit_index++;
            if(bit_index == 8) {
                bit_index = 0;
                byte_index++;
            }
        }
    }

    data_out[byte_index] <<= 8 - bit_index;

    return data_out;
}

uint8_t* compress(uint8_t* data, uint32_t size) {
    map_t* frequencies = find_frequencies(data, size);
    tree_node_t* tree = generate_tree(frequencies);
    map_t* codes = generate_codes(tree);
    uint8_t* data_out = compress_data(data, size, codes);

    return data_out;
}

uint8_t* decompress(uint8_t* data, uint32_t size) {
}

int main() {
    return 0;
}