#include <iostream>
#include <algorithm>

using namespace std;

int findDifference(int arr[], int size) {
    int minElement = *min_element(arr, arr + size);
    int maxElement = *max_element(arr, arr + size);
    return maxElement - minElement;
}

int main() {
    int arr[] = {10, 3, 5, 6, 2, 8, 1};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    int difference = findDifference(arr, size);
    
    cout << "The difference between the largest and smallest integers in the array is: " << difference << endl;
    
    return 0;
}
