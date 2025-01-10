// Program08.cpp
// Author: Raees
// This program contains a function that counts the number of times a particular letter shows up in a word search.

#include <iostream>
#include <string>

using namespace std;

// Function to count the number of times a particular letter shows up in the word search
int countLetterOccurrences(const string& wordSearch, char letter) {
    int count = 0;
    for (char ch : wordSearch) {
        if (ch == letter) {
            count++;
        }
    }
    return count;
}

int main() {
    string wordSearch;
    char letter;

    cout << "Enter the word search: ";
    getline(cin, wordSearch);

    cout << "Enter the letter to search for: ";
    cin >> letter;

    int occurrences = countLetterOccurrences(wordSearch, letter);
    cout << "The letter '" << letter << "' appears " << occurrences << " times in the word search." << endl;

    return 0;
}