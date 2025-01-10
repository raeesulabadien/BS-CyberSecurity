#include <iostream>
#include <string>

using namespace std;

// Function to check if the characters in the string are in order
bool isOrdered(const string& str) {
    for (size_t i = 1; i < str.length(); ++i) {
        // If the current character is less than the previous character, return false
        if (str[i] < str[i - 1]) {
            return false;
        }
    }
    // If all characters are in order, return true
    return true;
}

int main() {
    string testStr;
    cout << "Enter a string: ";
    cin >> testStr;

    // Check if the characters in the string are in order and print the result
    if (isOrdered(testStr)) {
        cout << "The characters are in order." << endl;
    } else {
        cout << "The characters are not in order." << endl;
    }

    return 0;
}

// Code modified by Raees