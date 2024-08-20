#include<iostream>
using namespace std;

int countSteps = 0;  // To count the number of recursive steps

// Function to implement the Extended Euclidean Algorithm
int gcdExtended(int a, int b, int *x, int *y){
    countSteps++;  // Increment step count each time this function is called

    if (a == 0){
        *x = 0;
        *y = 1;
        return b;
    }
    
    int x1, y1;  // To store results of recursive call
    int gcd = gcdExtended(b % a, a, &x1, &y1);
    
    *x = y1 - (b / a) * x1;
    *y = x1;
    
    return gcd;
}

int main() {
    int a, b, x, y;

    // Taking input from the user
    cout << "Enter two integers to find GCD: ";
    cin >> a >> b;

    // Calling gcdExtended
    int g = gcdExtended(a, b, &x, &y);

    // Outputting the result in a proper format
    cout << "GCD of " << a << " and " << b << " is: " << g << endl;
    cout << "Coefficients x and y are: " << x << " and " << y << endl;
    cout << "Number of recursive steps: " << countSteps << endl;

    return 0;
}
