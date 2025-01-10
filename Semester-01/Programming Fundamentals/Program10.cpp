// Program to check if an array is special
// Author: Raees

#include <iostream>
using namespace std;

// Function to check if the array is special
bool isSpecialArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        // Check if the element at even index is even
        if (i % 2 == 0 && arr[i] % 2 != 0) {
            return false;
        }
        // Check if the element at odd index is odd
        if (i % 2 != 0 && arr[i] % 2 == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int arr[] = {2, 3, 4, 5, 6, 7}; // Example array
    int size = sizeof(arr) / sizeof(arr[0]);

    if (isSpecialArray(arr, size)) {
        cout << "The array is special." << endl;
    } else {
        cout << "The array is not special." << endl;
    }

    return 0;
}