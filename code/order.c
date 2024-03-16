#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
 * Compares two subsets based on their lengths first and then lexicographically.
 * This function is used by qsort.
 *
 * @param a Pointer to the first subset.
 * @param b Pointer to the second subset.
 * @return Negative if a < b, positive if a > b, zero if equal.
 */
int compare(const void *a, const void *b) {
    const int *ia = *(const int **)a;
    const int *ib = *(const int **)b;
    int sizeA = ia[0];
    int sizeB = ib[0];
    if (sizeA != sizeB) {
        return sizeA - sizeB;
    } else {
        for (int i = 1; i <= sizeA; ++i) {
            if (ia[i] != ib[i]) {
                return ia[i] - ib[i];
            }
        }
    }
    return 0;
}

/**
 * Generates all subsets of the n-set, sorts them first by size then lexicographically, and prints them.
 *
 * @param n The size of the n-set.
 */
void printSubsets(int n) {
    int *set = malloc(n * sizeof(int));
    for (int i = 0; i < n; ++i) {
        set[i] = i + 1; // Fill the set with consecutive numbers
    }

    unsigned int pow_set_size = pow(2, n);
    int **subsets = malloc(pow_set_size * sizeof(int *));
    int index = 0;

    for (int i = 0; i < pow_set_size; i++) {
        subsets[index] = malloc((n + 1) * sizeof(int));
        subsets[index][0] = 0; // First element will store the size of the subset
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                subsets[index][++subsets[index][0]] = set[j];
            }
        }
        index++;
    }

    qsort(subsets, pow_set_size, sizeof(int *), compare);

    for (int i = 0; i < pow_set_size; i++) {
        printf("{");
        for (int j = 1; j <= subsets[i][0]; j++) {
            printf("%d", subsets[i][j]);
            if (j < subsets[i][0]) printf(", ");
        }
        printf("} ");
        free(subsets[i]);
    }
    printf("\n");
    free(subsets);
    free(set);
}

/**
 * Main function. Prompts the user for the size of the n-set, then prints all subsets sorted by size and lexicographically.
 */
int main() {
    int n;
    printf("Enter the size of the set (n): ");
    scanf("%d", &n);

    printSubsets(n);
    return 0;
}
