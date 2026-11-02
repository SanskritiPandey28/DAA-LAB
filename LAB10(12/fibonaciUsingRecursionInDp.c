#include <stdio.h>

int fib(int n, int dp[]) {
    if (n <= 1)
        return n;

    if (dp[n] != -1)
        return dp[n];

    dp[n] = fib(n - 1, dp) + fib(n - 2, dp);

    return dp[n];
}

int main() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);

    int dp[n + 1];

    for (int i = 0; i <= n; i++) {
        dp[i] = -1;
    }

    printf("Fibonacci number = %d\n", fib(n, dp));

    return 0;
}