#include "gallery.h"
#include <fstream>
#include <iostream>
#include <algorithm>

Gallery::Gallery(const std::string& name) : galleryName(name) {}

void Gallery::addArtwork(std::unique_ptr<Artwork> artwork) {
    artworks.push_back(std::move(artwork));
}

void Gallery::displayAllArtworks() const {
    std::cout << "\n=== " << galleryName << " Gallery ===\n";
    std::cout << "Total Artworks: " << artworks.size() << "\n";
    
    for (const auto& artwork : artworks) {
        artwork->displayInfo();
        std::cout << "------------------------\n";
    }
}

std::vector<Artwork*> Gallery::getArtworksByCategory(const std::string& category) const {
    std::vector<Artwork*> result;
    for (const auto& artwork : artworks) {
        if (artwork->getCategory() == category) {
            result.push_back(artwork.get());
        }
    }
    return result;
}

std::vector<Artwork*> Gallery::getArtworksByArtist(const std::string& artist) const {
    std::vector<Artwork*> result;
    for (const auto& artwork : artworks) {
        if (artwork->getArtist() == artist) {
            result.push_back(artwork.get());
        }
    }
    return result;
}

Artwork* Gallery::getArtworkById(int id) const {
    for (const auto& artwork : artworks) {
        if (artwork->getId() == id) {
            return artwork.get();
        }
    }
    return nullptr;
}

const std::vector<std::unique_ptr<Artwork>>& Gallery::getAllArtworks() const {
    return artworks;
}

void Gallery::exportToJson(const std::string& filename) const {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return;
    }
    
    file << "{\n";
    file << "  \"galleryName\": \"" << galleryName << "\",\n";
    file << "  \"artworks\": [\n";
    
    for (size_t i = 0; i < artworks.size(); ++i) {
        file << "    " << artworks[i]->toJson();
        if (i < artworks.size() - 1) {
            file << ",";
        }
        file << "\n";
    }
    
    file << "  ]\n";
    file << "}\n";
    
    file.close();
    std::cout << "Gallery data exported to " << filename << std::endl;
}

std::string Gallery::getName() const {
    return galleryName;
}

size_t Gallery::getArtworkCount() const {
    return artworks.size();
}