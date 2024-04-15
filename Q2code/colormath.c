#include "color.h"

int factorial(int n) {
    int fact = 1;
    for (int i = 2; i <= n; i++)
        fact *= i;
    return fact;
}

// Utility function to swap PermElement values
void swap(PermElement *a, PermElement *b) {
    PermElement temp = *a;
    *a = *b;
    *b = temp;
}