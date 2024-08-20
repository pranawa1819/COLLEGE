#include <bits/stdc++.h>

using namespace std;

struct Item {
    int value, weight;

    // Constructor
    Item(int value, int weight)
        : value(value), weight(weight)
    {
    }
};

int c = 0;

bool cmp(struct Item a, struct Item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    c = c + 4;
    return r1 > r2;
}

double fractionalKnapsack(struct Item arr[], int N, int size) {
    // Sort Item based on value-to-weight ratio
    sort(arr, arr + size, cmp);

    // Current weight in knapsack
    int curWeight = 0;

    // Result (value in Knapsack)
    double finalvalue = 0.0;

    c += 2;
    for (int i = 0; i < size; i++) {
        if (curWeight + arr[i].weight <= N) {
            curWeight += arr[i].weight;
            finalvalue += arr[i].value;
            c += 4;
        } else {
            int remain = N - curWeight;
            finalvalue += arr[i].value * ((double)remain / arr[i].weight);
            c += 6;
            break;
        }
        c = c + 4;
    }

    // Returning final value
    return finalvalue;
}

// Driver Code
int main() {
    // Weight of knapsack
    int N = 11;

    // Given weights and values as pairs
    Item arr[] = {  {30, 3},
                { 18, 6 },
                { 25,2},
                { 15, 3} };

    int size = sizeof(arr) / sizeof(arr[0]);

    // Function Call
    cout << "Maximum profit earned = " << fractionalKnapsack(arr, N, size) << endl;
    cout << "No. of required steps : " << c << endl;
    return 0;
}
