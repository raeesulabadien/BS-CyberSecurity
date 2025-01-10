// Program to calculate the sum of the absolute values of elements in an array
// Author: Raees

#include <iostream>
#include <cmath> // For std::abs

using namespace std;

int sumOfAbsoluteValues(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += abs(arr[i]);
    }
    return sum;
}

int main() {
    int arr[] = {-1, -2, 3, 4, -5};
    int size = sizeof(arr) / sizeof(arr[0]);

    int result = sumOfAbsoluteValues(arr, size);
    cout << "The sum of the absolute values is: " << result << endl;

    return 0;
}