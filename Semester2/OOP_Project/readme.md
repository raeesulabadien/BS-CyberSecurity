# 🎨 Digital Art Gallery Curator

A comprehensive art gallery management system built with C++ backend and modern web frontend, demonstrating core Object-Oriented Programming principles and full-stack integration.

![Gallery Preview](https://img.shields.io/badge/Language-C%2B%2B-blue.svg)
![Web Frontend](https://img.shields.io/badge/Frontend-HTML%2FCSS%2FJS-green.svg)
![License](https://img.shields.io/badge/License-MIT-yellow.svg)
![Status](https://img.shields.io/badge/Status-Complete-brightgreen.svg)

## 📋 Table of Contents
- [Overview](#overview)
- [Features](#features)
- [Technologies Used](#technologies-used)
- [Project Structure](#project-structure)
- [Installation & Setup](#installation--setup)
- [Usage](#usage)
- [OOP Concepts Demonstrated](#oop-concepts-demonstrated)
- [Screenshots](#screenshots)
- [API Documentation](#api-documentation)
- [Contributing](#contributing)
- [License](#license)
- [Contact](#contact)

## 🎯 Overview

The **Digital Art Gallery Curator** is a complete gallery management system that allows users to:
- Manage artwork collections with full CRUD operations
- Search and filter artworks by various criteria
- Export and import gallery data
- View comprehensive gallery statistics
- Experience a modern web interface integrated with C++ backend

This project was designed as a semester project to demonstrate practical application of Object-Oriented Programming concepts in C++, with a focus on clean code architecture and real-world software development practices.

## ✨ Features

### 🖥️ C++ Backend Features
- **Complete Artwork Management**: Add, view, search, and manage artworks
- **Advanced Search Capabilities**: Search by artist, category, ID, and more
- **File I/O Operations**: Save and load gallery data with persistent storage
- **Data Export**: Export gallery data in both TXT and JSON formats
- **Statistical Analysis**: Generate comprehensive gallery statistics
- **Memory Management**: Efficient object handling and resource management

### 🌐 Web Frontend Features
- **Modern UI Design**: Clean, minimal dark blue aesthetic
- **Responsive Layout**: Works seamlessly on desktop and mobile devices
- **Interactive Dashboard**: Real-time gallery statistics and visualizations
- **Intuitive Navigation**: Tab-based interface for easy access to all features
- **Form Validation**: Client-side validation for data integrity
- **Modal Dialogs**: Detailed artwork views with enhanced user experience

### 🔗 Integration Features
- **Seamless Data Exchange**: C++ backend exports data for web frontend consumption
- **Real-time Updates**: Changes in C++ program reflect immediately in web interface
- **Cross-platform Compatibility**: Works on Windows, macOS, and Linux
- **Professional Workflow**: Demonstrates industry-standard development practices

## 🛠️ Technologies Used

### Backend
- **C++14**: Core programming language with modern features
- **STL Containers**: Vector for dynamic data storage
- **File Streams**: For data persistence and export functionality
- **Object-Oriented Design**: Classes, encapsulation, and composition

### Frontend
- **HTML5**: Semantic markup for content structure
- **CSS3**: Modern styling with flexbox and grid layouts
- **Vanilla JavaScript**: Pure JS for interactive functionality
- **Responsive Design**: Mobile-first approach for cross-device compatibility

### Development Tools
- **G++ Compiler**: For C++ compilation with C++14 standard
- **Python HTTP Server**: For local web development and testing
- **Git**: Version control for project management

## 📁 Project Structure

```
digital-art-gallery/
├── 📄 README.md                 # Project documentation
├── 📝 .gitignore               # Git ignore rules
├── 📄 LICENSE                  # MIT License
│
├── 🗂️ src/                     # Source code directory
│   ├── 📄 artwork.h            # Artwork class header
│   ├── 📄 artwork.cpp          # Artwork class implementation
│   ├── 📄 gallery.h            # Gallery class header
│   ├── 📄 gallery.cpp          # Gallery class implementation
│   └── 📄 main.cpp             # Main program entry point
│
├── 🌐 web/                     # Web interface directory
│   ├── 📄 index.html           # Main HTML page
│   ├── 🎨 style.css            # Stylesheet for UI design
│   └── ⚡ script.js            # JavaScript for interactivity
│
├── 📊 data/                    # Data storage directory
│   ├── 📄 gallery_data.txt     # Gallery data export (TXT format)
│   ├── 📄 gallery_data.json    # Gallery data export (JSON format)
│   └── 📄 gallery_backup.txt   # Backup data file
│
├── 📸 screenshots/             # Project screenshots
│   ├── 🖼️ cpp_interface.png    # C++ console interface
│   ├── 🖼️ web_interface.png    # Web interface preview
│   └── 🖼️ features_demo.png    # Features demonstration
│
└── 📚 docs/                    # Additional documentation
    ├── 📄 setup_guide.md       # Detailed setup instructions
    ├── 📄 user_manual.md       # User manual and tutorials
    └── 📄 api_reference.md     # Technical API documentation
```

## 🚀 Installation & Setup

### Prerequisites
- **C++ Compiler**: GCC 7.0+ or equivalent with C++14 support
- **Python 3.x**: For running the local web server
- **Modern Web Browser**: Chrome, Firefox, Safari, or Edge
- **Git**: For cloning the repository

### Quick Start

1. **Clone the Repository**
   ```bash
   git clone https://github.com/raeesulabadien/digital-art-gallery.git
   cd digital-art-gallery
   ```

2. **Compile the C++ Program**
   ```bash
   cd src
   g++ -std=c++14 -Wall -Wextra -o gallery main.cpp artwork.cpp gallery.cpp
   ```

3. **Run the Backend Program**
   ```bash
   ./gallery
   ```

4. **Start the Web Server** (New terminal window)
   ```bash
   cd web
   python -m http.server 8000
   ```

5. **Access the Web Interface**
   ```
   Open your browser and navigate to: http://localhost:8000
   ```

### Alternative Compilation (Windows)
```cmd
g++ -std=c++14 -o gallery.exe main.cpp artwork.cpp gallery.cpp
gallery.exe
```

## 📖 Usage

### C++ Console Interface

The console application provides a menu-driven interface:

```
=== Digital Art Gallery ===
1. Show All Artworks
2. Search by Artist
3. Search by Category
4. Find by ID
5. Add New Artwork
6. Save to File
7. Exit
Choose option (1-7):
```

**Example Usage:**
```cpp
// Adding a new artwork
gallery.addArtwork(Artwork(4, "The Persistence of Memory", "Salvador Dali", "Surrealism", 50000000));

// Searching by artist
auto results = gallery.searchByArtist("Van Gogh");

// Exporting data
gallery.saveToFile("gallery_backup.txt");
```

### Web Interface Navigation

1. **All Artworks**: Browse the complete gallery collection
2. **Search**: Find artworks by artist, category, or ID
3. **Add Artwork**: Add new pieces to the collection
4. **File Operations**: Save, export, and view statistics

### Integration Workflow

1. **Manage Data**: Use C++ program for data management
2. **Export Data**: Save gallery data using option 6
3. **View Web Interface**: Access the modern web dashboard
4. **Real-time Updates**: See changes reflected immediately

## 🔧 OOP Concepts Demonstrated

### 1. **Classes and Objects**
```cpp
class Artwork {
    // Artwork blueprint defining properties and behaviors
};

class Gallery {
    // Gallery manages multiple Artwork objects
};

// Creating objects from classes
Gallery gallery("My Art Gallery");
Artwork artwork(1, "Starry Night", "Van Gogh", "Impressionism", 100000000);
```

### 2. **Encapsulation**
```cpp
class Artwork {
private:
    int id;              // Hidden data members
    string title;
    string artist;
    
public:
    int getId();         // Controlled access through public methods
    string getTitle();
    void display();
};
```

### 3. **Data Abstraction**
```cpp
// Complex internal operations hidden behind simple interface
gallery.addArtwork(artwork);        // Simple method call
gallery.searchByArtist("Van Gogh"); // Hides search algorithm complexity
gallery.saveToFile();               // Abstracts file I/O operations
```

### 4. **Composition**
```cpp
class Gallery {
private:
    vector<Artwork> artworks;  // Gallery contains multiple Artwork objects
    string name;
public:
    void addArtwork(Artwork artwork);  // Manages contained objects
};
```

### 5. **Memory Management**
```cpp
// Automatic memory management using STL containers
vector<Artwork> artworks;  // Vector handles memory allocation/deallocation
// No manual new/delete required - RAII principle
```

## 📸 Screenshots

### C++ Console Interface
![C++ Console Interface](screenshots/cpp_interface.png)
*Clean, menu-driven console interface for gallery management*

### Modern Web Dashboard
![Web Interface](screenshots/web_interface.png)
*Professional web interface with dark blue aesthetic and responsive design*

### Features Demonstration
![Features Demo](screenshots/features_demo.png)
*Complete feature set including search, add, and statistics functionality*

## 📚 API Documentation

### Artwork Class Methods

| Method | Description | Parameters | Return Type |
|--------|-------------|------------|-------------|
| `Artwork()` | Constructor to create artwork object | `id, title, artist, category, price` | `Artwork` |
| `getId()` | Get artwork ID | None | `int` |
| `getTitle()` | Get artwork title | None | `string` |
| `getArtist()` | Get artist name | None | `string` |
| `getCategory()` | Get artwork category | None | `string` |
| `getPrice()` | Get artwork price | None | `double` |
| `display()` | Display artwork information | None | `void` |

### Gallery Class Methods

| Method | Description | Parameters | Return Type |
|--------|-------------|------------|-------------|
| `Gallery()` | Constructor to create gallery | `name` | `Gallery` |
| `addArtwork()` | Add artwork to gallery | `Artwork` | `void` |
| `showAll()` | Display all artworks | None | `void` |
| `searchByArtist()` | Search artworks by artist | `string artist` | `void` |
| `searchByCategory()` | Search artworks by category | `string category` | `void` |
| `findById()` | Find artwork by ID | `int id` | `Artwork*` |
| `saveToFile()` | Save gallery to file | None | `void` |
| `getCount()` | Get total artwork count | None | `int` |

## 🤝 Contributing

Contributions are welcome! Here's how you can help improve this project:

### Ways to Contribute
- 🐛 **Bug Reports**: Found a bug? Please create an issue with detailed steps to reproduce
- 💡 **Feature Requests**: Have an idea for a new feature? Open an issue to discuss it
- 📝 **Documentation**: Help improve documentation and code comments
- 🔧 **Code Improvements**: Submit pull requests for bug fixes or enhancements

### Development Setup
1. Fork the repository
2. Create a feature branch: `git checkout -b feature/amazing-feature`
3. Make your changes and test thoroughly
4. Commit your changes: `git commit -m 'Add amazing feature'`
5. Push to the branch: `git push origin feature/amazing-feature`
6. Open a Pull Request

### Code Style Guidelines
- Follow C++14 standard conventions
- Use meaningful variable and function names
- Add comments for complex algorithms
- Maintain consistent indentation (4 spaces)
- Test all changes before submitting

## 📄 License

This project is licensed under the **MIT License** - see the [LICENSE](LICENSE) file for details.

```
MIT License

Copyright (c) 2025 Raees Ul Abadien

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
```

## 📞 Contact

**Raees Ul Abadien**
- 🐙 **GitHub**: [@raeesulabadien](https://github.com/raeesulabadien)
- 📧 **Email**: raeesulabadien@gmail.com
- 💼 **LinkedIn**: [linkedin.com/in/raeesulabadien](https://linkedin.com/in/raeesulabadien)
- 🌐 **Portfolio**: [raeesulabadien.dev](https://raeesulabadien.dev)

### Project Information
- 📅 **Created**: May 28, 2025
- 🎓 **Type**: Semester Project (Object-Oriented Programming)
- 🏫 **Institution**: [Air University, Islamabad]
- 📚 **Course**: Object Oriented Programming - OOP Lab

---

## 🌟 Acknowledgments

- **Course Instructor**: For guidance on OOP principles and project requirements
- **Teaching Assistants**: For technical support and code review assistance
- **Classmates**: For collaborative learning and peer feedback
- **Open Source Community**: For inspiring clean code practices and documentation standards

---

## 🏆 Project Achievements

- ✅ **Complete OOP Implementation**: All core concepts properly demonstrated
- ✅ **Professional Code Quality**: Clean, well-documented, and maintainable code
- ✅ **Modern Integration**: Successfully bridges C++ backend with web frontend
- ✅ **Real-world Application**: Practical gallery management system
- ✅ **Academic Excellence**: Comprehensive project meeting all course requirements

---

<div align="center">

**⭐ If you found this project helpful, please give it a star! ⭐**

![GitHub stars](https://img.shields.io/github/stars/raeesulabadien/digital-art-gallery?style=social)
![GitHub forks](https://img.shields.io/github/forks/raeesulabadien/digital-art-gallery?style=social)
![GitHub watchers](https://img.shields.io/github/watchers/raeesulabadien/digital-art-gallery?style=social)

**Made with ❤️ by [Raees Ul Abadien](https://github.com/raeesulabadien)**

</div>
