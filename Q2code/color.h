#ifndef COLOR_H
#define COLOR_H

typedef struct {
    int value;
    int color; // 0 or 1
} PermElement;

int factorial(int n);
int rank2ColoredPermutation(PermElement* perm, int n);
void printUnrankedPermutation(int rank, int n);
void printSuccessor(PermElement *perm);
void printRank(int size, PermElement* perm);

#endif // COLOR_H
