#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

// Function to calculate the cumulative sum of a vector of integers
vector<int> cumulativeSum(const vector<int>& numbers) {
    vector<int> result(numbers.size());
    // Using partial_sum to calculate the cumulative sum
    partial_sum(numbers.begin(), numbers.end(), result.begin());
    return result;
}

int main() {
    // Initialize a vector with some numbers
    vector<int> numbers = {1, 2, 3, 4, 5};
    // Calculate the cumulative sum
    vector<int> result = cumulativeSum(numbers);

    // Output the cumulative sum
    cout << "Cumulative sum: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

// Code written by Raees
