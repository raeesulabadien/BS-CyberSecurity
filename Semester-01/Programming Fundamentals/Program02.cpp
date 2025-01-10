// Program to count the number of 1s in a 2D array
// Author: Raees

#include <iostream>
using namespace std;

// Function to count the number of 1s in a 2D array
int countOnes(int arr[][4], int rows, int cols) {
    int count = 0;
    // Loop through each element in the array
    for(int i = 0; i < rows; ++i) {
        for(int j = 0; j < cols; ++j) {
            // If the element is 1, increment the count
            if(arr[i][j] == 1) {
                ++count;
            }
        }
    }
    return count;
}

int main() {
    // Initialize a 3x4 array with some values
    int arr[3][4] = {
        {1, 0, 1, 0},
        {0, 1, 1, 0},
        {1, 0, 0, 1}
    };
    int rows = 3;
    int cols = 4;
    // Output the number of 1s in the array
    cout << "Number of 1s in the array: " << countOnes(arr, rows, cols) << endl;
    return 0;
}