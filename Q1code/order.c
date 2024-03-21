#include <stdio.h>                                                          // Include standard input/output library
#include <stdlib.h>                                                         // Include standard library
#include <math.h>                                                           // Include math library

/**
 * Compare function for qsort to sort subsets by size and then lexicographically
 * @param a Pointer to a pointer to an integer array
 * @param b Pointer to a pointer to an integer array
 * @return -1 if a < b, 0 if a == b, 1 if a > b
*/
int compare(const void *a, const void *b) {                                 // Pointer to a pointer to an integer array
    const int *ia = *(const int **)a;                                       // cast to pointer to int
    const int *ib = *(const int **)b;                                       // cast to pointer to int
    int sizeA = ia[0];                                                      // First element stores the size of the subset
    int sizeB = ib[0];                                                      // First element stores the size of the subset
    if (sizeA != sizeB) {                                                   // First compare by size
        return sizeA - sizeB;                                               // Smaller size comes first
    } else {                                                                // If sizes are equal
        for (int i = 1; i <= sizeA; ++i) {                                  // Then compare lexicographically
            if (ia[i] != ib[i]) {                                           // First difference determines order
                return ia[i] - ib[i];                                       // Smaller value comes first
            }
        }
    }
    return 0;                                                               // Both subsets are equal
}
/**
 * Function to generate all subsets of a set of n elements
 * @param n Number of elements in the set
 * @param subsets Pointer to a pointer to an integer array to store the subsets
 * @param pow_set_size Pointer to an unsigned int to store the size of the power set
 * @return void
 * @note The caller is responsible for freeing the memory allocated for the subsets
 *     using the freeSubsets function
 * @note The subsets are sorted by size and then lexicographically
 * @note The first element of each subset stores the size of the subset
*/
void generateSubsets(int n, int ***subsets, unsigned int *pow_set_size) {   // Pointer to a pointer to an integer array
    *pow_set_size = pow(2, n);                                              // Size of the power set is 2^n
    *subsets = (int **)malloc(*pow_set_size * sizeof(int *));               // Allocate memory for the power set
    int index = 0;                                                          // Index to store subsets

    for (unsigned int i = 0; i < *pow_set_size; i++) {                      // Generate all 2^n subsets
        (*subsets)[index] = (int *)malloc((n + 1) * sizeof(int));           // Allocate memory for each subset
        (*subsets)[index][0] = 0;                                           // First element stores the size of the subset
        for (int j = 0; j < n; j++) {                                       // Check each bit of the number
            if (i & (1 << j)) {                                             // If jth bit is set
                (*subsets)[index][++(*subsets)[index][0]] = j + 1;          // Add j+1 to the subset
            }
        }
        index++;                                                            // Move to the next subset
    }

    qsort(*subsets, *pow_set_size, sizeof(int *), compare);                 // Sort the subsets
}

/**
 * Function to free the memory allocated for the subsets
 * @param subsets Pointer to a pointer to an integer array
 * @param pow_set_size Size of the power set
 * @return void
*/
void freeSubsets(int **subsets, unsigned int pow_set_size) {                // Pointer to a pointer to an integer array
    for (unsigned int i = 0; i < pow_set_size; i++) {                       // Free memory for each subset
        free(subsets[i]);                                                   // Free memory for each subset
    }       
    free(subsets);                                                          // Free memory for the power set
}

/**
 * Function to print all subsets of a set of n elements
 * @param n Number of elements in the set
 * @return void
*/
void printSubsets(int n) {                                                  // Number of elements in the set
    unsigned int pow_set_size;                                              // Size of the power set
    int **subsets;                                                          // Pointer to a pointer to an integer array
    generateSubsets(n, &subsets, &pow_set_size);                            // Generate the subsets

    for (unsigned int i = 0; i < pow_set_size; i++) {                       // Print all subsets
        printf("Rank %d: {", i);                                            // Print the rank of the subset
        for (int j = 1; j <= subsets[i][0]; j++) {                          // Print the elements of the subset
            printf("%d", subsets[i][j]);                                    // Print the element
            if (j < subsets[i][0]) printf(", ");                            // Print comma if not the last element
        }
        printf("}\n");                                                      // Print the end of the subset
    }
    freeSubsets(subsets, pow_set_size);                                     // Free the memory allocated for the subsets
}

