#include "gallery.h"
#include <iostream>
#include <limits>

using namespace std;

// Show the login menu
void showLoginMenu() {
    cout << "\n=== Art Gallery Login ===" << endl;
    cout << "1. Login" << endl;
    cout << "2. Register" << endl;
    cout << "3. Exit" << endl;
    cout << "Choose option (1-3): ";
}

// Show the user menu
void showUserMenu() {
    cout << "\n=== Art Gallery - User Menu ===" << endl;
    cout << "1. Show All Artworks" << endl;
    cout << "2. Search by Artist" << endl;
    cout << "3. Search by Category" << endl;
    cout << "4. Find Artwork by ID" << endl;
    cout << "5. Rate an Artwork" << endl;
    cout << "6. View Statistics" << endl;
    cout << "7. Logout" << endl;
    cout << "Choose option (1-7): ";
}

// Show the admin menu
void showAdminMenu() {
    cout << "\n=== Art Gallery - Admin Menu ===" << endl;
    cout << "1. Show All Artworks" << endl;
    cout << "2. Search by Artist" << endl;
    cout << "3. Search by Category" << endl;
    cout << "4. Find Artwork by ID" << endl;
    cout << "5. Add New Artwork" << endl;
    cout << "6. Remove Artwork" << endl;
    cout << "7. View Statistics" << endl;
    cout << "8. Save Gallery to File" << endl;
    cout << "9. Load Gallery from File" << endl;
    cout << "10. Logout" << endl;
    cout << "Choose option (1-10): ";
}

// Clear the input buffer
void clearInputBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Add sample data to the gallery
void addSampleData(Gallery& gallery) {
    // Add sample artwork data
    gallery.addArtwork(Artwork(1, "Starry Night", "Van Gogh", "Impressionism", 100000000, 
        "A night scene showing swirling clouds and bright stars over a sleeping town."));
    gallery.addArtwork(Artwork(2, "Mona Lisa", "Da Vinci", "Renaissance", 850000000, 
        "A portrait of a woman with an enigmatic smile."));
    gallery.addArtwork(Artwork(3, "The Scream", "Munch", "Expressionism", 120000000,
        "A figure with an agonized expression against a landscape with an orange sky."));
    
    // Add ratings to demonstrate functionality
    gallery.rateArtwork(1, 5);
    gallery.rateArtwork(1, 4);
    gallery.rateArtwork(2, 5);
    gallery.rateArtwork(3, 4);
    
    // Add sample users
    gallery.registerUser("admin", "admin123", true);
    gallery.registerUser("user", "user123", false);
}

