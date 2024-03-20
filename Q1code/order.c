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
 * Rank the given subset.
 * The rank is calculated by sorting the subset and then counting the number of subsets that are lexicographically
 * 
 * @param n The size of the n-set.
 * @param set The subset to find the rank of.
*/
void printRank(int n, int *set) {
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
        if (subsets[i][0] == n) {
            printf("Rank of the given subset is %d\n", i);
            break;
        }
    }
    for (int i = 0; i < pow_set_size; i++) {
        free(subsets[i]);
    }
    free(subsets);
}

/**
 * Unrank the given rank.
 * 
 * @param n The size of the n-set.
 * @param rank The rank of the subset to unrank.
*/
void printUnrank(int n, int rank) {
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
        if (i == rank) {
            printf("Unrank of the given rank is {");
            for (int j = 1; j <= subsets[i][0]; j++) {
                printf("%d", subsets[i][j]);
                if (j < subsets[i][0]) printf(", ");
            }
            printf("}\n");
            break;
        }
    }
    for (int i = 0; i < pow_set_size; i++) {
        free(subsets[i]);
    }
    free(subsets);
    free(set);
}

/**
 * Find the successor of the given subset.
 * 
 * @param n The size of the n-set.
 * @param set The subset to find the successor of.
*/
void printSuccessor(int n, int *set) {
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
        if (subsets[i][0] == n) {
            printf("Successor of the given subset is {");
            for (int j = 1; j <= subsets[i][0]; j++) {
                printf("%d", subsets[i][j]);
                if (j < subsets[i][0]) printf(", ");
            }
            printf("}\n");
            break;
        }
    }
    for (int i = 0; i < pow_set_size; i++) {
        free(subsets[i]);
    }
    free(subsets);
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
    int m;
    printf("This program generates all subsets of an n-set and prints them in lexicographical order.\n");
    printf("A set of size n has 2^n subsets, so be careful with large n.\n");
    printf("The subsets are printed in the format {a1, a2, ..., ak} {b1, b2, ..., bl} ... {z1, z2, ..., zm}\n");
    printf("Please enter the selection of the functionality you want to use\n");
    printf("1. Generate all subsets of an n-set and print them in lexicographical order\n");
    printf("2. Generate the rank of a given subsets\n");
    printf("3. Generate the unrank of a given rank\n");
    printf("4. Generate the successor of a given subset\n");
    scanf("%d", &m);
    if (m==1){
    printf("Enter the size of the set (n): ");
    scanf("%d", &n);
    printSubsets(n);
    }
    else if (m==2){
    printf("Enter the size of the set (n): ");
    scanf("%d", &n);
    printf("Enter the subset to find the rank of: ");
    int *set = malloc(n * sizeof(int));
    for (int i = 0; i < n; ++i) {
        scanf("%d", &set[i]);
    }
    unsigned int pow_set_size = pow(2, n);
    int **subsets = malloc(pow_set_size * sizeof(int *));
    int index = 0;
    printRank(n, set);
    }
    else if (m==3){
    printf("Enter the size of the set (n): ");
    scanf("%d", &n);
    printf("Enter the rank to find the subset of: ");
    int rank;
    scanf("%d", &rank);
    printUnrank(n, rank);
    }
    else if (m==4){
    printf("Enter the size of the set (n): ");
    scanf("%d", &n);
    printf("Enter the subset to find the successor of: ");
    int *set = malloc(n * sizeof(int));
    for (int i = 0; i < n; ++i) {
        scanf("%d", &set[i]);
    }
    printSuccessor(n, set);
    }

    


    return 0;
}
