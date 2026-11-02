
#include <stdio.h>

// Factorial Without Recursion (Iterative)
int factorialIterative(int n) {
    int fact = 1;

    for (int i = 1; i <= n; i++) {
        fact = fact * i;
    }

    return fact;
}

// Factorial With Recursion
int factorialRecursive(int n) {
    if (n == 0 || n == 1)
        return 1;  // Base case

    return n * factorialRecursive(n - 1);
}

int main() {
    int n = 5;

    if (n < 0) {
        printf("Factorial is not defined for negative numbers.\n");
        return 0;
    }

    printf("Factorial without recursion = %d\n",
           factorialIterative(n));

    printf("Factorial with recursion = %d\n",
           factorialRecursive(n));

    return 0;
}
