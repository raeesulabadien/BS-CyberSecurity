// Program to validate an email address
// Author: Raees

#include <iostream>
#include <string>

using namespace std;

// Function to check if the given email address is valid
bool isValidEmail(const std::string& email) {
    size_t atPos = email.find('@');
    size_t dotPos = email.find('.', atPos);

    // Check if '@' is present and not at the start
    if (atPos == std::string::npos || atPos == 0) {
        return false;
    }

    // Check if '.' is present after '@' and not at the end
    if (dotPos == std::string::npos || dotPos <= atPos + 1 || dotPos == email.length() - 1) {
        return false;
    }

    return true;
}

int main() {
    std::string email;
    cout << "Enter an email address: ";
    cin >> email;

    // Check if the email address is valid and print the result
    if (isValidEmail(email)) {
        cout << "The email address is valid." << endl;
    } else {
        cout << "The email address is invalid." << endl;
    }

    return 0;
}