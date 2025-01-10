// Program to find the missing number in an array of numbers between 1 and 10
// Author: Raees

#include <iostream>
using namespace std;

// Function to find the missing number
int findMissingNumber(int arr[], int size) {
    int totalSum = 55; // Sum of numbers from 1 to 10
    int arrSum = 0;

    for (int i = 0; i < size; i++) {
        arrSum += arr[i];
    }

    return totalSum - arrSum;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 10}; // Example array with 9 elements
    int size = sizeof(arr) / sizeof(arr[0]);

    int missingNumber = findMissingNumber(arr, size);

    cout << "The missing number is: " << missingNumber << endl;

    return 0;
}