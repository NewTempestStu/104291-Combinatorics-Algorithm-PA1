#include "color.h"

int factorial(int n) {
    int fact = 1;
    for (int i = 2; i <= n; i++)
        fact *= i;
    return fact;
}

typedef struct {
    int value;
    int color; // 0 or 1
} PermElement;
