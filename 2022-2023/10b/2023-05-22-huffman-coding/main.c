#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

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

map_t* generate_codes(tree_node_t* root) {
    
}

uint8_t* compress(uint8_t* data, uint32_t size) {
    map_t* frequencies = find_frequencies(data, size);
    tree_node_t* tree = generate_tree(frequencies);
    void* codes = generate_codes(tree);

    uint8_t* data_out = malloc();
    for(int i = 0; i < size; i++) {
        data_out += codes[data[i]];
    }

    return data_out;
}

int main() {
    return 0;
}