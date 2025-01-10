/**
 * @file Program34.cpp
 * @brief This program finds the number that is not equal to the third number among three given numbers.
 * 
 * The function `findOther` takes three integers as input: `a`, `b`, and `c`. 
 * It returns the number that is not equal to `c` using bitwise XOR operation.
 * 
 * @param a First integer
 * @param b Second integer
 * @param c Third integer, which is equal to either `a` or `b`
 * @return The integer that is not equal to `c`
 * 
 * @note The function does not use any if statements or function calls.
 * 
 * Example usage:
 * @code
 * int a = 5, b = 10, c = 5;
 * cout << "The other number is: " << findOther(a, b, c) << endl; // Output: The other number is: 10
 * @endcode
 */
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