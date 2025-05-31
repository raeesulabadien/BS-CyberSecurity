#ifndef GALLERY_H
#define GALLERY_H

#include "artwork.h"
#include "user.h"
#include <vector>
#include <string>

using namespace std;

// Gallery class manages a collection of artworks and users
class Gallery {
private:
    vector<Artwork> artworks;     // List of artworks
    vector<User> users;           // List of users
    string name;                  // Gallery name
    string currentUser;           // Currently logged in username
    bool isUserAdmin;             // Is current user an admin?

public:
    // Constructor
    Gallery(string name);
    
    // User management
    bool registerUser(const string& username, const string& password, bool isAdmin = false);
    bool login(const string& username, const string& password);
    void logout();
    bool isLoggedIn() const;
    bool isAdmin() const;
    string getCurrentUsername() const;
    
    // Artwork management
    bool addArtwork(const Artwork& artwork);
    void showAll() const;
    void searchByArtist(const string& artist) const;
    void searchByCategory(const string& category) const;
    Artwork* findById(int id);
    bool removeArtwork(int id);
    bool rateArtwork(int id, int rating);
    
    // Statistics
    void showStatistics() const;
    void showMostExpensiveArtwork() const;
    void showMostPopularArtist() const;
    
    // File operations
    bool saveToFile(const string& filename = "gallery_data.txt") const;
    bool loadFromFile(const string& filename = "gallery_data.txt");
    
    // Getters
    int getCount() const;
    string getName() const;
};

#endif
