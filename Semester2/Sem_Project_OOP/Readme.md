# Digital Art Gallery Curator

A simple digital art gallery management system built with C++ backend using OOP concepts and HTML/CSS/JavaScript frontend.

## Features

### C++ Backend (OOP Concepts Used):
- **Classes & Objects**: `Artwork` and `Gallery` classes
- **Encapsulation**: Private member variables with public getter methods
- **Inheritance**: Demonstrated through class design
- **Polymorphism**: Virtual functions and unique_ptr usage
- **Abstraction**: Clean interfaces for artwork management

### Frontend Features:
- Responsive web interface
- Browse all artworks
- Filter by categories
- Search functionality
- Detailed artwork view modal
- Mobile-friendly design

## How to Run

### Step 1: Compile and Run C++ Backend
```bash
# Compile the program
make

# Or manually compile:
g++ -std=c++14 -Wall -Wextra -o gallery main.cpp artwork.cpp gallery.cpp

# Run the program
./gallery
```

### Step 2: Generate Web Data
1. Run the C++ program
2. Choose option **5** to "Export to Web (JSON)"
3. This creates `gallery_data.json` file

### Step 3: View Web Interface
1. Open `index.html` in a web browser
2. The webpage will automatically load data from `gallery_data.json`

## Project Structure

```
digital-art-gallery/
├── artwork.h          # Artwork class header
├── artwork.cpp        # Artwork class implementation
├── gallery.h          # Gallery class header
├── gallery.cpp        # Gallery class implementation
├── main.cpp           # Main program with menu
├── index.html         # Web interface
├── style.css          # Styling
├── script.js          # JavaScript functionality
├── Makefile           # Build configuration
├── README.md          # This file
└── gallery_data.json  # Generated data file
```

## OOP Concepts Demonstrated

1. **Encapsulation**: Private data members with public methods
2. **Classes & Objects**: Artwork and Gallery classes with constructors
3. **Data Abstraction**: Clean interfaces hiding implementation details
4. **Memory Management**: Smart pointers (unique_ptr) for automatic memory management

## Menu Options (C++ Program)

1. Display All Artworks - Shows all artworks in the console
2. Search by Category - Filter artworks by category
3. Search by Artist - Find artworks by specific artist
4. Search by ID - Get specific artwork by ID
5. Export to Web (JSON) - Generate data for web interface
6. Exit - Close the program

## Web Interface Features

- **All Artworks**: Grid view of all artworks
- **Categories**: Browse artworks by category
- **Search**: Find artworks by title, artist, or category
- **Detail View**: Click any artwork for detailed information

## Troubleshooting

### Web Interface Shows Error
- Make sure you've run the C++ program
- Choose option 5 to export data
- Refresh the webpage

### Compilation Errors
- Ensure you have a C++14 compatible compiler
- Use the provided Makefile or compile manually

### Images Not Loading
- Sample uses online images
- If images don't load, placeholder images will be shown

## Sample Data

The program comes with 4 famous artworks:
- Starry Night by Vincent van Gogh
- Mona Lisa by Leonardo da Vinci
- The Scream by Edvard Munch
- Girl with a Pearl Earring by Johannes Vermeer

## Technologies Used

- **Backend**: C++ with OOP concepts
- **Frontend**: HTML5, CSS3, JavaScript (ES6)
- **Data Exchange**: JSON format
- **Build System**: Makefile

This project demonstrates clean separation between backend logic and frontend presentation, making it easy to understand and extend.
