// Program to reverse a string using recursion
// Author: Raees

#include <iostream>
#include <string>

using namespace std;

// Function to reverse a string recursively
string reverseString(const string &str) {
    // Base case: if the string is empty or has only one character
    if (str.empty() || str.size() == 1) {
        return str;
    }
    // Recursive case: reverse the substring excluding the first character
    // and append the first character at the end
    return reverseString(str.substr(1)) + str[0];
}

int main() {
    string input = "Hello, World!";
    string reversed = reverseString(input);
    cout << "Original string: " << input << endl;
    cout << "Reversed string: " << reversed << endl;
    return 0;
}