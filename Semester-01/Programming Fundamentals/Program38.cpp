#include <iostream>
#include <sstream>
#include <string>

using namespace std;

// Program to count the number of words in a sentence
// Author: Raees

// Function to count the number of words in a sentence
int wordCount(const string& sentence) {
    istringstream stream(sentence); // Create a string stream from the sentence
    string word;
    int count = 0;
    // Extract words from the stream and count them
    while (stream >> word) {
        count++;
    }
    return count; // Return the word count
}

int main() {
    string sentence = "This is a sample sentence."; // Sample sentence
    // Output the word count of the sample sentence
    cout << "Word count: " << wordCount(sentence) << endl;
    return 0;
}