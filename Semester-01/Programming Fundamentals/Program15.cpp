// Program to calculate the total number of possible paths a salesman can travel, given n cities
// Author: Raees

#include <iostream>
using namespace std;

// Function to calculate factorial of a number
int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

// Function to calculate the total number of possible paths
int totalPaths(int n) {
    // The total number of possible paths is given by (n-1)!
    return factorial(n - 1);
}

int main() {
    int n;
    cout << "Enter the number of cities: ";
    cin >> n;

    int paths = totalPaths(n);
    cout << "The total number of possible paths is: " << paths << endl;

    return 0;
}