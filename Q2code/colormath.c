#include "color.h"

int factorial(int n) {
    int fact = 1;
    for (int i = 2; i <= n; i++)
        fact *= i;
    return fact;
}

// Define a structure for a permutation element with color.
typedef struct {
    int value; // The value of the permutation element.
    int color; // The color of the element, 0 or 1.
} PermElement;