/**
 * Function to print the rank of a given subset
 * @param n Number of elements in the set
 * @param subset Pointer to an integer array to store the subset
 * @param subsetSize Size of the subset
 * @return void
*/
void printRank(int n, int *subset, int subsetSize) {                        // Pointer to an integer array
    unsigned int pow_set_size;                                              // Size of the power set
    int **subsets;                                                          // Pointer to a pointer to an integer array
    generateSubsets(n, &subsets, &pow_set_size);                            // Generate the subsets
    
    int rank = -1;                                                          // Initialize rank as -1 to indicate not found
    for (unsigned int i = 0; i < pow_set_size; i++) {                       // Find rank
        if (subsets[i][0] == subsetSize) {                                  // If the size of the subset matches
            int match = 1;                                                  // Assume it's a match
            for (int j = 1; j <= subsetSize; j++) {                         // Check each element of the subset
                if (subsets[i][j] != subset[j-1]) {                         // If any element does not match
                    match = 0;                                              // Not a match
                    break;                                                  // Break the loop
                }
            }
            if (match) {                                                    // If it's a match
                rank = i;                                                   // Store the rank
                break;                                                      // Break the loop
            }
        }
    }
    
    if (rank != -1) {                                                       // If the subset was found
        printf("Rank of the given subset is %d\n", rank);                   // Print the rank
    } else {                                                                // If the subset was not found
        printf("Given subset was not found.\n");                            // Print a message
    }
    
    freeSubsets(subsets, pow_set_size);                                     // Free the memory allocated for the subsets
}

/**
 * Function to print a subset given its rank
 * @param n Number of elements in the set
 * @param rank Rank of the subset to find
 * @return void
*/
void printUnrank(int n, int rank) {                                         // Rank of the subset to find
    unsigned int pow_set_size;                                              // Size of the power set
    int **subsets;                                                          // Pointer to a pointer to an integer array
    generateSubsets(n, &subsets, &pow_set_size);                            // Generate the subsets
    
    if (rank >= 0 && rank < pow_set_size) {                                 // If the rank is valid
        printf("Subset at rank %d is {", rank);                             // Print the rank of the subset
        for (int j = 1; j <= subsets[rank][0]; j++) {                       // Print the elements of the subset
            printf("%d", subsets[rank][j]);                                 // Print the element
            if (j < subsets[rank][0]) printf(", ");                         // Print comma if not the last element
        }
        printf("}\n");                                                      // Print the end of the subset
    } else {                                                                // If the rank is invalid
        printf("Invalid rank.\n");                                          // Print a message
    }
    
    freeSubsets(subsets, pow_set_size);                                     // Free the memory allocated for the subsets
}


void printSuccessor(int n, int *subset, int subsetSize) {                   // Pointer to an integer array
    unsigned int pow_set_size;                                              // Size of the power set
    int **subsets;                                                          // Pointer to a pointer to an integer array
    generateSubsets(n, &subsets, &pow_set_size);                            // Generate the subsets
    
    int rank = -1;                                                          // Initialize rank as -1 to indicate not found                                        

    for (unsigned int i = 0; i < pow_set_size; i++) {                       // Find rank
        if (subsets[i][0] == subsetSize) {                                  // If the size of the subset matches
            int match = 1;                                                  // Assume it's a match
            for (int j = 1; j <= subsetSize; j++) {                         // Check each element of the subset
                if (subsets[i][j] != subset[j-1]) {                         // If any element does not match
                    match = 0;                                              // Not a match
                    break;                                                  // Break the loop
                }
            }
            if (match) {                                                    // If it's a match
                rank = i;                                                   // Store the rank
                break;                                                      // Break the loop
            }       
        }
    }
    
    if (rank != -1 && rank + 1 < pow_set_size) {                            // If the subset was found and has a successor
        printf("Successor of the given subset is {");                       // Print the rank of the subset
        for (int j = 1; j <= subsets[rank + 1][0]; j++) {                   // Print the elements of the subset
            printf("%d", subsets[rank + 1][j]);                             // Print the element
            if (j < subsets[rank + 1][0]) printf(", ");                     // Print comma if not the last element
        }
        printf("}\n");                                                      // Print the end of the subset
    } else {                                                                // If the subset was not found or does not have a successor
        printf("Given subset does not have a successor.\n");                // Print a message
    }
    
    freeSubsets(subsets, pow_set_size);                                     // Free the memory allocated for the subsets
}

