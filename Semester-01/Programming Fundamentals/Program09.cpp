// Program09.cpp
// Author: Raees
// This program checks if one array can be nested inside another array

#include <iostream>
using namespace std;

// Function to find the minimum element in an array
int findMin(int arr[], int size) {
    int min = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

// Function to find the maximum element in an array
int findMax(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Function to check if arr1 can be nested inside arr2
bool canBeNested(int arr1[], int size1, int arr2[], int size2) {
    int min1 = findMin(arr1, size1);
    int max1 = findMax(arr1, size1);
    int min2 = findMin(arr2, size2);
    int max2 = findMax(arr2, size2);

    return (min1 > min2 && max1 < max2);
}

int main() {
    int arr1[] = {3, 5, 7};
    int arr2[] = {1, 8, 10};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    if (canBeNested(arr1, size1, arr2, size2)) {
        cout << "arr1 can be nested inside arr2" << endl;
    } else {
        cout << "arr1 cannot be nested inside arr2" << endl;
    }

    return 0;
}