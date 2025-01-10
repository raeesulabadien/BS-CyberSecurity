// Program to find the difference between the largest and smallest integers in an array
// Author: Raees

#include <iostream>
#include <algorithm> // for std::min_element and std::max_element

using namespace std;

int findDifference(int arr[], int size) {
    // Find the smallest element in the array
    int minElement = *min_element(arr, arr + size);
    
    // Find the largest element in the array
    int maxElement = *max_element(arr, arr + size);
    
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