int main() {
    Gallery gallery("Digital Art Gallery");
    addSampleData(gallery);
    
    int choice;
    string username, password, searchText, filename;
    int searchId, rating;
    
    cout << "Welcome to the Digital Art Gallery!" << endl;
    
    while (true) {
        // If not logged in, show login menu
        if (!gallery.isLoggedIn()) {
            showLoginMenu();
            cin >> choice;
            clearInputBuffer();
            
            switch (choice) {
                case 1: // Login
                    cout << "Enter username: ";
                    getline(cin, username);
                    cout << "Enter password: ";
                    getline(cin, password);
                    
                    if (gallery.login(username, password)) {
                        cout << "Login successful! Welcome, " << username << "!" << endl;
                    } else {
                        cout << "Invalid username or password. Please try again." << endl;
                    }
                    break;
                    
                case 2: // Register
                    cout << "Enter new username: ";
                    getline(cin, username);
                    cout << "Enter new password: ";
                    getline(cin, password);
                    
                    if (gallery.registerUser(username, password)) {
                        cout << "Registration successful! You can now log in." << endl;
                    } else {
                        cout << "Username already exists. Please try a different username." << endl;
                    }
                    break;
                    
                case 3: // Exit
                    cout << "Thank you for visiting the Digital Art Gallery!" << endl;
                    return 0;
                    
                default:
                    cout << "Invalid choice! Try again." << endl;
            }
            
            continue;
        }
        
        // Show appropriate menu based on user type
        if (gallery.isAdmin()) {
            showAdminMenu();
        } else {
            showUserMenu();
        }
        
        cin >> choice;
        clearInputBuffer();
        
        // Shared options for both user types
        switch (choice) {
            case 1: // Show All
                gallery.showAll();
                break;
                
            case 2: // Search by Artist
                cout << "Enter artist name: ";
                getline(cin, searchText);
                gallery.searchByArtist(searchText);
                break;
                
            case 3: // Search by Category
                cout << "Enter category: ";
                getline(cin, searchText);
                gallery.searchByCategory(searchText);
                break;
                
            case 4: // Find by ID
                cout << "Enter artwork ID: ";
                cin >> searchId;
                clearInputBuffer();
                {
                    Artwork* found = gallery.findById(searchId);
                    if (found != nullptr) {
                        found->displayDetailed();
                    } else {
                        cout << "Artwork not found!" << endl;
                    }
                }
                break;
        }
        
        // Admin-specific options
        if (gallery.isAdmin()) {
            switch (choice) {
                case 5: // Add Artwork
                    {
                        int id;
                        string title, artist, category, description;
                        double price;
                        
                        cout << "Enter ID: ";
                        cin >> id;
                        clearInputBuffer();
                        
                        cout << "Enter title: ";
                        getline(cin, title);
                        
                        cout << "Enter artist: ";
                        getline(cin, artist);
                        
                        cout << "Enter category: ";
                        getline(cin, category);
                        
                        cout << "Enter price: ";
                        cin >> price;
                        clearInputBuffer();
                        
                        cout << "Enter description: ";
                        getline(cin, description);
                        
                        if (gallery.addArtwork(Artwork(id, title, artist, category, price, description))) {
                            cout << "Artwork added successfully!" << endl;
                        } else {
                            cout << "Failed to add artwork. ID may already exist." << endl;
                        }
                    }
                    break;
                    
                case 6: // Remove Artwork
                    cout << "Enter artwork ID to remove: ";
                    cin >> searchId;
                    clearInputBuffer();
                    
                    if (gallery.removeArtwork(searchId)) {
                        cout << "Artwork removed successfully!" << endl;
                    } else {
                        cout << "Failed to remove artwork. ID may not exist." << endl;
                    }
                    break;
                    
                case 7: // View Statistics
                    gallery.showStatistics();
                    break;
                    
                case 8: // Save to File
                    cout << "Enter filename to save (or leave empty for default): ";
                    getline(cin, filename);
                    
                    if (filename.empty()) {
                        gallery.saveToFile();
                    } else {
                        gallery.saveToFile(filename);
                    }
                    break;
                    
                case 9: // Load from File
                    cout << "Enter filename to load (or leave empty for default): ";
                    getline(cin, filename);
                    
                    if (filename.empty()) {
                        gallery.loadFromFile();
                    } else {
                        gallery.loadFromFile(filename);
                    }
                    break;
                    
                case 10: // Logout
                    gallery.logout();
                    cout << "Logged out successfully!" << endl;
                    break;
                    
                default:
                    if (choice > 10) {
                        cout << "Invalid choice! Try again." << endl;
                    }
            }
        } 
        // User-specific options
        else {
            switch (choice) {
                case 5: // Rate Artwork
                    cout << "Enter artwork ID to rate: ";
                    cin >> searchId;
                    clearInputBuffer();
                    
                    cout << "Enter rating (1-5): ";
                    cin >> rating;
                    clearInputBuffer();
                    
                    if (rating < 1 || rating > 5) {
                        cout << "Invalid rating! Please enter a number between 1 and 5." << endl;
                    } else if (gallery.rateArtwork(searchId, rating)) {
                        cout << "Rating submitted successfully!" << endl;
                    } else {
                        cout << "Failed to add rating. Artwork ID may not exist." << endl;
                    }
                    break;
                    
                case 6: // View Statistics
                    gallery.showStatistics();
                    break;
                    
                case 7: // Logout
                    gallery.logout();
                    cout << "Logged out successfully!" << endl;
                    break;
                    
                default:
                    if (choice > 7) {
                        cout << "Invalid choice! Try again." << endl;
                    }
            }
        }
    }
    
    return 0;
}
