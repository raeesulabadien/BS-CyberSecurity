// Program to calculate the value of x in a simple algebraic equation
// Author: Raees

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

// Function to calculate the value of x
int calculateX(const string& equation) {
    int x = 0;
    int currentNumber = 0;
    char operation = '+';
    stringstream ss(equation);

    while (ss >> currentNumber) {
        if (operation == '+') {
            x += currentNumber;
        } else if (operation == '-') {
            x -= currentNumber;
        }
        ss >> operation;
    }

    return x;
}

int main() {
    string equation;
    
    // Input the algebraic equation
    cout << "Enter the algebraic equation: ";
    getline(cin, equation);

    // Calculate and display the value of x
    int result = calculateX(equation);
    cout << "The value of x is: " << result << endl;

    return 0;
}