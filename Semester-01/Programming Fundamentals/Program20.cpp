// Program to perform even-odd transform on an array n times
// Author: Raees

#include <iostream>
#include <vector>

using namespace std;

void evenOddTransform(vector<int>& arr, int n) {
    for (int i = 0; i < n; ++i) {
        for (int& num : arr) {
            if (num % 2 == 0) {
                num -= 2; // Subtract 2 from even integers
            } else {
                num += 2; // Add 2 to odd integers
            }
        }
    }
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    int n = 3; // Number of transformations

    evenOddTransform(arr, n);

    // Print the transformed array
    for (int num : arr) {
        cout << num << " ";
    }

    return 0;
}