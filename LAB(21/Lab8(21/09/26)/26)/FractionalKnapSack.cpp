#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item {
    int weight;
    int value;
    double ratio;
};

bool compare(Item a, Item b) {
    return a.ratio > b.ratio;
}

int main() {

    vector<Item> items = {
        {10, 60, 0},
        {20, 100, 0},
        {30, 120, 0}
    };

    int capacity = 50;

    // Calculate value/weight ratio
    for (int i = 0; i < items.size(); i++) {
        items[i].ratio = (double)items[i].value / items[i].weight;
    }

    // Sort according to ratio
    sort(items.begin(), items.end(), compare);

    double totalValue = 0;

    // Take items
    for (int i = 0; i < items.size(); i++) {

        // If complete item can fit
        if (items[i].weight <= capacity) {

            capacity = capacity - items[i].weight;
            totalValue = totalValue + items[i].value;
        }

        // If complete item cannot fit
        else {

            // Take only the fraction that fits
            totalValue = totalValue +
                         items[i].ratio * capacity;

            capacity = 0;

            break;
        }
    }

    cout << "Maximum value = " << totalValue << endl;

    return 0;
}