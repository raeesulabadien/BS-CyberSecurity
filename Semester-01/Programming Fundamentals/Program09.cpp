// Program09.cpp
// Author: Raees
// This program checks if one array can be nested inside another array

#include <iostream>
#include <algorithm>
using namespace std;

// Function to check if arr1 can be nested inside arr2
bool canBeNested(int arr1[], int size1, int arr2[], int size2) {
    int min1 = *min_element(arr1, arr1 + size1);
    int max1 = *max_element(arr1, arr1 + size1);
    int min2 = *min_element(arr2, arr2 + size2);
    int max2 = *max_element(arr2, arr2 + size2);

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