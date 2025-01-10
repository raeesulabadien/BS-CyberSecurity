// Program07.cpp
// Author: Raees
// This program defines a function that takes two numbers and returns their sum as a binary string.

#include <iostream>
#include <string>
#include <bitset>

// Function to convert an integer to a binary string
std::string toBinaryString(int num) {
    return std::bitset<32>(num).to_string();
}

// Function to add two numbers and return their sum as a binary string
std::string addNumbersAsBinary(int num1, int num2) {
    int sum = num1 + num2;
    return toBinaryString(sum);
}

int main() {
    int number1 = 5;
    int number2 = 3;
    std::string binarySum = addNumbersAsBinary(number1, number2);
    std::cout << "The sum of " << number1 << " and " << number2 << " in binary is: " << binarySum << std::endl;
    return 0;
}