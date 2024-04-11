#include "color.h"
#include <stdio.h>
#include <stdlib.h>

// Helper function to find the k-th smallest element and remove it from the array
int findAndRemoveKth(int *array, int size, int k) {
    int elem = array[k];
    for (int i = k; i < size - 1; i++) {
        array[i] = array[i + 1];
    }
    return elem;
}

// Function to unrank a permutation given its rank and size n
void unrank2ColoredPermutation(int rank, int n, PermElement *perm) {
    // Decode colors from the lower n bits
    for (int i = n - 1; i >= 0; i--) {
        perm[i].color = rank & 1;
        rank >>= 1;
    }

    // Prepare an array to help with permutation decoding
    int *elements = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        elements[i] = i + 1; // Initialize with 1 through n
    }

    // Decode the permutation part
    for (int i = 0; i < n; i++) {
        int number = factorial(n - i - 1);
        int index = rank / number;
        rank %= number;

        perm[i].value = findAndRemoveKth(elements, n - i, index);
    }

    free(elements);
}


void printUnrankedPermutation(int rank, int n) {

    PermElement *perm = malloc(n * sizeof(PermElement));

    unrank2ColoredPermutation(rank, n, perm);

    printf("Permutation for rank %d:\n", rank);
    for (int i = 0; i < n; i++) {
        printf("%d(color %d) ", perm[i].value, perm[i].color);
    }
    printf("\n");

    free(perm);
}
