#include "artwork.h"
#include <iomanip>
#include <sstream>

Artwork::Artwork(int id, const std::string& title, const std::string& artist, 
                 const std::string& category, const std::string& description, 
                 const std::string& imageUrl, double price)
    : id(id), title(title), artist(artist), category(category), 
      description(description), imageUrl(imageUrl), price(price) {}

int Artwork::getId() const { return id; }
std::string Artwork::getTitle() const { return title; }
std::string Artwork::getArtist() const { return artist; }
std::string Artwork::getCategory() const { return category; }
std::string Artwork::getDescription() const { return description; }
std::string Artwork::getImageUrl() const { return imageUrl; }
double Artwork::getPrice() const { return price; }

void Artwork::displayInfo() const {
    std::cout << "\n--- Artwork Details ---\n";
    std::cout << "ID: " << id << "\n";
    std::cout << "Title: " << title << "\n";
    std::cout << "Artist: " << artist << "\n";
    std::cout << "Category: " << category << "\n";
    std::cout << "Description: " << description << "\n";
    std::cout << "Price: $" << std::fixed << std::setprecision(2) << price << "\n";
    std::cout << "Image URL: " << imageUrl << "\n";
}

std::string Artwork::toJson() const {
    std::ostringstream json;
    json << "{"
         << "\"id\":" << id << ","
         << "\"title\":\"" << title << "\","
         << "\"artist\":\"" << artist << "\","
         << "\"category\":\"" << category << "\","
         << "\"description\":\"" << description << "\","
         << "\"imageUrl\":\"" << imageUrl << "\","
         << "\"price\":" << std::fixed << std::setprecision(2) << price
         << "}";
    return json.str();
}