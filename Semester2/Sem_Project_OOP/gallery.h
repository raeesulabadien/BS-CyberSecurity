#ifndef GALLERY_H
#define GALLERY_H

#include "artwork.h"
#include <vector>
#include <memory>

class Gallery {
private:
    std::vector<std::unique_ptr<Artwork>> artworks;
    std::string galleryName;

public:
    // Constructor
    Gallery(const std::string& name);
    
    // Add artwork
    void addArtwork(std::unique_ptr<Artwork> artwork);
    
    // Display all artworks
    void displayAllArtworks() const;
    
    // Search by category
    std::vector<Artwork*> getArtworksByCategory(const std::string& category) const;
    
    // Search by artist
    std::vector<Artwork*> getArtworksByArtist(const std::string& artist) const;
    
    // Get artwork by ID
    Artwork* getArtworkById(int id) const;
    
    // Get all artworks
    const std::vector<std::unique_ptr<Artwork>>& getAllArtworks() const;
    
    // Export to JSON file for web display
    void exportToJson(const std::string& filename) const;
    
    // Get gallery name
    std::string getName() const;
    
    // Get total artworks count
    size_t getArtworkCount() const;
};

#endif