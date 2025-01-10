#include <iostream>
#include <string>

using namespace std;

// Function to check if a character is a vowel
bool isVowel(char c) {
    c = tolower(c); // Convert character to lowercase for uniformity
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

// Function to rearrange the string with vowels first and consonants (including non-vowel characters) second
string rearrangeString(const string& str) {
    string vowels, consonants;
    
    for (char c : str) {
        if (isVowel(c)) {
            vowels += c;
        } else {
            consonants += c;
        }
    }
    
    return vowels + consonants;
}

int main() {
    string input = "Hello, World!";
    string result = rearrangeString(input);
    
    cout << "Original string: " << input << endl;
    cout << "Rearranged string: " << result << endl;
    
    return 0;
}