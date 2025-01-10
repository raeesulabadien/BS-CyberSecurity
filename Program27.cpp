// Program to return the sum of the first n numbers in an array
// Author: Raees

#include <iostream>
using namespace std;

// Function to return the sum of the first n numbers in the array
int sumOfFirstN(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += arr[i];
    }
    return sum;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5}; // Example array
    int n = 3; // Number of elements to sum

    // Calculate and print the sum of the first n numbers
    cout << "Sum of first " << n << " numbers: " << sumOfFirstN(arr, n) << endl;

    return 0;
}