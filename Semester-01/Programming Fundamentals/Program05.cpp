// Program05.cpp
// Author: Raees
// This program defines a function that takes two numbers as arguments (num, length)
// and prints multiples of num until the count reaches length.

#include <iostream>

void printMultiples(int num, int length) {
    for (int i = 1; i <= length; ++i) {
        std::cout << num * i << " ";
    }
    std::cout << std::endl;
}

int main() {
    int num = 5;
    int length = 10;

    std::cout << "Multiples of " << num << " up to length " << length << " are: ";
    printMultiples(num, length);

    return 0;
}
