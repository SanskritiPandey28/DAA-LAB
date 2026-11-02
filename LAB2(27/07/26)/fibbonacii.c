// Without Recursion
#include <stdio.h>

int main() {
    int n;

    printf("Enter number of terms in Fibonacci series: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Please enter a positive number.");
        return 0;
    }

    int arr[n];

    arr[0] = 0;

    if (n > 1) {
        arr[1] = 1;
    }
    
    for (int i = 2; i < n; i++) {
        arr[i] = arr[i - 1] + arr[i - 2];
    }

    printf("Fibonacci Series: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}