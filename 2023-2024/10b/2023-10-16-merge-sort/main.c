#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// fac(5) = 5 * fac(4)
// fac(n) = n * fac(n-1)
// fac(1) = 1

int fac(int n) {
    printf("fac(%d)\n", n);
    if(n <= 1) {
        printf("return 1\n");
        return 1;
    }
    
    printf("return %d * fac(%d)\n", n, n -1);
    return n * fac(n-1);
}

void print_arr(int* arr, int count) {
    for(int i = 0; i < count; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }
}

void merge_sort(
    int* arr,
    int count
) {
    printf("merge_sort(%p, %d) start\n", arr, count);
    puts("Before split: ");
    print_arr(arr, count);

    if(count <= 1) {
        // No need to split
        return;
    }

    int mid = count / 2;
    int* left = arr;
    int* right = arr + mid;
    printf("mid=%d, left=%p, right=%p\n", mid, left, right);

    merge_sort(left, mid);
    merge_sort(right, count - mid);
    printf("merge_sort(%p, %d) end\n", arr, count);

    int* tmp = malloc(sizeof(int) * count);
    int lIndex = 0;
    int rIndex = 0;

    for(int i = 0; i < count; i++) {
        printf("i=%d lIndex=%d(%d) rIndex=%d(%d)\n", i, lIndex, mid, rIndex, count - mid);

        // All conditions in separate statements
        // if(lIndex >= mid) // only the right array has items
        //     tmp[i] = right[rIndex++];
        // else if (rIndex >= (count - mid)) // only the left array has items
        //     tmp[i] = left[lIndex++];
        // else if (left[lIndex] > right[rIndex]) // the right item is smaller than the left
        //     tmp[i] = right[rIndex++];
        // else // the left item is smaller than the rigth
        //     tmp[i] = left[lIndex++];

        // First attempt in class
        // if(
        //     (lIndex >= mid && 
        //     rIndex < (count - mid)) || 
        //     left[lIndex] > right[rIndex]
        // ) {
        //     tmp[i] = right[rIndex++];
        // } else {
        //     tmp[i] = left[lIndex++];
        // }

        // Working version
        if (
            // IF the left array is over => only the right array has items to take
            lIndex >= mid ||
            // OR the right array is not over => both arrays have items
            // AND the right item is smaller than the left item => compare the first items in the arrays
            (
                rIndex < (count - mid) && 
                left[lIndex] > right[rIndex]
            )
        )
            // Take from the right array
            tmp[i] = right[rIndex++];
        else
            // All other cases - right array is over OR left item is smaller than right item
            tmp[i] = left[lIndex++];
    }

    memcpy(arr, tmp, sizeof(int) * count);
    free(tmp);
    tmp = NULL;
    
    puts("After merge: ");
    print_arr(arr, count);
}


int main() {
    // fac(5);
    int arr[] = {3, 5, 4, 1, 2};

    puts("Before sort: ");
    print_arr(arr, 5);

    merge_sort(arr, 5);

    puts("After sort: ");
    print_arr(arr, 5);

    return 0;
}