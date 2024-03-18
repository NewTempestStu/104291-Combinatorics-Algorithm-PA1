#include <stdio.h>
#include <stdlib.h>
#include "colormath.h" // Include the header file for factorial

// Define a structure for a permutation element with color.
typedef struct {
    int value; // The value of the permutation element.
    int color; // The color of the element, 0 or 1.
} PermElement;

// Comparison function for sorting permutation elements.
int comparePermElements(const void *a, const void *b) {
    const PermElement *element1 = (const PermElement *)a;
    const PermElement *element2 = (const PermElement *)b;
    
    // First compare by value.
    if (element1->value != element2->value)
        return element1->value - element2->value;
    // If values are equal, then compare by color.
    return element1->color - element2->color;
}

// Function to sort a single permutation.
void sortPermutation(PermElement *perm, int n) {
    qsort(perm, n, sizeof(PermElement), comparePermElements);
}

int main() {
    // Example permutation with color.
    PermElement permutation[] = {{3, 1}, {1, 0}, {2, 1}, {3, 0}, {1, 1}};
    int n = sizeof(permutation) / sizeof(permutation[0]);

    // Sort the permutation.
    sortPermutation(permutation, n);

    // Print the sorted permutation.
    printf("Sorted permutation:\n");
    for (int i = 0; i < n; i++) {
        printf("Value: %d, Color: %d\n", permutation[i].value, permutation[i].color);
    }

    return 0;
}
