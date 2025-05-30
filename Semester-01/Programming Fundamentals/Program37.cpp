// Program to mask all but the last four characters of a string
// Author: Raees

#include <iostream>
#include <string>

using namespace std;

// Function to mask all but the last four characters of a string
std::string maskString(const std::string& str) {
    // If the string length is 4 or less, return the original string
    if (str.length() <= 4) {
        return str;
    }
    // Create a new string with '#' characters, leaving the last four characters unmasked
    std::string masked(str.length() - 4, '#');
    masked += str.substr(str.length() - 4); // Append the last four characters of the original string
    return masked; // Return the masked string
}

int main() {
    std::string input;
    cout << "Enter a string to mask: ";
    cin >> input; // Read input string from the user

    // Call the maskString function and store the result
    std::string maskedString = maskString(input);
    // Output the masked string
    cout << "Masked string: " << maskedString << endl;

    return 0; // Return 0 to indicate successful execution
}