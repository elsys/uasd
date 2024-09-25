#include <stdio.h>


int main() {
    int arr1[5];
    // int* arr2[5]; ???
    int arr3[5] = {1,2,3};

    int* ptr1 = NULL;
    if(ptr1 == NULL)  {
        printf("ptr1 is empty\n");
        // ...
    }

    for(int i = 0; i < 5; i++) 
        arr1[i] = i + 10;
    for(int i = 0; i < 5; i++) 
        printf("arr1[%d] = %d\n", i, arr1[i]);
    
    // for(int* i = arr1; ???; i++) 
    //     printf("arr1[%d] = %d\n", ???, *i);

    printf("%p %d %d\n", arr1, arr1[0], *arr1);
    for(int i = 0; i < 5; i++) 
        printf("%p %p %d %d\n", &(arr1[i]), arr1 + i, arr1[i], *(arr1 + i));

    return 0;
}