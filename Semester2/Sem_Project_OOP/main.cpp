#include "gallery.h"
#include <iostream>
#include <memory>

void populateGallery(Gallery& gallery) {
    // Add sample artworks
    gallery.addArtwork(std::make_unique<Artwork>(
        1, "Starry Night", "Vincent van Gogh", "Post-Impressionism",
        "A famous painting depicting a swirling night sky", 
        "https://upload.wikimedia.org/wikipedia/commons/thumb/e/ea/Van_Gogh_-_Starry_Night_-_Google_Art_Project.jpg/1280px-Van_Gogh_-_Starry_Night_-_Google_Art_Project.jpg",
        100000000.0
    ));
    
    gallery.addArtwork(std::make_unique<Artwork>(
        2, "Mona Lisa", "Leonardo da Vinci", "Renaissance",
        "Portrait of Lisa Gherardini, wife of Florentine merchant",
        "https://upload.wikimedia.org/wikipedia/commons/thumb/e/ec/Mona_Lisa%2C_by_Leonardo_da_Vinci%2C_from_C2RMF_retouched.jpg/687px-Mona_Lisa%2C_by_Leonardo_da_Vinci%2C_from_C2RMF_retouched.jpg",
        850000000.0
    ));
    
    gallery.addArtwork(std::make_unique<Artwork>(
        3, "The Scream", "Edvard Munch", "Expressionism",
        "An artwork showing a figure with an agonized expression",
        "https://upload.wikimedia.org/wikipedia/commons/thumb/c/c5/Edvard_Munch%2C_1893%2C_The_Scream%2C_oil%2C_tempera_and_pastel_on_cardboard%2C_91_x_73_cm%2C_National_Gallery_of_Norway.jpg/471px-Edvard_Munch%2C_1893%2C_The_Scream%2C_oil%2C_tempera_and_pastel_on_cardboard%2C_91_x_73_cm%2C_National_Gallery_of_Norway.jpg",
        120000000.0
    ));
    
    gallery.addArtwork(std::make_unique<Artwork>(
        4, "Girl with a Pearl Earring", "Johannes Vermeer", "Baroque",
        "Portrait of an unknown woman with a mysterious pearl earring",
        "https://upload.wikimedia.org/wikipedia/commons/thumb/0/0f/1665_Girl_with_a_Pearl_Earring.jpg/540px-1665_Girl_with_a_Pearl_Earring.jpg",
        50000000.0
    ));
}

void showMenu() {
    std::cout << "\n=== Digital Art Gallery Curator ===\n";
    std::cout << "1. Display All Artworks\n";
    std::cout << "2. Search by Category\n";
    std::cout << "3. Search by Artist\n";
    std::cout << "4. Search by ID\n";
    std::cout << "5. Export to Web (JSON)\n";
    std::cout << "6. Exit\n";
    std::cout << "Choose an option (1-6): ";
}

int main() {
    Gallery gallery("Digital Art Museum");
    
    // Populate with sample data
    populateGallery(gallery);
    
    int choice;
    std::string searchTerm;
    int searchId;
    
    while (true) {
        showMenu();
        std::cin >> choice;
        
        switch (choice) {
            case 1:
                gallery.displayAllArtworks();
                break;
                
            case 2:
                std::cout << "Enter category to search: ";
                std::cin.ignore();
                std::getline(std::cin, searchTerm);
                {
                    auto results = gallery.getArtworksByCategory(searchTerm);
                    if (results.empty()) {
                        std::cout << "No artworks found in category: " << searchTerm << std::endl;
                    } else {
                        std::cout << "\nFound " << results.size() << " artwork(s) in category: " << searchTerm << std::endl;
                        for (auto* artwork : results) {
                            artwork->displayInfo();
                        }
                    }
                }
                break;
                
            case 3:
                std::cout << "Enter artist name to search: ";
                std::cin.ignore();
                std::getline(std::cin, searchTerm);
                {
                    auto results = gallery.getArtworksByArtist(searchTerm);
                    if (results.empty()) {
                        std::cout << "No artworks found by artist: " << searchTerm << std::endl;
                    } else {
                        std::cout << "\nFound " << results.size() << " artwork(s) by artist: " << searchTerm << std::endl;
                        for (auto* artwork : results) {
                            artwork->displayInfo();
                        }
                    }
                }
                break;
                
            case 4:
                std::cout << "Enter artwork ID to search: ";
                std::cin >> searchId;
                {
                    Artwork* artwork = gallery.getArtworkById(searchId);
                    if (artwork) {
                        artwork->displayInfo();
                    } else {
                        std::cout << "No artwork found with ID: " << searchId << std::endl;
                    }
                }
                break;
                
            case 5:
                gallery.exportToJson("gallery_data.json");
                std::cout << "Data exported! You can now view the web interface.\n";
                break;
                
            case 6:
                std::cout << "Thank you for visiting the Digital Art Gallery!\n";
                return 0;
                
            default:
                std::cout << "Invalid option. Please try again.\n";
        }
    }
    
    return 0;
}