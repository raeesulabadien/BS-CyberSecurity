#include <iostream>
#include <numeric>

using namespace std;

// Function to calculate the cumulative sum of an array of integers
void cumulativeSum(const int* numbers, int* result, int size) {
    result[0] = numbers[0];
    for (int i = 1; i < size; ++i) {
        result[i] = result[i - 1] + numbers[i];
    }
}

int main() {
    // Initialize an array with some numbers
    int numbers[] = {1, 2, 3, 4, 5};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    int result[size];

    // Calculate the cumulative sum
    cumulativeSum(numbers, result, size);

    // Output the cumulative sum
    cout << "Cumulative sum: ";
    for (int i = 0; i < size; ++i) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
