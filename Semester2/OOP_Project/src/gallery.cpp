#include "gallery.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>
#include <iomanip>

using namespace std;

// Constructor
Gallery::Gallery(string name) {
    this->name = name;
    this->currentUser = "";
    this->isUserAdmin = false;
}

// Register a new user
bool Gallery::registerUser(const string& username, const string& password, bool isAdmin) {
    // Check if username already exists
    for (const User& user : users) {
        if (user.getUsername() == username) {
            return false;  // Username already taken
        }
    }
    
    // Add new user
    users.push_back(User(username, password, isAdmin));
    return true;
}

// Log in a user
bool Gallery::login(const string& username, const string& password) {
    for (const User& user : users) {
        if (user.getUsername() == username && user.checkPassword(password)) {
            currentUser = username;
            isUserAdmin = user.getIsAdmin();
            return true;  // Login successful
        }
    }
    return false;  // Login failed
}

// Log out the current user
void Gallery::logout() {
    currentUser = "";
    isUserAdmin = false;
}

// Check if a user is logged in
bool Gallery::isLoggedIn() const {
    return !currentUser.empty();
}

// Check if current user is an admin
bool Gallery::isAdmin() const {
    return isLoggedIn() && isUserAdmin;
}

// Get current username
string Gallery::getCurrentUsername() const {
    return currentUser;
}

// Add a new artwork to the gallery
bool Gallery::addArtwork(const Artwork& artwork) {
    // Check if artwork ID already exists
    for (const Artwork& art : artworks) {
        if (art.getId() == artwork.getId()) {
            return false;  // ID already exists
        }
    }
    
    artworks.push_back(artwork);
    return true;
}

// Show all artworks in the gallery
void Gallery::showAll() const {
    cout << "\n=== " << name << " ===" << endl;
    cout << "Total Artworks: " << artworks.size() << endl;
    cout << endl;
    
    for (const Artwork& artwork : artworks) {
        artwork.display();
    }
}

// Search artworks by artist name
void Gallery::searchByArtist(const string& artist) const {
    cout << "\nSearching for artist: " << artist << endl;
    bool found = false;
    
    for (const Artwork& artwork : artworks) {
        if (artwork.getArtist() == artist) {
            artwork.display();
            found = true;
        }
    }
    
    if (!found) {
        cout << "No artworks found by " << artist << endl;
    }
}

// Search artworks by category
void Gallery::searchByCategory(const string& category) const {
    cout << "\nSearching for category: " << category << endl;
    bool found = false;
    
    for (const Artwork& artwork : artworks) {
        if (artwork.getCategory() == category) {
            artwork.display();
            found = true;
        }
    }
    
    if (!found) {
        cout << "No artworks found in " << category << endl;
    }
}

// Find an artwork by ID
Artwork* Gallery::findById(int id) {
    for (int i = 0; i < artworks.size(); i++) {
        if (artworks[i].getId() == id) {
            return &artworks[i];
        }
    }
    return nullptr;  // Not found
}

// Remove an artwork by ID
bool Gallery::removeArtwork(int id) {
    for (int i = 0; i < artworks.size(); i++) {
        if (artworks[i].getId() == id) {
            artworks.erase(artworks.begin() + i);
            return true;
        }
    }
    return false;  // Artwork not found
}

// Rate an artwork
bool Gallery::rateArtwork(int id, int rating) {
    Artwork* artwork = findById(id);
    if (artwork != nullptr) {
        artwork->addRating(rating);
        return true;
    }
    return false;  // Artwork not found
}

// Show gallery statistics
void Gallery::showStatistics() const {
    if (artworks.empty()) {
        cout << "\nNo artworks in the gallery." << endl;
        return;
    }
    
    cout << "\n=== Gallery Statistics ===" << endl;
    cout << "Total artworks: " << artworks.size() << endl;
    
    // Calculate total value
    double totalValue = 0;
    for (const Artwork& artwork : artworks) {
        totalValue += artwork.getPrice();
    }
    
    cout << "Total value: $" << fixed << setprecision(2) << totalValue << endl;
    cout << "Average value: $" << fixed << setprecision(2) << totalValue / artworks.size() << endl;
    
    // Find most expensive artwork
    showMostExpensiveArtwork();
    
    // Find most popular artist
    showMostPopularArtist();
}

// Show the most expensive artwork
void Gallery::showMostExpensiveArtwork() const {
    if (artworks.empty()) {
        return;
    }
    
    // Find artwork with highest price
    const Artwork* mostExpensive = &artworks[0];
    for (const Artwork& artwork : artworks) {
        if (artwork.getPrice() > mostExpensive->getPrice()) {
            mostExpensive = &artwork;
        }
    }
    
    cout << "\nMost expensive artwork:" << endl;
    mostExpensive->display();
}

// Show the most popular artist
void Gallery::showMostPopularArtist() const {
    if (artworks.empty()) {
        return;
    }
    
    // Count artworks by artist
    map<string, int> artistCounts;
    for (const Artwork& artwork : artworks) {
        artistCounts[artwork.getArtist()]++;
    }
    
    // Find artist with most artworks
    string mostPopular = artworks[0].getArtist();
    int maxCount = artistCounts[mostPopular];
    
    for (const auto& pair : artistCounts) {
        if (pair.second > maxCount) {
            mostPopular = pair.first;
            maxCount = pair.second;
        }
    }
    
    cout << "Most popular artist: " << mostPopular << " (" << maxCount << " artworks)" << endl;
}

// Save gallery data to a file
bool Gallery::saveToFile(const string& filename) const {
    ofstream file(filename);
    
    if (!file.is_open()) {
        cout << "Error: Could not open file for saving." << endl;
        return false;
    }
    
    file << name << endl;
    file << artworks.size() << endl;
    
    for (const Artwork& artwork : artworks) {
        file << artwork.getId() << endl;
        file << artwork.getTitle() << endl;
        file << artwork.getArtist() << endl;
        file << artwork.getCategory() << endl;
        file << artwork.getPrice() << endl;
        file << artwork.getDescription() << endl;
    }
    
    file.close();
    cout << "Gallery saved to " << filename << endl;
    return true;
}

// Load gallery data from a file
bool Gallery::loadFromFile(const string& filename) {
    ifstream file(filename);
    
    if (!file.is_open()) {
        cout << "Error: Could not open file for loading." << endl;
        return false;
    }
    
    string galleryName;
    getline(file, galleryName);
    name = galleryName;
    
    int artworkCount;
    file >> artworkCount;
    file.ignore();  // Skip newline
    
    artworks.clear();  // Clear existing artworks
    
    for (int i = 0; i < artworkCount; i++) {
        int id;
        string title, artist, category, description;
        double price;
        
        file >> id;
        file.ignore();  // Skip newline
        
        getline(file, title);
        getline(file, artist);
        getline(file, category);
        
        file >> price;
        file.ignore();  // Skip newline
        
        getline(file, description);
        
        artworks.push_back(Artwork(id, title, artist, category, price, description));
    }
    
    file.close();
    cout << "Gallery loaded from " << filename << endl;
    return true;
}

// Get artwork count
int Gallery::getCount() const {
    return artworks.size();
}

// Get gallery name
string Gallery::getName() const {
    return name;
}
