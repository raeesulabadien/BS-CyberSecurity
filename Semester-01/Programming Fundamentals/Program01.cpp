#include <iostream>
#include <vector>

using namespace std;

// Program written by Raees 

// Function to generate an array of multiples of a given number
vector<int> arrayOfMultiples(int num, int length) {
    vector<int> multiples;
    for (int i = 1; i <= length; ++i) {
        multiples.push_back(num * i); // Add the multiple to the vector
    }
    return multiples;
}

int main() {
    int num = 5; // Number to generate multiples of
    int length = 10; // Number of multiples to generate
    vector<int> result = arrayOfMultiples(num, length); // Get the multiples

    // Print the multiples
    cout << "Multiples of " << num << " up to length " << length << " are: ";
    for (int i : result) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}