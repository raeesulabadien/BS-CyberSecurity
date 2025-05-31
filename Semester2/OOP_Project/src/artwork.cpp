#include "artwork.h"
#include <numeric>    // For accumulate
#include <iomanip>    // For setprecision

// Constructor
Artwork::Artwork(int id, string title, string artist, string category, double price, string description) {
    this->id = id;
    this->title = title;
    this->artist = artist;
    this->category = category;
    this->price = price;
    this->description = description;
}

// Get artwork ID
int Artwork::getId() const {
    return id;
}

// Get artwork title
string Artwork::getTitle() const {
    return title;
}

// Get artist name
string Artwork::getArtist() const {
    return artist;
}

// Get artwork category
string Artwork::getCategory() const {
    return category;
}

// Get artwork price
double Artwork::getPrice() const {
    return price;
}

// Get artwork description
string Artwork::getDescription() const {
    return description;
}

// Add a new rating (1-5 stars)
void Artwork::addRating(int rating) {
    // Only accept ratings between 1 and 5
    if (rating >= 1 && rating <= 5) {
        ratings.push_back(rating);
    }
}

// Calculate the average rating
double Artwork::getAverageRating() const {
    if (ratings.empty()) {
        return 0.0;  // No ratings yet
    }
    
    // Sum all ratings and divide by count
    double sum = 0.0;
    for (int rating : ratings) {
        sum += rating;
    }
    return sum / ratings.size();
}

// Get the number of ratings
int Artwork::getRatingCount() const {
    return ratings.size();
}

// Display basic artwork information
void Artwork::display() const {
    cout << "ID: " << id << endl;
    cout << "Title: " << title << endl;
    cout << "Artist: " << artist << endl;
    cout << "Category: " << category << endl;
    cout << "Price: $" << fixed << setprecision(2) << price << endl;
    
    // Show rating if available
    if (!ratings.empty()) {
        cout << "Rating: " << fixed << setprecision(1) << getAverageRating() 
             << "/5.0 (" << ratings.size() << " reviews)" << endl;
    }
    
    cout << "------------------------" << endl;
}

// Display detailed artwork information
void Artwork::displayDetailed() const {
    display();  // Show basic info first
    
    // Show additional details
    if (!description.empty()) {
        cout << "Description: " << description << endl;
    }
    
    cout << "------------------------" << endl;
}
