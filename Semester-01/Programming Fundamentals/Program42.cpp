// Program to check if all elements in a slot machine outcome array are identical
// Author: Raees

#include <iostream>
using namespace std;

// Function to check if all elements in the array are identical
bool isJackpot(int arr[], int size) {
    for (int i = 1; i < size; ++i) {
        if (arr[i] != arr[0]) {
            return false; // Return false if any element is different
        }
    }
    return true; // Return true if all elements are identical
}

int main() {
    int slotMachineOutcome[4] = {7, 7, 7, 7}; // Example input
    if (isJackpot(slotMachineOutcome, 4)) {
        cout << "Jackpot!" << endl; // Output if all elements are identical
    } else {
        cout << "Try again!" << endl; // Output if any element is different
    }
    return 0;
}