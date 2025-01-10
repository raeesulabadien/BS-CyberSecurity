// This program calculates the minimum number of swaps needed to convert one binary string into another of the same length.
// Written by Raees

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// Function to calculate the minimum number of swaps needed to convert str1 to str2
int minSwapsToConvert(const string& str1, const string& str2) {
    if (str1.length() != str2.length()) {
        return -1; // Strings of different lengths cannot be converted
    }

    int count1 = 0, count2 = 0;
    for (size_t i = 0; i < str1.length(); ++i) {
        if (str1[i] != str2[i]) {
            if (str1[i] == '1') {
                ++count1; // Count mismatched 1s in str1
            } else {
                ++count2; // Count mismatched 0s in str1
            }
        }
    }

    if (count1 != count2) {
        return -1; // Unequal number of 1s and 0s cannot be converted
    }

    return count1; // Minimum number of swaps needed
}

int main() {
    string str1 = "1100";
    string str2 = "1001";

    int result = minSwapsToConvert(str1, str2);
    if (result != -1) {
        cout << "Minimum number of swaps: " << result << endl;
    } else {
        cout << "Conversion is not possible." << endl;
    }

    return 0;
}