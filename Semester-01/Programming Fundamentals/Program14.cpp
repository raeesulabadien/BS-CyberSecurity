// Program14.cpp
// Author: Raees
// This program contains a function that counts the number of syllables in a word.
// Each syllable is separated with a dash.

#include <iostream>
#include <string>

using namespace std;

// Function to count the number of syllables in a word
int countSyllables(const string& word) {
    int count = 1; // Start with 1 because the last syllable won't have a dash after it
    for (char ch : word) {
        if (ch == '-') {
            count++;
        }
    }
    return count;
}

int main() {
    string word;
    cout << "Enter a word with syllables separated by dashes: ";
    cin >> word;

    int syllableCount = countSyllables(word);
    cout << "The word '" << word << "' has " << syllableCount << " syllables." << endl;

    return 0;
}