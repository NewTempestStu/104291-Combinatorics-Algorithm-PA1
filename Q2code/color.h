#ifndef COLOR_H
#define COLOR_H

typedef struct {
    int value;
    int color; // 0 or 1
} PermElement;

int factorial(int n);
int rank2ColoredPermutation(PermElement* perm, int n);
void printPermutations(PermElement **perms, int n, unsigned int perms_count);
void printUnrankedPermutation(int rank, int n);
void printSuccessor(PermElement *perm);
void printRank(int size, PermElement* perm);
void swap(PermElement *a, PermElement *b);
void generateAllColoredPermutations(int n, PermElement ***all_perms, unsigned int *perms_count);
void cleanupPermutations(PermElement **perms, unsigned int perms_count);

#endif // COLOR_H
