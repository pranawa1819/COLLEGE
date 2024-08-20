#include <iostream>
#include <vector>

using namespace std;

struct Item {
    int value, weight;
    Item(int value, int weight) : value(value), weight(weight) {}
};

// Global variable to store the maximum value obtained
int maxProfit = 0;

// Backtracking function to solve the 0/1 Knapsack problem
void knapsackBacktrack(int i, int curWeight, int curValue, int W, vector<Item>& items) {
    // Base case: if we've considered all items
    if (i == items.size()) {
        if (curValue > maxProfit) {
            maxProfit = curValue;  // Update maxProfit if a better value is found
        }
        return;
    }

    // Recursive case: include the current item if possible
    if (curWeight + items[i].weight <= W) {
        knapsackBacktrack(i + 1, curWeight + items[i].weight, curValue + items[i].value, W, items);
    }

    // Recursive case: exclude the current item
    knapsackBacktrack(i + 1, curWeight, curValue, W, items);
}

int main() {
    int n, W;
    
    // Input number of items and the knapsack capacity
    cout << "Enter the number of items: ";
    cin >> n;
    cout << "Enter the weight capacity of the knapsack: ";
    cin >> W;

    vector<Item> items;
    
    // Input item values and weights
    cout << "Enter the values and weights of the items:" << endl;
    for (int i = 0; i < n; i++) {
        int value, weight;
        cin >> value >> weight;
        items.push_back(Item(value, weight));
    }

    // Solve the problem using backtracking
    knapsackBacktrack(0, 0, 0, W, items);

    // Output the maximum value that can be obtained
    cout << "The maximum value that can be obtained is: " << maxProfit << endl;

    return 0;
}
