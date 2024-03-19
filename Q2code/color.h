#ifndef COLOR_H
#define COLOR_H

typedef struct {
    int value;
    int color; // 0 or 1
} PermElement;

int factorial(int n);
int rank2ColoredPermutation(PermElement* perm, int n);
void unrank2ColoredPermutation(int rank, int n, PermElement *perm)

#endif // COLOR_H
