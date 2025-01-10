// Program to implement Caesar Cipher encryption
// This program takes a text input and a rotation factor from the user
// and outputs the encrypted text using the Caesar Cipher technique.

#include <iostream>
#include <string>

using namespace std;

string caesarCipher(const string &s, int k) {
    string result = "";
    k = k % 26; // Ensure the rotation factor is within the range of the alphabet

    for (char c : s) {
        if (isalpha(c)) {
            char base = islower(c) ? 'a' : 'A';
            result += (c - base + k) % 26 + base;
        } else {
            result += c; // Non-alphabetic characters are not changed
        }
    }

    return result;
}

int main() {
    string text;
    int rotationFactor;

    cout << "Enter the text to be encrypted: ";
    getline(cin, text);

    cout << "Enter the rotation factor: ";
    cin >> rotationFactor;

    string encryptedText = caesarCipher(text, rotationFactor);
    cout << "Encrypted text: " << encryptedText << endl;

    return 0;
}