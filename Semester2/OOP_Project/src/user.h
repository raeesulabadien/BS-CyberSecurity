#ifndef USER_H
#define USER_H

#include <string>
#include <functional>

using namespace std;

// User class for authentication and access control
class User {
private:
    string username;     // Username for login
    string passwordHash; // Hashed password (for security)
    bool isAdmin;        // Admin flag for special permissions
    
    // Simple hash function for passwords
    string hashPassword(const string& password);

public:
    // Constructor
    User(string username, string password, bool isAdmin = false);
    
    // Getters
    string getUsername() const;
    bool checkPassword(const string& password) const;
    bool getIsAdmin() const;
};

#endif
