// Program to check if Sam and Frodo are side by side in the array
// Author: Raees

#include <iostream>
#include <string>

using namespace std;

bool areSamAndFrodoClose(const string names[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        if ((names[i] == "Sam" && names[i + 1] == "Frodo") || 
            (names[i] == "Frodo" && names[i + 1] == "Sam")) {
            return true;
        }
    }
    return false;
}

int main() {
    string names[] = {"Gandalf", "Sam", "Frodo", "Aragorn"};
    int size = sizeof(names) / sizeof(names[0]);
    if (areSamAndFrodoClose(names, size)) {
        cout << "Sam and Frodo are close." << endl;
    } else {
        cout << "Sam and Frodo are not close." << endl;
    }
    return 0;
}