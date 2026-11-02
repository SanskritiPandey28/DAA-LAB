
#include <bits/stdc++.h>
using namespace std;

int main() {
    int p[4];

    // Dimensions:
    // A1 = p[0] x p[1]
    // A2 = p[1] x p[2]
    // A3 = p[2] x p[3]

    cout << "Enter 4 dimensions: ";
    for (int i = 0; i < 4; i++) {
        cin >> p[i];
    }

    // Sequence 1: (A1 * A2) * A3
    int cost1 = p[0] * p[1] * p[2]
              + p[0] * p[2] * p[3];

    // Sequence 2: A1 * (A2 * A3)
    int cost2 = p[1] * p[2] * p[3]
              + p[0] * p[1] * p[3];

    cout << "Cost of (A1*A2)*A3 = " << cost1 << endl;
    cout << "Cost of A1*(A2*A3) = " << cost2 << endl;

    cout << "Minimum cost = " << min(cost1, cost2) << endl;

    if (cost1 < cost2)
        cout << "Best sequence: (A1*A2)*A3";
    else if (cost2 < cost1)
        cout << "Best sequence: A1*(A2*A3)";
    else
        cout << "Both sequences have equal cost";

    return 0;
}
