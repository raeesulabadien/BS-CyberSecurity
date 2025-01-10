#include <iostream>

using namespace std;

// Program written by Raees 

// Function to print multiples of a given number
void printMultiples(int num, int length) {
    for (int i = 1; i <= length; ++i) {
        cout << num * i << " "; // Print the multiple
    }
    cout << endl;
}

int main() {
    int num = 5; // Number to generate multiples of
    int length = 10; // Number of multiples to generate

    // Print the multiples
    cout << "Multiples of " << num << " up to length " << length << " are: ";
    printMultiples(num, length);

    return 0;
}
