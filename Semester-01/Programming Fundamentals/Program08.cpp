#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string wordSearch;
    char letter;

    cout << "Enter the word search: ";
    getline(cin, wordSearch);

    cout << "Enter the letter to search for: ";
    cin >> letter;
    int count = std::count(wordSearch.begin(), wordSearch.end(), letter);
    cout << "The letter '" << letter << "' appears " << count << " times in the word search." << endl;

    return 0;
}
