#include <iostream>
#include <vector>
using namespace std;

int fib(int n) {

    vector<int> dp(n + 1);

    dp[0] = 0;

    if (n >= 1) {
        dp[1] = 1;
    }

    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

int main() {

    int n;

    cout << "Enter n: ";
    cin >> n; 

    int ans = fib(n);

    cout << "Fibonacci number = " << ans << endl;

    return 0;
} 