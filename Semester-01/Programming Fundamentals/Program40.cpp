#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// Function to reverse a given string
string reverseString(const string& str) {
    string reversedStr = str;
    reverse(reversedStr.begin(), reversedStr.end());
    return reversedStr;
}

int main() {
    string input;
    cout << "Enter a string: ";
    getline(cin, input);

    // Call the reverseString function and store the result
    string reversed = reverseString(input);
    cout << "Reversed string: " << reversed << endl;

    return 0;
}

// Program written by Raees