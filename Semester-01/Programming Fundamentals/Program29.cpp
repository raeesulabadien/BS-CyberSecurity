#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int longestConsecutiveRange(const vector<int>& nums) {
    if (nums.empty()) return 0;

    vector<int> sortedNums = nums;
    sort(sortedNums.begin(), sortedNums.end());

    int longestRange = 1;
    int currentRange = 1;

    for (size_t i = 1; i < sortedNums.size(); ++i) {
        if (sortedNums[i] == sortedNums[i - 1] + 1) {
            currentRange++;
        } else if (sortedNums[i] != sortedNums[i - 1]) {
            longestRange = max(longestRange, currentRange);
            currentRange = 1;
        }
    }

    longestRange = max(longestRange, currentRange);
    return longestRange;
}

int main() {
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    cout << "Longest consecutive range length: " << longestConsecutiveRange(nums) << endl;
    return 0;
}
