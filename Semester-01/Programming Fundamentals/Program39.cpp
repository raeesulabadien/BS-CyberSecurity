#include <iostream>
#include <string>

using namespace std;

// Author: [Raees]
// Function to repeat each character in the input string
string repeatCharacters(const string& input) {
    string result;
    for (char c : input) {
        result += c;
        result += c;
    }
    return result;
}

int main() {
    string input = "hello";
    string output = repeatCharacters(input);
    
    // Print the original and modified strings
    cout << "Original string: " << input << endl;
    cout << "Modified string: " << output << endl;
    
    return 0;
}