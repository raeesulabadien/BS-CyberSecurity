// This program checks if a given password is valid based on certain criteria.
#include <iostream>
#include <string>
#include <cctype>
#include <unordered_set>

using namespace std;

bool isValidPassword(const string& password) {
    if (password.length() < 6 || password.length() > 24) {
        return false;
    }

    bool hasUpper = false, hasLower = false, hasDigit = false;
    unordered_set<char> specialChars = {'@', '#', '$', '%', '^', '&', '*', '(', ')', '+', '{', '}', '[', ']', ':', ';', '"', '\'', '?', '<', '>', ',', '.'};

    int repeatCount = 1;
    for (size_t i = 0; i < password.length(); ++i) {
        if (isupper(password[i])) hasUpper = true;
        if (islower(password[i])) hasLower = true;
        if (isdigit(password[i])) hasDigit = true;
        if (specialChars.find(password[i]) == specialChars.end() && !isalnum(password[i])) {
            return false;
        }

        if (i > 0 && password[i] == password[i - 1]) {
            repeatCount++;
            if (repeatCount > 2) {
                return false;
            }
        } else {
            repeatCount = 1;
        }
    }

    return hasUpper && hasLower && hasDigit;
}

int main() {
    string password;
    cout << "Enter password: ";
    cin >> password;

    if (isValidPassword(password)) {
        cout << "Password is valid." << endl;
    } else {
        cout << "Password is invalid." << endl;
    }

    return 0;
}