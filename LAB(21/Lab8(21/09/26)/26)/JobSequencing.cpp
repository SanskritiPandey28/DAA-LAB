#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Job {
    char id;
    int deadline;
    int profit;
};

bool compare(Job a, Job b) {
    return a.profit > b.profit;
}

int main() {

    vector<Job> jobs = {
        {'A', 2, 100},
        {'B', 1, 19},
        {'C', 2, 27},
        {'D', 1, 25},
        {'E', 3, 15}
    };

    // Sort jobs according to profit
    sort(jobs.begin(), jobs.end(), compare);

    // Find maximum deadline
    int maxDeadline = 0;

    for (int i = 0; i < jobs.size(); i++) {
        maxDeadline = max(maxDeadline, jobs[i].deadline);
    }

    // Create slots
    vector<char> slot(maxDeadline + 1, '-');

    int totalProfit = 0;

    // Try to schedule every job
    for (int i = 0; i < jobs.size(); i++) {

        // Start from the job's deadline
        // and move backwards
        for (int j = jobs[i].deadline; j >= 1; j--) {

            if (slot[j] == '-') {

                slot[j] = jobs[i].id;
                totalProfit += jobs[i].profit;

                break;
            }
        }
    }

    cout << "Jobs scheduled: ";

    for (int i = 1; i <= maxDeadline; i++) {
        if (slot[i] != '-') {
            cout << slot[i] << " ";
        }
    }

    cout << endl;

    cout << "Maximum Profit = " << totalProfit << endl;

    return 0;
}