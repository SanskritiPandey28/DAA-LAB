#include <stdio.h>
#include <limits.h>

int matrixChain(int p[], int n) {
    int dp[n][n];

    // Cost of multiplying a single matrix is 0
    for (int i = 1; i < n; i++) {
        dp[i][i] = 0;
    }

    // len is the number of matrices in the chain
    for (int len = 2; len < n; len++) {
        for (int i = 1; i < n - len + 1; i++) {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;

            for (int k = i; k < j; k++) {
                int cost = dp[i][k]
                         + dp[k + 1][j]
                         + p[i - 1] * p[k] * p[j];

                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                }
            }
        }
    }

    return dp[1][n - 1];
}

int main() {
    int p[] = {10, 30, 5, 60};
    int n = sizeof(p) / sizeof(p[0]);

    printf("Minimum number of multiplications = %d\n",
           matrixChain(p, n));

    return 0;
}