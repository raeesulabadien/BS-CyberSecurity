// This program counts the number of prime numbers up to a given integer n

// Include necessary libraries
#include <iostream>
#include <cmath>

using namespace std;

// Function to check if a number is prime
bool isPrime(int num) {
    if (num <= 1) return false; // Numbers less than or equal to 1 are not prime
    if (num <= 3) return true;  // 2 and 3 are prime numbers
    if (num % 2 == 0 || num % 3 == 0) return false; // Eliminate multiples of 2 and 3
    for (int i = 5; i * i <= num; i += 6) { // Check for factors from 5 onwards
        if (num % i == 0 || num % (i + 2) == 0) return false; // Check divisibility
    }
    return true; // If no factors found, the number is prime
}

// Function to count the number of prime numbers up to n
int countPrimes(int n) {
    int count = 0; // Initialize prime count
    for (int i = 2; i <= n; ++i) { // Iterate from 2 to n
        if (isPrime(i)) { // Check if the number is prime
            ++count; // Increment count if prime
        }
    }
    return count; // Return the total count of prime numbers
}

// Main function
int main() {
    int n; // Variable to store user input
    cout << "Enter an integer: "; // Prompt user for input
    cin >> n; // Read user input
    cout << "Number of prime numbers up to " << n << " is: " << countPrimes(n) << endl; // Output result
    return 0; // End of program
}
