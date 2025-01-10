// Program05.cpp
// Author: Raees
// This program defines a function that takes two numbers as arguments (num, length)
// and returns an array of multiples of num until the array length reaches length.

#include <iostream>
#include <vector>

std::vector<int> arrayOfMultiples(int num, int length) {
    std::vector<int> multiples(length);
    for (int i = 0; i < length; ++i) {
        multiples[i] = num * (i + 1);
    }
    return multiples;
}

int main() {
    int num = 5;
    int length = 10;
    std::vector<int> result = arrayOfMultiples(num, length);

    std::cout << "Multiples of " << num << " up to length " << length << " are: ";
    for (int multiple : result) {
        std::cout << multiple << " ";
    }
    std::cout << std::endl;

    return 0;
}