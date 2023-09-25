int* sort(int arr[], int count) {
    //int res[count];
    int *res = malloc(count * sizeof(int));

    // ???

    
    (*res) = 10;
    *(res + 0) = 10;
    res[0] = 10;

    *(res + 1) = 20;
    res[1] = 20;

    return res;
}

int main() {
    return 0;
}