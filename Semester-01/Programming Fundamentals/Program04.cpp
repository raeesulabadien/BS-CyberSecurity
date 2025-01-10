#include <iostream>

using namespace std;

// Program to find the length of the longest consecutive run in an array

int longestConsecutiveRun(const int nums[], int size) {
    if (size == 0) return 0;

    int maxLength = 1;
    int currentLength = 1;

    for (int i = 1; i < size; ++i) {
        if (nums[i] == nums[i - 1] + 1 || nums[i] == nums[i - 1] - 1) {
            currentLength++;
        } else {
            if (currentLength > maxLength) {
                maxLength = currentLength;
            }
            currentLength = 1;
        }
    }

    if (currentLength > maxLength) {
        maxLength = currentLength;
    }
    return maxLength;
}

int main() {
    int nums[] = {1, 2, 3, 5, 6, 7, 8, 10, 11, 12};
    int size = sizeof(nums) / sizeof(nums[0]);
    cout << "Length of the longest consecutive run: " << longestConsecutiveRun(nums, size) << endl;
    return 0;
}
