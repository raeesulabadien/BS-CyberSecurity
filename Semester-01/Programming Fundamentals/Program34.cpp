// Program to find the number that is not equal to the third number among three given numbers. 
//Author: Raees
#include <iostream>

using namespace std;

int findOther(int a, int b, int c) {
    return a ^ b ^ c;
}

int main() {
    int a = 5, b = 10, c = 5;
    cout << "The other number is: " << findOther(a, b, c) << endl;
    return 0;
}
