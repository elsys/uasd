#include "dsu.h"
#include "dsu2.h"

//Explain difference between the two implementation
/*
The first implementation (dsu.h and dsu.c) uses an array-based approach to represent the disjoint sets. 
Each element in the array represents a set, and the parent of each set is stored in the parent array. 

The second implementation (dsu2.h and dsu2.c) uses a pointer-based approach to represent the disjoint sets. 
Each set is represented as a struct that contains a pointer to its parent and a rank. The find and union operations 
are implemented using pointers, which can be more efficient in terms of memory usage and can allow for more 
flexible data structures.


The rank array is used to optimize the union operation by keeping track of the depth of the trees representing the sets.
Ignore that for now.
In terms of functionality, both implementations provide the same operations: initialization, finding the 
representative of a set, and union of two sets. 
*/

int main() {
    //Example usage of DSU 1
    DSU* dsu = init_dsu(5);

    union_sets(dsu, 0, 1);
    union_sets(dsu, 1, 2);
    union_sets(dsu, 3, 4);

    printf("Find(0): %d\n", find(dsu, 0)); // Should print the representative of the set containing 0
    printf("Find(1): %d\n", find(dsu, 1)); // Should print the same representative as Find(0)
    printf("Find(2): %d\n", find(dsu, 2)); // Should print the same representative as Find(0)
    printf("Find(3): %d\n", find(dsu, 3)); // Should print the representative of the set containing 3
    printf("Find(4): %d\n", find(dsu, 4)); // Should print the same representative as Find(3)

    free_dsu(dsu);

    //Example usage of DSU 2
    Set** sets = init_sets(5);
    union_sets2(sets[0], sets[1]);
    union_sets2(sets[1], sets[2]);
    union_sets2(sets[3], sets[4]);

    printf("Find(0): %p\n", (void*)find2(sets[0])); // Should print the representative of the set containing 0
    printf("Find(1): %p\n", (void*)find2(sets[1])); // Should print the same representative as Find(0)
    printf("Find(2): %p\n", (void*)find2(sets[2])); // Should print the same representative as Find(0)
    printf("Find(3): %p\n", (void*)find2(sets[3])); // Should print the representative of the set containing 3
    printf("Find(4): %p\n", (void*)find2(sets[4])); // Should print the same representative as Find(3)

    free_sets(sets, 5);

    return 0;
}