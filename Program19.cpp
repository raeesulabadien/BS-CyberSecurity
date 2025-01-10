// Program to sort an array and remove all duplicate items
// Author: Raees

#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<int> arrayToSet(vector<int> arr) {
    // Use a set to remove duplicates and sort the array
    set<int> s(arr.begin(), arr.end());
    
    // Convert the set back to a vector
    vector<int> result(s.begin(), s.end());
    
    return result;
}

int main() {
    vector<int> originalArray = {1, 3, 3, 5, 5, 5};
    
    vector<int> setArray = arrayToSet(originalArray);
    
    // Print the result
    cout << "Original array transformed into a set: ";
    for (int num : setArray) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}
