typedef struct Set {
    struct Set* parent;
    int rank;
    int size;
} Set;

Set* init_set() {
    Set* set = (Set*)malloc(sizeof(Set));
    set->parent = set;
    set->rank = 0;
    set->size = 1;

    return set;
}

Set* find(Set* set) {
    if(set == set->parent) {
        return set;
    }
    return find(set->parent);
}

int set_union(Set* set1, Set* set2) {
    Set* root1 = find(set1);
    Set* root2 = find(set2);

    if (root1 == root2) {
        return root1->size;
    }

    if (root1->rank < root2->rank) {
        root1->parent = root2;
        root2->size += root1->size;
        return root2->size;
    } else {
        root2->parent = root1;
        if(root2->rank == root1->rank) {
            root1->rank++;
        }

        root1->size += root2->size;
        return root1->size;
    }
}


bool equationsPossible(char** equations, int equationsSize) {
    Set** sets = (Set**)malloc(sizeof(Set*)*26);
    for (int i = 0; i < 26; i++) {
        sets[i] = init_set();
    } 

    for (int i = 0; i < equationsSize; i++) {
        if (equations[i][1] == '=') {
            set_union(sets[equations[i][0] - 'a'], sets[equations[i][3] - 'a']);
        }
    }

    for (int i = 0; i < equationsSize; i++) {
        if (equations[i][1] == '!') {
            Set* group1 = find(sets[equations[i][0] - 'a']);
            Set* group2 = find(sets[equations[i][3] - 'a']);

            if(group1 == group2) {
                return false;
            }
        }
    }

    return true;
}

