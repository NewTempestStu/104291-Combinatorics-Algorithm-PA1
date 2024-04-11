#include <stdio.h>
#include <stdlib.h>
#include "color.h" // Include the header file for factorial

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

//Function to print all permutations of size n 2-colored permutations
void printPermutations(PermElement *perm, int n) {
    PermElement *permCopy = malloc(n * sizeof(PermElement));
    for (int i = 0; i < n; i++) {
        permCopy[i] = perm[i];
    }
    sortPermutation(permCopy, n);
    int rank = rank2ColoredPermutation(permCopy, n);
    printf("Permutation %d: ", rank);
    for (int i = 0; i < n; i++) {
        printf("%d(color %d) ", permCopy[i].value, permCopy[i].color);
    }
    printf("\n");
}

void generatePermutations(PermElement *perm, int n, int index) {
    if (index == n) {
        return;
    }
    for (int i = 0; i < n; i++) {
        perm[index].value = i + 1;
        perm[index].color = index % 2;
        generatePermutations(perm, n, index + 1);
    }
}

int main() {
    int choice;
    int n;
    int size;
    int rank;
    
    printf("\nMenu:\n");                                                             // Print the menu
            printf("1. Generate and print all permutations/rank\n");                 // Print the menu
            printf("2. Find and print the rank of a given permutation\n");           // Print the menu
            printf("3. Find and print a permutation given its rank\n");              // Print the menu
            printf("4. Find and print the successor of a given permutation\n");      // Print the menu
            printf("5. Exit\n");                                                     // Print the menu
            printf("Enter your choice: ");                                           // Prompt the user for choice
            scanf("%d", &choice);

    while(1) {
        switch (choice) {
            case 1:
                printf("Enter the size of the permutation: ");
                scanf("%d", &size);
                n = size;
                PermElement *perm = malloc(n * sizeof(PermElement));
                generatePermutations(perm, n, 0);
                printPermutations(perm, n);
                break;
            case 2:
                printf("Enter the size of the given permutation: ");
                scanf("%d", &size);
                n = size;
                PermElement *perm2 = malloc(n * sizeof(PermElement));
                for(int i = 0; i < n; i++) {
                    printf("Enter the value for element %d: ", i + 1);
                    scanf("%d", &perm2[i].value);
                    printf("Enter the color for element %d (0 or 1): ", i + 1);
                    scanf("%d", &perm2[i].color);
                }

                printRank(size, perm2);
                break;
            case 3:
                printf("Enter the size of the permutation: ");
                scanf("%d", &size);
                n = size;
                printf("Enter the rank of the permutation: ");
                scanf("%d", &rank);
                printUnrankedPermutation(rank, n);
                break;
            case 4:
                printf("Enter the size of the permutation: ");
                scanf("%d", &size);
                n = size;
                PermElement *perm3 = malloc(n * sizeof(PermElement));
                for (int i = 0; i < n; i++) {
                    printf("Enter the value for element %d: ", i + 1);
                    scanf("%d", &perm3[i].value);
                    printf("Enter the color for element %d (0 or 1): ", i + 1);
                    scanf("%d", &perm3[i].color);
                }
                printSuccessor(perm3);
                break;
            case 5:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Please enter a number between 1 and 5.\n");
        }

    }
}
