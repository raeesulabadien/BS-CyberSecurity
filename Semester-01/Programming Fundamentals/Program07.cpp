// Program07.cpp
// Author: Raees
// This program defines a function that takes two numbers and returns their sum as a binary string.

#include <iostream>
#include <string>

using namespace std;

// Function to convert an integer to a binary string
string toBinaryString(int num) {
    string binary = "";
    while (num > 0) {
        binary = (num % 2 == 0 ? "0" : "1") + binary;
        num /= 2;
    }
    return binary.empty() ? "0" : binary;
}

// Function to add two numbers and return their sum as a binary string
string addNumbersAsBinary(int num1, int num2) {
    int sum = num1 + num2;
    return toBinaryString(sum);
}

int main() {
    int number1 = 5;
    int number2 = 3;
    string binarySum = addNumbersAsBinary(number1, number2);
    cout << "The sum of " << number1 << " and " << number2 << " in binary is: " << binarySum << endl;
    return 0;
}