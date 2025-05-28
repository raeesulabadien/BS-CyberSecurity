#ifndef GALLERY_H
#define GALLERY_H

#include "artwork.h"
#include <vector>

using namespace std;

class Gallery {
private:
    vector<Artwork> artworks;
    string name;

public:
    // Simple constructor
    Gallery(string name);
    
    // Basic operations
    void addArtwork(Artwork artwork);
    void showAll();
    void searchByArtist(string artist);
    void searchByCategory(string category);
    Artwork* findById(int id);
    
    // File operations
    void saveToFile();
    
    // Simple getters
    int getCount();
    string getName();
};

#endif