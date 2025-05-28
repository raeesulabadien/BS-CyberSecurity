#include "artwork.h"
using namespace std;

Artwork::Artwork(int id, string title, string artist, string category, double price) {
    this->id = id;
    this->title = title;
    this->artist = artist;
    this->category = category;
    this->price = price;
}

int Artwork::getId() {
    return id;
}

string Artwork::getTitle() {
    return title;
}

string Artwork::getArtist() {
    return artist;
}

string Artwork::getCategory() {
    return category;
}

double Artwork::getPrice() {
    return price;
}

void Artwork::display() {
    cout << "ID: " << id << endl;
    cout << "Title: " << title << endl;
    cout << "Artist: " << artist << endl;
    cout << "Category: " << category << endl;
    cout << "Price: $" << price << endl;
    cout << "------------------------" << endl;
}