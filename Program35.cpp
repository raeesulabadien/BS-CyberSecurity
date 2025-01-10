#include <iostream>
using namespace std;

// Function to get the century from a given year
int getCentury(int year) {
    if (year >= 1000 && year <= 2010) {
        // Calculate the century
        return (year - 1) / 100 + 1;
    } else {
        // Return -1 for invalid year
        return -1;
    }
}

int main() {
    int year;
    cout << "Enter a year between 1000 and 2010: ";
    cin >> year;

    int century = getCentury(year);
    if (century != -1) {
        // Output the century
        cout << "The year " << year << " is in the " << century << "th century." << endl;
    } else {
        // Output an error message for invalid year
        cout << "Invalid year entered." << endl;
    }

    return 0;
}