// Program06.cpp
// Author: Raees
// This program checks if all elements in a 4-element array are identical.

#include <iostream>
using namespace std;

bool isIdentical(const int arr[4]) {
    return arr[0] == arr[1] && arr[1] == arr[2] && arr[2] == arr[3];
}

int main() {
    int slotMachine[4] = {7, 7, 7, 7}; // Example array
    cout << (isIdentical(slotMachine) ? "All elements are identical." : "Elements are not identical.") << endl;
    return 0;
}
