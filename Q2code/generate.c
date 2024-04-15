#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "color.h"

// Local function declarations
static void sortPermutation(PermElement *perm, int n);
static void permute(PermElement *elements, int start, int end, PermElement **all_perms, unsigned int *index);
static void generateColorConfigurations(PermElement *current_perm, int n, PermElement **all_perms, unsigned int *index);
static int comparePermElements(const void *a, const void *b);

// Comparison function for sorting permutation elements.
static int comparePermElements(const void *a, const void *b) {
    const PermElement *element1 = (const PermElement *)a;
    const PermElement *element2 = (const PermElement *)b;
    if (element1->value != element2->value)
        return element1->value - element2->value;
    return element1->color - element2->color;
}

// Function to sort a single permutation.
static void sortPermutation(PermElement *perm, int n) {
    qsort(perm, n, sizeof(PermElement), comparePermElements);
}

void generateAllColoredPermutations(int n, PermElement ***all_perms, unsigned int *perms_count) {
    *perms_count = (1 << n); // 2^n for color configurations
    for (int i = 2; i <= n; i++) {
        *perms_count *= i; // Factorial(n)
    }

    *all_perms = malloc(*perms_count * sizeof(PermElement *));
    for (unsigned int i = 0; i < *perms_count; i++) {
        (*all_perms)[i] = malloc(n * sizeof(PermElement));
    }

    PermElement *elements = malloc(n * sizeof(PermElement));
    for (int i = 0; i < n; i++) {
        elements[i].value = i + 1; // 1 to n
    }

    unsigned int index = 0;
    permute(elements, 0, n, *all_perms, &index);
    free(elements);
}

static void permute(PermElement *elements, int start, int end, PermElement **all_perms, unsigned int *index) {
    if (start == end) {
        generateColorConfigurations(elements, end, all_perms, index);
        return;
    }
    for (int i = start; i < end; i++) {
        PermElement temp = elements[start];
        elements[start] = elements[i];
        elements[i] = temp;
        permute(elements, start + 1, end, all_perms, index);
        temp = elements[start];
        elements[start] = elements[i];
        elements[i] = temp;
    }
}

static void generateColorConfigurations(PermElement *current_perm, int n, PermElement **all_perms, unsigned int *index) {
    unsigned int total_colors = 1 << n;
    for (unsigned int i = 0; i < total_colors; i++) {
        for (int j = 0; j < n; j++) {
            current_perm[j].color = (i >> j) & 1;
        }
        sortPermutation(current_perm, n);
        memcpy(all_perms[*index], current_perm, n * sizeof(PermElement));
        (*index)++;
    }
}

void cleanupPermutations(PermElement **perms, unsigned int perms_count) {
    for (unsigned int i = 0; i < perms_count; i++) {
        free(perms[i]);  // Free each array of PermElements
    }
    free(perms);  // Free the array of pointers
}

void printPermutations(PermElement **perms, int n, unsigned int perms_count) {
    for (unsigned int i = 0; i < perms_count; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d(%s) ", perms[i][j].value, perms[i][j].color == 0 ? "Red" : "Blue");
        }
        printf("\n");
    }
}
