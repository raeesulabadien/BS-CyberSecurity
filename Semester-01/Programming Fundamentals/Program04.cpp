/**
 * @file Program04.cpp
 * @brief This program finds the length of the longest consecutive run in a vector of integers.
 * 
 * A consecutive run is defined as a list of adjacent, consecutive integers, which can be either increasing or decreasing.
 * If there are no consecutive runs (i.e., there is a gap between each integer), the function returns 1.
 * 
 * @author Raees
 * @date 10 Jan 2025
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * @brief Finds the length of the longest consecutive run in a vector of integers.
 * 
 * @param nums A vector of integers.
 * @return The length of the longest consecutive run.
 */
int longestConsecutiveRun(const vector<int>& nums) {
    if (nums.empty()) return 0;

    int maxLength = 1;        // Variable to store the maximum length of consecutive run found
    int currentLength = 1;    // Variable to store the current length of consecutive run

    for (size_t i = 1; i < nums.size(); ++i) {
        if (nums[i] == nums[i - 1] + 1 || nums[i] == nums[i - 1] - 1) {
            currentLength++;  // Increment current length if the current number is consecutive
        } else {
            maxLength = max(maxLength, currentLength);  // Update max length if current run ends
            currentLength = 1;  // Reset current length for the next run
        }
    }

    maxLength = max(maxLength, currentLength);  // Final check to update max length
    return maxLength;
}

/**
 * @brief Main function to test the longestConsecutiveRun function.
 * 
 * @return int Exit status of the program.
 */
int main() {
    vector<int> nums = {1, 2, 3, 5, 6, 7, 8, 10, 11, 12};
    cout << "Length of the longest consecutive run: " << longestConsecutiveRun(nums) << endl;
    return 0;
}