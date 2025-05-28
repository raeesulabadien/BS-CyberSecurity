#ifndef ARTWORK_H
#define ARTWORK_H

#include <string>
#include <iostream>

using namespace std;

class Artwork {
private:
    int id;
    string title;
    string artist;
    string category;
    double price;

public:
    // Simple constructor
    Artwork(int id, string title, string artist, string category, double price);
    
    // Simple getters
    int getId();
    string getTitle();
    string getArtist();
    string getCategory();
    double getPrice();
    
    // Simple display
    void display();
};

#endif