/**
 * Main function to demonstrate the subset generation and operations
 * @return 0
*/
int main() {
    int choice;                                                             // User choice
    int n, subsetSize, rank;                                                // Size of the set, size of the subset, rank of the subset
    int *subset;                                                            // Pointer to an integer array

    while (1) {                                                             // Loop until the user chooses to exit
        printf("\nMenu:\n");                                                // Print the menu
        printf("1. Generate and print all subsets/rank\n");                 // Print the menu
        printf("2. Find and print the rank of a given subset\n");           // Print the menu
        printf("3. Find and print a subset given its rank\n");              // Print the menu
        printf("4. Find and print the successor of a given subset\n");      // Print the menu
        printf("5. Exit\n");                                                // Print the menu
        printf("Enter your choice: ");                                      // Prompt the user for choice
        scanf("%d", &choice);                                               // Read the user choice

        switch (choice) {                                                   // Switch based on user choice
            case 1:                                                         // If the user chooses 1
                printf("Enter the size of the set (n): ");                  // Prompt the user for the size of the set
                scanf("%d", &n);                                            // Read the size of the set
                printSubsets(n);                                            // Print all subsets
                break;                                                      // Break the switch
            case 2:                                                         // If the user chooses 2
                printf("Enter the size of the set (n): ");                  // Prompt the user for the size of the set
                scanf("%d", &n);                                            // Read the size of the set
                printf("Enter the size of the subset: ");                   // Prompt the user for the size of the subset
                scanf("%d", &subsetSize);                                   // Read the size of the subset
                subset = (int *)malloc(subsetSize * sizeof(int));           // Allocate memory for the subset
                printf("Enter the elements of the subset: ");               // Prompt the user for the elements of the subset
                for (int i = 0; i < subsetSize; i++) {                      // Read the elements of the subset
                    scanf("%d", &subset[i]);                                // Read the element
                }
                printRank(n, subset, subsetSize);                           // Print the rank of the subset
                free(subset);                                               // Free the memory allocated for the subset
                break;                                                      // Break the switch               
            case 3:                                                         // If the user chooses 3
                printf("Enter the size of the set (n): ");                  // Prompt the user for the size of the set
                scanf("%d", &n);                                            // Read the size of the set
                printf("Enter the rank of the subset to find: ");           // Prompt the user for the rank of the subset
                scanf("%d", &rank);                                         // Read the rank of the subset
                printUnrank(n, rank);                                       // Print the subset given its rank
                break;                                                      // Break the switch
            case 4:                                                         // If the user chooses 4
                printf("Enter the size of the set (n): ");                  // Prompt the user for the size of the set
                scanf("%d", &n);                                            // Read the size of the set
                printf("Enter the size of the subset: ");                   // Prompt the user for the size of the subset
                scanf("%d", &subsetSize);                                   // Read the size of the subset
                subset = (int *)malloc(subsetSize * sizeof(int));           // Allocate memory for the subset
                printf("Enter the elements of the subset: ");               // Prompt the user for the elements of the subset
                for (int i = 0; i < subsetSize; i++) {                      // Read the elements of the subset
                    scanf("%d", &subset[i]);                                // Read the element
                }
                printSuccessor(n, subset, subsetSize);                      // Print the successor of the subset
                free(subset);                                               // Free the memory allocated for the subset
                break;                                                      // Break the switch 
            case 5:                                                         // If the user chooses 5
                printf("Exiting program.\n");                               // Print a message
                return 0;                                                   // Return 0 to indicate successful completion
            default:                                                        // If the user chooses an invalid option
                printf("Please enter a number between 1 and 5.\n");         // Print a message
        }
    }
    return 0;                                                               // Return 0 to indicate successful completion
}

