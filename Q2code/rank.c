#include <stdio.h>
#include <stdlib.h>
#include "color.h"

// Calculate the rank of the permutation (ignoring color)
int permutationRank(PermElement* perm, int n) {
    int rank = 0;
    for (int i = 0; i < n; i++) {
        int smaller = 0; // Count elements smaller than perm[i]
        for (int j = i + 1; j < n; j++) {
            if (perm[j].value < perm[i].value)
                smaller++;
        }
        rank += smaller * factorial(n - i - 1);
    }
    return rank;
}

// Print the rank of the permutation
void printRank(int size, PermElement* perm) {
    printf("Rank of the permutation: %d\n", permutationRank(perm, size));
}

// Calculate color rank adjustment
int colorRankAdjustment(PermElement* perm, int n) {
    int adjustment = 0;
    for (int i = 0; i < n; i++) {
        adjustment = adjustment * 2 + perm[i].color;
    }
    return adjustment;
}

// Combined rank function
int rank2ColoredPermutation(PermElement* perm, int n) {
    int permRank = permutationRank(perm, n);
    int colorAdjustment = colorRankAdjustment(perm, n);
    return permRank * (1 << n) + colorAdjustment; // 1 << n is 2^n
}