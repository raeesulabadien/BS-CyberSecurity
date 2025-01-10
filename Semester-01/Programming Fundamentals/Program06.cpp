// Program06.cpp
// Author: Raees
// This program contains a function that checks if all elements in a 4-element array are identical.

#include <iostream>
using namespace std;

bool isIdentical(int arr[4]) {
    for (int i = 1; i < 4; ++i) {
        if (arr[i] != arr[0]) {
            return false;
        }
    }
    return true;
}

int main() {
    int slotMachine[4] = {7, 7, 7, 7}; // Example array
    if (isIdentical(slotMachine)) {
        cout << "All elements are identical." << endl;
    } else {
        cout << "Elements are not identical." << endl;
    }
    return 0;
}