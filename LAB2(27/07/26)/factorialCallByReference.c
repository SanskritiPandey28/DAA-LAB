// WAP to execute factorial of a number using call by reference

#include <stdio.h>

void factorial(int n, int *fact) {
    if (n == 0 || n == 1) {
        *fact = 1;
    } else {
        factorial(n - 1, fact);
        *fact = (*fact) * n;
    }
}



int main() {
    int n, ans;

    printf("Enter number you want to find factorial: ");
    scanf("%d", &n);

    factorial(n, &ans);

    printf("Factorial is %d", ans);

    return 0;
}