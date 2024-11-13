#include <stdio.h>
#include "./Set/set.h"
#include "./TreeSet/treeSet.h"


int main() {
    Set* mySet = initSet();
    Node* myTreeSet = initTreeSet(5);
    
    treeSetAdd(myTreeSet, 5);
    treeSetAdd(myTreeSet, 3);
    treeSetAdd(myTreeSet, 4);
    treeSetAdd(myTreeSet, 1);
    treeSetAdd(myTreeSet, 1);
    // // OR
    // treeSetAdd2(&myTreeSet, 5);
    // treeSetAdd2(&myTreeSet, 3);
    // treeSetAdd2(&myTreeSet, 4);
    // treeSetAdd2(&myTreeSet, 1);
    // treeSetAdd2(&myTreeSet, 1);
    printTreeSet(myTreeSet);
    setAdd(mySet, 5);
    setAdd(mySet, 3);
    setAdd(mySet, 4);
    setAdd(mySet, 1);
    setAdd(mySet, 1);
    printSet(mySet);
}