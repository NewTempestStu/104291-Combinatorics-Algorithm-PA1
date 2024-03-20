#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

void generateSubsets(int n, int ***subsets, unsigned int *pow_set_size) {
    *pow_set_size = pow(2, n);
    *subsets = (int **)malloc(*pow_set_size * sizeof(int *));
    int index = 0;

    for (unsigned int i = 0; i < *pow_set_size; i++) {
        (*subsets)[index] = (int *)malloc((n + 1) * sizeof(int));
        (*subsets)[index][0] = 0; // First element stores the size of the subset
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                (*subsets)[index][++(*subsets)[index][0]] = j + 1;
            }
        }
        index++;
    }

    qsort(*subsets, *pow_set_size, sizeof(int *), compare);
}

void freeSubsets(int **subsets, unsigned int pow_set_size) {
    for (unsigned int i = 0; i < pow_set_size; i++) {
        free(subsets[i]);
    }
    free(subsets);
}

void printSubsets(int n) {
    unsigned int pow_set_size;
    int **subsets;
    generateSubsets(n, &subsets, &pow_set_size);

    for (unsigned int i = 0; i < pow_set_size; i++) {
        printf("{");
        for (int j = 1; j <= subsets[i][0]; j++) {
            printf("%d", subsets[i][j]);
            if (j < subsets[i][0]) printf(", ");
        }
        printf("} ");
    }
    printf("\n");
    freeSubsets(subsets, pow_set_size);
}

// Function to find and print the rank of a given subset
void printRank(int n, int *subset, int subsetSize) {
    unsigned int pow_set_size;
    int **subsets;
    generateSubsets(n, &subsets, &pow_set_size);
    
    int rank = -1; // Initialize rank as -1 to indicate not found
    for (unsigned int i = 0; i < pow_set_size; i++) {
        if (subsets[i][0] == subsetSize) {
            int match = 1; // Assume it's a match
            for (int j = 1; j <= subsetSize; j++) {
                if (subsets[i][j] != subset[j-1]) {
                    match = 0;
                    break;
                }
            }
            if (match) {
                rank = i;
                break;
            }
        }
    }
    
    if (rank != -1) {
        printf("Rank of the given subset is %d\n", rank);
    } else {
        printf("Given subset was not found.\n");
    }
    
    freeSubsets(subsets, pow_set_size);
}

// Function to unrank or find a subset given its rank
void printUnrank(int n, int rank) {
    unsigned int pow_set_size;
    int **subsets;
    generateSubsets(n, &subsets, &pow_set_size);
    
    if (rank >= 0 && rank < pow_set_size) {
        printf("Subset at rank %d is {", rank);
        for (int j = 1; j <= subsets[rank][0]; j++) {
            printf("%d", subsets[rank][j]);
            if (j < subsets[rank][0]) printf(", ");
        }
        printf("}\n");
    } else {
        printf("Invalid rank.\n");
    }
    
    freeSubsets(subsets, pow_set_size);
}


void printSuccessor(int n, int *subset, int subsetSize) {
    unsigned int pow_set_size;
    int **subsets;
    generateSubsets(n, &subsets, &pow_set_size);
    
    int rank = -1;
    // Find rank
    for (unsigned int i = 0; i < pow_set_size; i++) {
        if (subsets[i][0] == subsetSize) {
            int match = 1;
            for (int j = 1; j <= subsetSize; j++) {
                if (subsets[i][j] != subset[j-1]) {
                    match = 0;
                    break;
                }
            }
            if (match) {
                rank = i;
                break;
            }
        }
    }
    
    // Print successor
    if (rank != -1 && rank + 1 < pow_set_size) {
        printf("Successor of the given subset is {");
        for (int j = 1; j <= subsets[rank + 1][0]; j++) {
            printf("%d", subsets[rank + 1][j]);
            if (j < subsets[rank + 1][0]) printf(", ");
        }
        printf("}\n");
    } else {
        printf("Given subset does not have a successor.\n");
    }
    
    freeSubsets(subsets, pow_set_size);
}

int main() {
    int choice;
    int n, subsetSize, rank;
    int *subset;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Generate and print all subsets\n");
        printf("2. Find and print the rank of a given subset\n");
        printf("3. Find and print a subset given its rank\n");
        printf("4. Find and print the successor of a given subset\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the size of the set (n): ");
                scanf("%d", &n);
                printSubsets(n);
                break;
            case 2:
                printf("Enter the size of the set (n): ");
                scanf("%d", &n);
                printf("Enter the size of the subset: ");
                scanf("%d", &subsetSize);
                subset = (int *)malloc(subsetSize * sizeof(int));
                printf("Enter the elements of the subset: ");
                for (int i = 0; i < subsetSize; i++) {
                    scanf("%d", &subset[i]);
                }
                printRank(n, subset, subsetSize);
                free(subset);
                break;
            case 3:
                printf("Enter the size of the set (n): ");
                scanf("%d", &n);
                printf("Enter the rank of the subset to find: ");
                scanf("%d", &rank);
                printUnrank(n, rank);
                break;
            case 4:
                printf("Enter the size of the set (n): ");
                scanf("%d", &n);
                printf("Enter the size of the subset: ");
                scanf("%d", &subsetSize);
                subset = (int *)malloc(subsetSize * sizeof(int));
                printf("Enter the elements of the subset: ");
                for (int i = 0; i < subsetSize; i++) {
                    scanf("%d", &subset[i]);
                }
                printSuccessor(n, subset, subsetSize);
                free(subset);
                break;
            case 5:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Please enter a number between 1 and 5.\n");
        }
    }
    return 0;
}

