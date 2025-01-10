#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to find the length of the longest consecutive range in a vector of integers
/**
 * @brief Finds the length of the longest consecutive range in a given vector of integers.
 *
 * This function takes a vector of integers as input and returns the length of the longest
 * consecutive range of numbers within the vector. The input vector is first copied and sorted,
 * and then the function iterates through the sorted vector to determine the length of the longest
 * consecutive sequence of numbers.
 *
 * @param nums A vector of integers.
 * @return The length of the longest consecutive range of numbers in the input vector.
 *
 * @example
 * std::vector<int> nums = {100, 4, 200, 1, 3, 2};
 * int result = longestConsecutiveRange(nums);
 * // result will be 4, because the longest consecutive range is {1, 2, 3, 4}
 */
int longestConsecutiveRange(const vector<int>& nums) {
    // If the input vector is empty, return 0
    if (nums.empty()) return 0;

    // Create a copy of the input vector and sort it
    vector<int> sortedNums = nums;
    sort(sortedNums.begin(), sortedNums.end());

    int longestRange = 1; // Variable to store the length of the longest consecutive range
    int currentRange = 1; // Variable to store the length of the current consecutive range

    // Iterate through the sorted vector to find the longest consecutive range
    for (size_t i = 1; i < sortedNums.size(); ++i) {
        if (sortedNums[i] == sortedNums[i - 1] + 1) {
            // If the current element is consecutive to the previous one, increment the current range
            currentRange++;
        } else if (sortedNums[i] != sortedNums[i - 1]) {
            // If the current element is not consecutive and not a duplicate, update the longest range
            longestRange = max(longestRange, currentRange);
            currentRange = 1; // Reset the current range
        }
    }

    // Update the longest range for the last sequence
    longestRange = max(longestRange, currentRange);
    return longestRange;
}

int main() {
    // Example vector of integers
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    // Output the length of the longest consecutive range
    cout << "Longest consecutive range length: " << longestConsecutiveRange(nums) << endl;
    return 0;
}