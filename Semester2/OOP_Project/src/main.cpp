#include "artwork.h"
#include "gallery.h"
#include <iostream>

using namespace std;

void showMenu() {
    cout << "\n=== Art Gallery ===" << endl;
    cout << "1. Show All Artworks" << endl;
    cout << "2. Search by Artist" << endl;
    cout << "3. Search by Category" << endl;
    cout << "4. Find by ID" << endl;
    cout << "5. Add New Artwork" << endl;
    cout << "6. Save to File" << endl;
    cout << "7. Exit" << endl;
    cout << "Choose option (1-7): ";
}

void addSampleData(Gallery& gallery) {
    gallery.addArtwork(Artwork(1, "Starry Night", "Van Gogh", "Impressionism", 100000000));
    gallery.addArtwork(Artwork(2, "Mona Lisa", "Da Vinci", "Renaissance", 850000000));
    gallery.addArtwork(Artwork(3, "The Scream", "Munch", "Expressionism", 120000000));
}

int main() {
    Gallery gallery("My Art Gallery");
    addSampleData(gallery);
    
    int choice;
    string searchText;
    int searchId;
    
    cout << "Welcome to the Simple Art Gallery!" << endl;
    
    while (true) {
        showMenu();
        cin >> choice;
        
        switch (choice) {
            case 1:
                gallery.showAll();
                break;
                
            case 2:
                cout << "Enter artist name: ";
                cin.ignore();
                getline(cin, searchText);
                gallery.searchByArtist(searchText);
                break;
                
            case 3:
                cout << "Enter category: ";
                cin.ignore();
                getline(cin, searchText);
                gallery.searchByCategory(searchText);
                break;
                
            case 4:
                cout << "Enter artwork ID: ";
                cin >> searchId;
                {
                    Artwork* found = gallery.findById(searchId);
                    if (found != nullptr) {
                        found->display();
                    } else {
                        cout << "Artwork not found!" << endl;
                    }
                }
                break;
                
            case 5:
                {
                    int id;
                    string title, artist, category;
                    double price;
                    
                    cout << "Enter ID: ";
                    cin >> id;
                    cout << "Enter title: ";
                    cin.ignore();
                    getline(cin, title);
                    cout << "Enter artist: ";
                    getline(cin, artist);
                    cout << "Enter category: ";
                    getline(cin, category);
                    cout << "Enter price: ";
                    cin >> price;
                    
                    gallery.addArtwork(Artwork(id, title, artist, category, price));
                    cout << "Artwork added successfully!" << endl;
                }
                break;
                
            case 6:
                gallery.saveToFile();
                break;
                
            case 7:
                cout << "Thank you for using Art Gallery!" << endl;
                return 0;
                
            default:
                cout << "Invalid choice! Try again." << endl;
        }
    }
    
    return 0;
}