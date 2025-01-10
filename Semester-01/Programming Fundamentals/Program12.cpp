// Program to find the difference between the largest and smallest integers in an array
// Author: Raees

#include <iostream>

using namespace std;

int findDifference(int arr[], int size) {
    // Initialize minElement and maxElement with the first element of the array
    int minElement = arr[0];
    int maxElement = arr[0];
    
    // Traverse the array to find the smallest and largest elements
    for (int i = 1; i < size; ++i) {
        if (arr[i] < minElement) {
            minElement = arr[i];
        }
        if (arr[i] > maxElement) {
            maxElement = arr[i];
        }
    }
    
    // Return the difference between the largest and smallest elements
    return maxElement - minElement;
}

int main() {
    int arr[] = {10, 3, 5, 6, 2, 8, 1};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    int difference = findDifference(arr, size);
    
    cout << "The difference between the largest and smallest integers in the array is: " << difference << endl;
    
    return 0;
}