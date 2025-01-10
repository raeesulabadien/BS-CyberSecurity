#include <iostream>
using namespace std;

// Function to check if the array is special
bool isSpecialArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 != i % 2) {
            return false;
        }
    }
    return true;
}

int main() {
    int arr[] = {2, 3, 4, 5, 6, 7}; // Example array
    int size = sizeof(arr) / sizeof(arr[0]);

    if (isSpecialArray(arr, size)) {
        cout << "The array is special." << endl;
    } else {
        cout << "The array is not special." << endl;
    }

    return 0;
}
