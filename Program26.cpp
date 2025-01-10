// Program to detect a hidden lowercase word amongst a crowd of uppercase letters
// Author: Raees

#include <iostream>
#include <string>

using namespace std;

// Function to detect the hidden word
string detectHiddenWord(const string& crowd) {
    string hiddenWord = "";
    for (char ch : crowd) {
        if (islower(ch)) {
            hiddenWord += ch;
        }
    }
    return hiddenWord;
}

int main() {
    string crowd;
    cout << "Enter the crowd of letters: ";
    cin >> crowd;

    string hiddenWord = detectHiddenWord(crowd);
    cout << "The hidden word is: " << hiddenWord << endl;

    return 0;
}