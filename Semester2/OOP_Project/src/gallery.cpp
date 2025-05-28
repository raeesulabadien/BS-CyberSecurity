#include "gallery.h"
#include <fstream>

using namespace std;

Gallery::Gallery(string name) {
    this->name = name;
}

void Gallery::addArtwork(Artwork artwork) {
    artworks.push_back(artwork);
}

void Gallery::showAll() {
    cout << "\n=== " << name << " ===" << endl;
    cout << "Total Artworks: " << artworks.size() << endl;
    cout << endl;
    
    for (int i = 0; i < artworks.size(); i++) {
        artworks[i].display();
    }
}

void Gallery::searchByArtist(string artist) {
    cout << "\nSearching for artist: " << artist << endl;
    bool found = false;
    
    for (int i = 0; i < artworks.size(); i++) {
        if (artworks[i].getArtist() == artist) {
            artworks[i].display();
            found = true;
        }
    }
    
    if (!found) {
        cout << "No artworks found by " << artist << endl;
    }
}

void Gallery::searchByCategory(string category) {
    cout << "\nSearching for category: " << category << endl;
    bool found = false;
    
    for (int i = 0; i < artworks.size(); i++) {
        if (artworks[i].getCategory() == category) {
            artworks[i].display();
            found = true;
        }
    }
    
    if (!found) {
        cout << "No artworks found in " << category << endl;
    }
}

Artwork* Gallery::findById(int id) {
    for (int i = 0; i < artworks.size(); i++) {
        if (artworks[i].getId() == id) {
            return &artworks[i];
        }
    }
    return nullptr;
}

void Gallery::saveToFile() {
    ofstream file("gallery_data.txt");
    
    file << name << endl;
    file << artworks.size() << endl;
    
    for (int i = 0; i < artworks.size(); i++) {
        file << artworks[i].getId() << endl;
        file << artworks[i].getTitle() << endl;
        file << artworks[i].getArtist() << endl;
        file << artworks[i].getCategory() << endl;
        file << artworks[i].getPrice() << endl;
    }
    
    file.close();
    cout << "Gallery saved to gallery_data.txt" << endl;
}

int Gallery::getCount() {
    return artworks.size();
}

string Gallery::getName() {
    return name;
}