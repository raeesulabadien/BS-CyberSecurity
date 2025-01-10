// Program to count the number of syllables in a word
// Author: Raees

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// Function to count the number of syllables in a word
int countSyllables(const string& word) {
    return count(word.begin(), word.end(), '-') + 1;
}

int main() {
    string word;
    cout << "Enter a word with syllables separated by dashes: ";
    cin >> word;

    int syllableCount = countSyllables(word);
    cout << "The word '" << word << "' has " << syllableCount << " syllables." << endl;

    return 0;
}
