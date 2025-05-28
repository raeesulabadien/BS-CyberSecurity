#ifndef ARTWORK_H
#define ARTWORK_H

#include <string>
#include <iostream>

class Artwork {
private:
    int id;
    std::string title;
    std::string artist;
    std::string category;
    std::string description;
    std::string imageUrl;
    double price;

public:
    // Constructor
    Artwork(int id, const std::string& title, const std::string& artist, 
            const std::string& category, const std::string& description, 
            const std::string& imageUrl, double price);
    
    // Getters
    int getId() const;
    std::string getTitle() const;
    std::string getArtist() const;
    std::string getCategory() const;
    std::string getDescription() const;
    std::string getImageUrl() const;
    double getPrice() const;
    
    // Display artwork details
    void displayInfo() const;
    
    // Convert to JSON format for web display
    std::string toJson() const;
};

#endif