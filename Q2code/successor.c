#include "color.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



// Function to find the immediate successor of a given 2-colored permutation
bool findSuccessor(PermElement *perm, int n) {
    // Step 1: Try to toggle color from 0 to 1 from right to left
    for (int i = n - 1; i >= 0; i--) {
        if (perm[i].color == 0) {
            perm[i].color = 1;
            return true;
        } else {
            perm[i].color = 0; // Reset color and try to increment the next element
        }
    }

    // Step 2: Find the next lexicographical permutation
    // Find longest non-increasing suffix
    int i = n - 1;
    while (i > 0 && perm[i - 1].value >= perm[i].value)
        i--;
    // Now, i is the head index of the suffix
    
    // Are we at the last permutation already?
    if (i <= 0) return false;
    
    // Find the pivot (the element just before the suffix)
    int j = n - 1;
    while (perm[j].value <= perm[i - 1].value)
        j--;
    // Swap the pivot with the rightmost successor in the suffix
    swap(&perm[i - 1], &perm[j]);

    // Reverse the suffix
    j = n - 1;
    while (i < j) {
        swap(&perm[i], &perm[j]);
        i++;
        j--;
    }
    
    return true;
}

void printSuccessor(PermElement *perm) {
    // Example permutation with color.
    int n = sizeof(perm) / sizeof(perm[0]);

    if (findSuccessor(perm, n)) {
        printf("Successor permutation:\n");
        for (int i = 0; i < n; i++) {
            printf("%d(color %d) ", perm[i].value, perm[i].color);
        }
        printf("\n");
    } else {
        printf("Given permutation is the last in its order.\n");
    }
}

// New function to initialize the first permutation
void initializeFirstPermutation(PermElement *perm, int n) {
    for (int i = 0; i < n; i++) {
        perm[i].value = i + 1; // Elements in ascending order
        perm[i].color = 0;     // All colors set to 0
    }
}

// Function to list all 2-colored permutations
void listAll2ColoredPermutations(int n) {
    PermElement *perm = malloc(n * sizeof(PermElement));
    if (!perm) {
        fprintf(stderr, "Memory allocation failed.\n");
        return;
    }

    // Initialize to the first permutation
    initializeFirstPermutation(perm, n);

    // Continuously find and print the next permutation until done
    do {
        for (int i = 0; i < n; i++) {
            printf("%d(color %d) ", perm[i].value, perm[i].color);
        }
        printf("\n");
    } while (findSuccessor(perm, n));

    free(perm);
}
