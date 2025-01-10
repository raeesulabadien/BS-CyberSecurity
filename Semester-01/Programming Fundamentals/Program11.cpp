// Program to count the number of syllables in a word
// Author: Raees

#include <iostream>
#include <string>
using namespace std;

// Function to count the number of syllables in a word
int countSyllables(const string& word) {
    int count = 1; // Start with 1 because the first syllable doesn't have a dash before it
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