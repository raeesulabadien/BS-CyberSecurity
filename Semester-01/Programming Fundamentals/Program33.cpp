#include <iostream>
#include <vector>

using namespace std;

// Function to find the length of the longest consecutive run in a vector
/**
 * @file Program33.cpp
 * @brief This program defines a function to find the length of the longest consecutive run in a vector of integers.
 *
 * The function `longestConsecutiveRun` takes a vector of integers as input and returns the length of the longest consecutive run of numbers.
 * A consecutive run is defined as a sequence of numbers where each number is either one more or one less than the previous number.
 *
 * @param nums A constant reference to a vector of integers.
 * @return An integer representing the length of the longest consecutive run in the input vector.
 */
int longestConsecutiveRun(const vector<int>& nums) {
    // If the vector is empty, return 0
    if (nums.empty()) return 0;

    int maxLength = 1; // Variable to store the maximum length of consecutive run
    int currentLength = 1; // Variable to store the current length of consecutive run

    // Loop through the vector starting from the second element
    for (size_t i = 1; i < nums.size(); ++i) {
        // Check if the current element is consecutive to the previous element
        if (nums[i] == nums[i - 1] + 1 || nums[i] == nums[i - 1] - 1) {
            currentLength++; // Increment the current length
        } else {
            // If the current length is greater than the maximum length, update the maximum length
            if (currentLength > maxLength) {
                maxLength = currentLength;
            }
            currentLength = 1; // Reset the current length
        }
    }

    // Final check to update the maximum length if the last run was the longest
    if (currentLength > maxLength) {
        maxLength = currentLength;
    }
    return maxLength; // Return the maximum length of consecutive run
}

int main() {
    vector<int> nums = {1, 2, 3, 5, 6, 7, 8, 10, 11, 12}; // Sample vector
    // Print the length of the longest consecutive run
    cout << "Length of the longest consecutive-run: " << longestConsecutiveRun(nums) << endl;
    return 0;
}