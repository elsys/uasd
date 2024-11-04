#include<stdio.h>

void example1(int n) {
    int a = 0; // O(1)
    for(int i = 0; i < n; i++) { // O(n)
        a++; // O(1) each iteration
    }
    // Overall: O(n)
}

void example2(int n) {
    for(int i = 0; i < n; i++) { // O(n)
        for(int j = 0; j < 4; j++) { // O(1), runs 4 times
            printf("hello\n"); // O(1) each iteration
        }
    }
    // Overall: O(n)
}

void example3(int n) {
    for(int i = 0; i < n; i++) { // O(n)
        for(int j = 0; j < n; j++) { // O(n)
            printf("hello\n"); // O(1) each iteration
        }
    }
    // Overall: O(n^2)
}

void example4(int n) {
    for(int i = 0; i < n; i++) { // O(n)
        for(int j = n; j > n-3; j-- ) { // O(1), runs 3 times
            printf("hello\n"); // O(1) each iteration
        }
    }
    // Overall: O(n)
}

void example5(int n) {
    for(int i = 0; i < n; i++) { // O(n)
        printf("hi\n"); // O(1) each iteration
    }

    for(int i = 0 ; i < 2*n; i++) { // O(2n) → O(n)
        printf("hello\n"); // O(1) each iteration
    }
    // Overall: O(n)
}

void example6(int n) {
    for (int i = 1; i < n; i *= 2) { // O(log n)
        printf("hello\n"); // O(1) each iteration
    }
    // Overall: O(log n)
}

void example7(int n) {
    for (int i = 0; i < (1 << n); i++) { // O(2^n)
        printf("hello\n"); // O(1) each iteration
    }
    // Overall: O(2^n)
}

void example8(int n) { // O(n log n)
    for (int i = 0; i < n; i++) { // O(n)
        for (int j = 1; j < n; j *= 2) { // O(log n)
            printf("hello\n"); // O(1) each iteration
        }
    }
    // Overall: O(n log n)
}

void example9(int n) {
    for (int i = 0; i < n; i++) { // O(n)
        printf("hello\n"); // O(1) each iteration
    }

    for (int i = 1; i < n; i *= 2) { // O(log n)
        printf("world\n"); // O(1) each iteration
    }

    for (int i = 0; i < n; i++) { // O(n)
        for (int j = 0; j < n; j++) { // O(n)
            printf("!"); // O(1) each iteration
        }
    }
    // Overall: O(n^2)
}


int main() {
    
}