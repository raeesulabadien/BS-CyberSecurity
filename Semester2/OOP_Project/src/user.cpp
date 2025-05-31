#include "user.h"
#include <iostream>

// Simple hash function for passwords
string User::hashPassword(const string& password) {
    // Using std::hash for simplicity
    // Note: In a real app, you'd use a more secure hashing algorithm
    size_t hashValue = hash<string>{}(password);
    return to_string(hashValue);
}

// Constructor
User::User(string username, string password, bool isAdmin) {
    this->username = username;
    this->passwordHash = hashPassword(password);
    this->isAdmin = isAdmin;
}

// Get username
string User::getUsername() const {
    return username;
}

// Check if password matches
bool User::checkPassword(const string& password) const {
    return hashPassword(password) == passwordHash;
}

// Check if user is an admin
bool User::getIsAdmin() const {
    return isAdmin;
}
