#include <iostream>
#include <string>

using namespace std;

// Raees
// This program rearranges a string so that all vowels come first, followed by consonants and other characters.

// Function to check if a character is a vowel
bool isVowel(char c) {
    c = tolower(c); // Convert character to lowercase for uniformity
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

// Function to rearrange the string with vowels first and consonants (including non-vowel characters) second
string rearrangeString(const string& str) {
    string vowels, consonants;
    
    // Iterate through each character in the string
    for (char c : str) {
        if (isVowel(c)) {
            vowels += c; // Append to vowels string if character is a vowel
        } else {
            consonants += c; // Append to consonants string if character is not a vowel
        }
    }
    
    // Concatenate vowels and consonants strings
    return vowels + consonants;
}

int main() {
    string input = "Hello, World!"; // Input string
    string result = rearrangeString(input); // Get the rearranged string
    
    // Output the original and rearranged strings
    cout << "Original string: " << input << endl;
    cout << "Rearranged string: " << result << endl;
    
    return 0;
}