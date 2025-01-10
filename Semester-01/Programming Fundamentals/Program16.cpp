// Program16.cpp
// Author: Raees

#include <iostream>
using namespace std;

int countEqual(int a, int b, int c) {
    if (a == b && b == c) {
        return 3;
    } else if (a == b || b == c || a == c) {
        return 2;
    } else {
        return 0;
    }
}

int main() {
    int a, b, c;
    cout << "Enter three integers: ";
    cin >> a >> b >> c;
    cout << "Number of equal integers: " << countEqual(a, b, c) << endl;
    return 0;
}