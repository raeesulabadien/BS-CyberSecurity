// Program to perform even-odd transform on an array n times
// Author: Raees

#include <iostream>

using namespace std;

void evenOddTransform(int arr[], int size, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < size; ++j) {
            if (arr[j] % 2 == 0) {
                arr[j] -= 2; // Subtract 2 from even integers
            } else {
                arr[j] += 2; // Add 2 to odd integers
            }
        }
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    int n = 3; // Number of transformations

    evenOddTransform(arr, size, n);

    // Print the transformed array
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }

    return 0;
}