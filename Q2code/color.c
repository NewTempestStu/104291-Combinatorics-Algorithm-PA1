#include <stdio.h>
#include <stdlib.h>
#include "color.h"




int main() {
    int choice;
    int n;
    int size;
    int rank;
    PermElement **perms;
    unsigned int perms_count;
    
    
    while(1) {
        printf("\nMenu:\n");                                                     // Print the menu
        printf("1. Generate and print all permutations/rank\n");                 // Print the menu
        printf("2. Find and print the rank of a given permutation\n");           // Print the menu
        printf("3. Find and print a permutation given its rank\n");              // Print the menu
        printf("4. Find and print the successor of a given permutation\n");      // Print the menu
        printf("5. Exit\n");                                                     // Print the menu
        printf("Enter your choice: ");                                           // Prompt the user for choice
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the size of the permutation: ");
                scanf("%d", &n);

                generateAllColoredPermutations(n, &perms, &perms_count);
                printPermutations(perms, n, perms_count);
                cleanupPermutations(perms, perms_count);
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
