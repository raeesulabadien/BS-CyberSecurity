// Program to check if Sam and Frodo are side by side in the array
// Author: Raees

#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool areSamAndFrodoClose(const vector<string>& names) {
    for (size_t i = 0; i < names.size() - 1; ++i) {
        if ((names[i] == "Sam" && names[i + 1] == "Frodo") || 
            (names[i] == "Frodo" && names[i + 1] == "Sam")) {
            return true;
        }
    }
    return false;
}

int main() {
    vector<string> names = {"Gandalf", "Sam", "Frodo", "Aragorn"};
    if (areSamAndFrodoClose(names)) {
        cout << "Sam and Frodo are close." << endl;
    } else {
        cout << "Sam and Frodo are not close." << endl;
    }
    return 0;
}