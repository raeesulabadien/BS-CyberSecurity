#ifndef ARTWORK_H
#define ARTWORK_H

#include <string>
#include <iostream>
#include <vector>

using namespace std;

// Artwork class stores information about a single artwork
class Artwork {
private:
    int id;                 // Unique identifier
    string title;           // Title of the artwork
    string artist;          // Artist name
    string category;        // Art category (e.g. Impressionism)
    double price;           // Price in dollars
    string description;     // Brief description of the artwork
    vector<int> ratings;    // List of ratings (1-5 stars)
    
public:
    // Constructor
    Artwork(int id, string title, string artist, string category, double price, string description = "");
    
    // Basic getters
    int getId() const;
    string getTitle() const;
    string getArtist() const;
    string getCategory() const;
    double getPrice() const;
    string getDescription() const;
    
    // Rating functions
    void addRating(int rating);          // Add a new rating (1-5)
    double getAverageRating() const;     // Get average of all ratings
    int getRatingCount() const;          // Get number of ratings
    
    // Display methods
    void display() const;                // Simple display
    void displayDetailed() const;        // Detailed display
};

#endif
