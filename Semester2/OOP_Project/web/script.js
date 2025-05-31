// Main data store for the gallery
let galleryData = {
    name: "Digital Art Gallery",
    currentUser: null,  // Will store logged in user info
    // Sample artwork data
    artworks: [
        {
            id: 1,
            title: "Starry Night",
            artist: "Van Gogh",
            category: "Impressionism",
            price: 100000000,
            description: "A night scene showing the swirling clouds and bright stars over a sleeping town.",
            dateAdded: new Date(2023, 0, 15).getTime(),
            ratings: [5, 4, 5],
            image: "starry_night.jpg"
        },
        {
            id: 2,
            title: "Mona Lisa",
            artist: "Da Vinci",
            category: "Renaissance",
            price: 850000000,
            description: "A portrait of a woman with an enigmatic smile, one of the most famous paintings in the world.",
            dateAdded: new Date(2023, 1, 10).getTime(),
            ratings: [5, 4, 5, 4],
            image: "mona_lisa.jpg"
        },
        {
            id: 3,
            title: "The Scream",
            artist: "Munch",
            category: "Expressionism",
            price: 120000000,
            description: "A figure with an agonized expression set against a landscape with a tumultuous orange sky.",
            dateAdded: new Date(2023, 2, 5).getTime(),
            ratings: [4, 3, 4],
            image: "the_scream.jpg"
        }
    ],
    // Sample user data
    users: [
        {
            username: "admin",
            passwordHash: "admin123", // In a real app, this would be properly hashed
            isAdmin: true
        },
        {
            username: "user",
            passwordHash: "user123", // In a real app, this would be properly hashed
            isAdmin: false
        }
    ]
};

// Initialize when page loads
document.addEventListener('DOMContentLoaded', function() {
    checkLoginStatus();
    updateArtworkCount();
    populateCategoryFilter();
    
    // Set up filter event listeners
    setupFilterListeners();
});

// Check if user is logged in (from local storage)
function checkLoginStatus() {
    const user = localStorage.getItem('currentUser');
    if (user) {
        galleryData.currentUser = JSON.parse(user);
        showLoggedInUI();
    } else {
        showLoginUI();
    }
}

// Show login form
function showLoginUI() {
    document.getElementById('login-section').classList.add('active');
    document.getElementById('user-info').textContent = 'Guest';
    
    // Hide admin-only elements
    document.querySelectorAll('.admin-only').forEach(el => el.style.display = 'none');
}

// Show logged-in interface
function showLoggedInUI() {
    document.getElementById('login-section').classList.remove('active');
    document.getElementById('all-section').classList.add('active');
    document.getElementById('user-info').textContent = galleryData.currentUser.username;
    
    // Show admin-only elements if user is admin
    document.querySelectorAll('.admin-only').forEach(el => {
        el.style.display = galleryData.currentUser.isAdmin ? 'block' : 'none';
    });
    
    showAllArtworks();
    loadDashboard();
    loadRecommendations();
}

// Login function
function login() {
    const username = document.getElementById('login-username').value.trim();
    const password = document.getElementById('login-password').value.trim();
    
    const user = galleryData.users.find(u => u.username === username && u.passwordHash === password);
    
    if (user) {
        galleryData.currentUser = {
            username: user.username,
            isAdmin: user.isAdmin
        };
        localStorage.setItem('currentUser', JSON.stringify(galleryData.currentUser));
        showToast('Login successful!', 'success');
        showLoggedInUI();
    } else {
        showToast('Invalid username or password', 'error');
    }
}

// Logout function
function logout() {
    galleryData.currentUser = null;
    localStorage.removeItem('currentUser');
    showToast('Logged out successfully', 'success');
    showLoginUI();
}

// Show a specific section
function showSection(sectionName) {
    // Hide all sections
    document.querySelectorAll('.section').forEach(section => section.classList.remove('active'));
    
    // Show selected section
    document.getElementById(sectionName + '-section').classList.add('active');
    
    // Update nav buttons
    document.querySelectorAll('.nav-btn').forEach(btn => btn.classList.remove('active'));
    event.currentTarget.classList.add('active');
    
    // Load section-specific content
    if (sectionName === 'all') {
        showAllArtworks();
    } else if (sectionName === 'stats') {
        renderStatistics();
    } else if (sectionName === 'dashboard') {
        loadDashboard();
    }
}

// Display all artworks
function showAllArtworks() {
    const grid = document.getElementById('artworks-grid');
    grid.innerHTML = '';
    
    galleryData.artworks.forEach(artwork => {
        const card = createArtworkCard(artwork);
        grid.appendChild(card);
    });
    
    updateArtworkCount();
}

// Create artwork card
function createArtworkCard(artwork, isSmall = false) {
    const card = document.createElement('div');
    card.className = 'artwork-card';
    card.onclick = () => showArtworkDetail(artwork);
    
    // Calculate average rating
    const avgRating = artwork.ratings.length > 0 
        ? artwork.ratings.reduce((sum, r) => sum + r, 0) / artwork.ratings.length 
        : 0;
    
    // Format date
    const date = new Date(artwork.dateAdded);
    const dateStr = date.toLocaleDateString();
    
    // Create star rating display
    const stars = '★'.repeat(Math.round(avgRating)) + '☆'.repeat(5 - Math.round(avgRating));
    
    card.innerHTML = `
        <div class="artwork-id">#${artwork.id}</div>
        <div class="artwork-image-container">
            <img src="images/${artwork.image || 'placeholder.jpg'}" alt="${artwork.title}" class="artwork-image">
        </div>
        <div class="artwork-info">
            <div class="artwork-title">${artwork.title}</div>
            <div class="artwork-artist">by ${artwork.artist}</div>
            <div class="artwork-category">${artwork.category}</div>
            <div class="artwork-rating">${stars} (${artwork.ratings.length})</div>
            <div class="artwork-price">$${formatPrice(artwork.price)}</div>
            <div class="artwork-date">Added: ${dateStr}</div>
        </div>
    `;
    
    return card;
}

// Show artwork details in modal
function showArtworkDetail(artwork) {
    const modal = document.getElementById('artwork-modal');
    const modalContent = document.getElementById('artwork-modal-content');
    
    // Calculate average rating
    const avgRating = artwork.ratings.length > 0 
        ? artwork.ratings.reduce((sum, r) => sum + r, 0) / artwork.ratings.length 
        : 0;
        
    // Format date
    const date = new Date(artwork.dateAdded);
    const dateStr = date.toLocaleDateString();
    
    modalContent.innerHTML = `
        <h2>${artwork.title}</h2>
        <div class="modal-image-container">
            <img src="images/${artwork.image || 'placeholder.jpg'}" alt="${artwork.title}" class="modal-image">
        </div>
        <div class="artwork-details">
            <p><strong>Artist:</strong> ${artwork.artist}</p>
            <p><strong>Category:</strong> ${artwork.category}</p>
            <p><strong>Price:</strong> $${formatPrice(artwork.price)}</p>
            <p><strong>Rating:</strong> ${avgRating.toFixed(1)}/5 (${artwork.ratings.length} ratings)</p>
            <p><strong>Added:</strong> ${dateStr}</p>
            <p class="description"><strong>Description:</strong> ${artwork.description}</p>
            
            ${galleryData.currentUser ? `
                <div class="rating-container">
                    <h3>Rate this artwork:</h3>
                    <div class="star-rating">
                        <span class="star" data-rating="1">☆</span>
                        <span class="star" data-rating="2">☆</span>
                        <span class="star" data-rating="3">☆</span>
                        <span class="star" data-rating="4">☆</span>
                        <span class="star" data-rating="5">☆</span>
                    </div>
                    <button onclick="rateArtwork(${artwork.id})">Submit Rating</button>
                </div>
            ` : ''}
            
            ${galleryData.currentUser && galleryData.currentUser.isAdmin ? `
                <div class="admin-actions">
                    <button class="delete-btn" onclick="deleteArtwork(${artwork.id})">Delete</button>
                </div>
            ` : ''}
        </div>
        <button class="close-btn" onclick="closeModal()">Close</button>
    `;
    
    // Set up star rating functionality
    if (galleryData.currentUser) {
        const stars = modalContent.querySelectorAll('.star');
        stars.forEach(star => {
            star.addEventListener('mouseover', function() {
                const rating = this.getAttribute('data-rating');
                highlightStars(stars, rating);
            });
            
            star.addEventListener('mouseout', function() {
                stars.forEach(s => s.textContent = '☆');
            });
            
            star.addEventListener('click', function() {
                const rating = this.getAttribute('data-rating');
                setRating(stars, rating);
            });
        });
    }
    
    // Show similar artworks
    loadSimilarArtworks(artwork);
    
    // Display the modal
    modal.style.display = 'flex';
}

// Highlight stars for rating
function highlightStars(stars, rating) {
    stars.forEach(star => {
        const starRating = star.getAttribute('data-rating');
        star.textContent = starRating <= rating ? '★' : '☆';
    });
}

// Set rating when clicked
function setRating(stars, rating) {
    stars.forEach(star => {
        const starRating = star.getAttribute('data-rating');
        star.textContent = starRating <= rating ? '★' : '☆';
        if (starRating <= rating) {
            star.classList.add('active');
        } else {
            star.classList.remove('active');
        }
    });
    
    // Store the selected rating
    document.querySelector('.star-rating').setAttribute('data-selected', rating);
}

// Rate an artwork
function rateArtwork(artworkId) {
    const ratingContainer = document.querySelector('.star-rating');
    const rating = parseInt(ratingContainer.getAttribute('data-selected'));
    
    if (!rating) {
        showToast('Please select a rating', 'error');
        return;
    }
    
    const artwork = galleryData.artworks.find(a => a.id === artworkId);
    if (artwork) {
        artwork.ratings.push(rating);
        showToast('Rating submitted successfully!', 'success');
        closeModal();
        showAllArtworks();
        loadDashboard();
    }
}

// Close the modal
function closeModal() {
    document.getElementById('artwork-modal').style.display = 'none';
}

// Format price with commas
function formatPrice(price) {
    return price.toLocaleString('en-US');
}

// Update artwork count display
function updateArtworkCount() {
    const count = galleryData.artworks.length;
    document.getElementById('artwork-count').textContent = `${count} Artwork${count !== 1 ? 's' : ''}`;
}

// Search by artist
function searchByArtist() {
    const artistName = document.getElementById('artist-input').value.trim();
    if (!artistName) {
        showToast('Please enter an artist name', 'error');
        return;
    }
    
    const results = galleryData.artworks.filter(artwork => 
        artwork.artist.toLowerCase().includes(artistName.toLowerCase())
    );
    
    displaySearchResults(results, `artist "${artistName}"`);
}

// Search by category
function searchByCategory() {
    const categoryName = document.getElementById('category-input').value.trim();
    if (!categoryName) {
        showToast('Please enter a category', 'error');
        return;
    }
    
    const results = galleryData.artworks.filter(artwork => 
        artwork.category.toLowerCase().includes(categoryName.toLowerCase())
    );
    
    displaySearchResults(results, `category "${categoryName}"`);
}

// Find artwork by ID
function findById() {
    const id = parseInt(document.getElementById('id-input').value);
    if (isNaN(id)) {
        showToast('Please enter a valid ID', 'error');
        return;
    }
    
    const results = galleryData.artworks.filter(artwork => artwork.id === id);
    displaySearchResults(results, `ID ${id}`);
}

// Display search results
function displaySearchResults(results, searchType) {
    const resultsContainer = document.getElementById('search-results');
    resultsContainer.innerHTML = '';
    
    if (results.length === 0) {
        resultsContainer.innerHTML = `<p class="no-results">No artworks found for ${searchType}.</p>`;
        return;
    }
    
    const resultHeader = document.createElement('h3');
    resultHeader.textContent = `Found ${results.length} artwork(s) for ${searchType}:`;
    resultsContainer.appendChild(resultHeader);
    
    const grid = document.createElement('div');
    grid.className = 'grid';
    
    results.forEach(artwork => {
        const card = createArtworkCard(artwork);
        grid.appendChild(card);
    });
    
    resultsContainer.appendChild(grid);
}

// Add new artwork
function addArtwork(event) {
    event.preventDefault();
    
    // Only admin can add artwork
    if (!galleryData.currentUser || !galleryData.currentUser.isAdmin) {
        showToast('You do not have permission to add artwork', 'error');
        return;
    }
    
    // Get form values
    const id = parseInt(document.getElementById('new-id').value);
    const title = document.getElementById('new-title').value.trim();
    const artist = document.getElementById('new-artist').value.trim();
    const category = document.getElementById('new-category').value.trim();
    const price = parseFloat(document.getElementById('new-price').value);
    const description = document.getElementById('new-description').value.trim();
    
    // Validate inputs
    if (isNaN(id) || id <= 0) {
        showToast('Please enter a valid ID', 'error');
        return;
    }
    
    if (galleryData.artworks.some(a => a.id === id)) {
        showToast('An artwork with this ID already exists', 'error');
        return;
    }
    
    if (!title || !artist || !category || isNaN(price) || price <= 0) {
        showToast('Please fill in all required fields', 'error');
        return;
    }
    
    // Add the new artwork
    galleryData.artworks.push({
        id,
        title,
        artist,
        category,
        price,
        description,
        dateAdded: Date.now(),
        ratings: [],
        image: 'placeholder.jpg'
    });
    
    // Reset the form
    document.getElementById('add-form').reset();
    
    showToast('Artwork added successfully!', 'success');
    showAllArtworks();
    updateCategoryFilter(); // Update category filter options
    
    // Switch to all artworks view
    showSection('all');
}

// Delete an artwork
function deleteArtwork(artworkId) {
    // Only admin can delete artwork
    if (!galleryData.currentUser || !galleryData.currentUser.isAdmin) {
        showToast('You do not have permission to delete artwork', 'error');
        return;
    }
    
    if (confirm('Are you sure you want to delete this artwork?')) {
        const index = galleryData.artworks.findIndex(a => a.id === artworkId);
        if (index !== -1) {
            galleryData.artworks.splice(index, 1);
            showToast('Artwork deleted successfully!', 'success');
            closeModal();
            showAllArtworks();
            updateCategoryFilter(); // Update category filter options
        } else {
            showToast('Artwork not found', 'error');
        }
    }
}

// Show toast notification
function showToast(message, type = 'info') {
    const toast = document.createElement('div');
    toast.className = `toast ${type}`;
    toast.textContent = message;
    
    document.body.appendChild(toast);
    
    // Show the toast
    setTimeout(() => {
        toast.classList.add('show');
        
        // Hide after 3 seconds
        setTimeout(() => {
            toast.classList.remove('show');
            
            // Remove from DOM after hiding
            setTimeout(() => {
                document.body.removeChild(toast);
            }, 300);
        }, 3000);
    }, 10);
}

// Render gallery statistics
function renderStatistics() {
    const statsContainer = document.getElementById('statistics-content');
    
    // Calculate stats
    const totalArtworks = galleryData.artworks.length;
    const totalValue = galleryData.artworks.reduce((sum, artwork) => sum + artwork.price, 0);
    
    // Get most expensive artwork
    const mostExpensive = [...galleryData.artworks].sort((a, b) => b.price - a.price)[0];
    
    // Get most rated artwork
    const mostRated = [...galleryData.artworks].sort((a, b) => b.ratings.length - a.ratings.length)[0];
    
    // Count artworks by category
    const categoryCounts = {};
    galleryData.artworks.forEach(artwork => {
        categoryCounts[artwork.category] = (categoryCounts[artwork.category] || 0) + 1;
    });
    
    // Format HTML
    statsContainer.innerHTML = `
        <div class="stats-card">
            <h3>Gallery Overview</h3>
            <p><strong>Total Artworks:</strong> ${totalArtworks}</p>
            <p><strong>Total Value:</strong> $${formatPrice(totalValue)}</p>
            <p><strong>Average Value:</strong> $${formatPrice(totalValue / totalArtworks)}</p>
        </div>
        
        <div class="stats-card">
            <h3>Most Expensive Artwork</h3>
            <p><strong>Title:</strong> ${mostExpensive ? mostExpensive.title : 'N/A'}</p>
            <p><strong>Artist:</strong> ${mostExpensive ? mostExpensive.artist : 'N/A'}</p>
            <p><strong>Value:</strong> $${mostExpensive ? formatPrice(mostExpensive.price) : 'N/A'}</p>
        </div>
        
        <div class="stats-card">
            <h3>Most Rated Artwork</h3>
            <p><strong>Title:</strong> ${mostRated ? mostRated.title : 'N/A'}</p>
            <p><strong>Artist:</strong> ${mostRated ? mostRated.artist : 'N/A'}</p>
            <p><strong>Ratings:</strong> ${mostRated ? mostRated.ratings.length : 'N/A'}</p>
        </div>
        
        <div class="stats-card">
            <h3>Categories Distribution</h3>
            <div class="category-chart">
                ${Object.entries(categoryCounts).map(([category, count]) => `
                    <div class="category-item">
                        <div class="category-name">${category}</div>
                        <div class="category-bar" style="width: ${(count / totalArtworks) * 100}%">${count}</div>
                    </div>
                `).join('')}
            </div>
        </div>
    `;
}

// Filter variables
let activeFilters = {
    category: null,
    artist: null,
    minPrice: null,
    maxPrice: null,
    minRating: null
};

// Set up filter event listeners
function setupFilterListeners() {
    document.getElementById('filter-category').addEventListener('change', function() {
        setFilter('category', this.value || null);
    });
    
    document.getElementById('filter-artist').addEventListener('input', function() {
        setFilter('artist', this.value || null);
    });
    
    document.getElementById('filter-min-price').addEventListener('input', function() {
        setFilter('minPrice', this.value ? parseFloat(this.value) : null);
    });
    
    document.getElementById('filter-max-price').addEventListener('input', function() {
        setFilter('maxPrice', this.value ? parseFloat(this.value) : null);
    });
    
    document.getElementById('filter-min-rating').addEventListener('change', function() {
        setFilter('minRating', this.value ? parseFloat(this.value) : null);
    });
    
    document.getElementById('apply-filters-btn').addEventListener('click', function() {
        applyFilters();
    });
    
    document.getElementById('clear-filters-btn').addEventListener('click', function() {
        clearAllFilters();
    });
}

// Populate category filter dropdown
function populateCategoryFilter() {
    const categorySelect = document.getElementById('filter-category');
    
    // Get unique categories
    const categories = new Set();
    galleryData.artworks.forEach(artwork => {
        categories.add(artwork.category);
    });
    
    // Add options
    categorySelect.innerHTML = '<option value="">All Categories</option>';
    
    Array.from(categories).sort().forEach(category => {
        const option = document.createElement('option');
        option.value = category;
        option.textContent = category;
        categorySelect.appendChild(option);
    });
}

// Update category filter options
function updateCategoryFilter() {
    populateCategoryFilter();
}

// Set a filter value
function setFilter(filterType, value) {
    activeFilters[filterType] = value;
    updateFilterBadges();
}

// Apply all filters
function applyFilters() {
    let filteredArtworks = [...galleryData.artworks];
    
    // Category filter
    if (activeFilters.category) {
        filteredArtworks = filteredArtworks.filter(artwork => 
            artwork.category.toLowerCase() === activeFilters.category.toLowerCase()
        );
    }
    
    // Artist filter
    if (activeFilters.artist) {
        filteredArtworks = filteredArtworks.filter(artwork => 
            artwork.artist.toLowerCase().includes(activeFilters.artist.toLowerCase())
        );
    }
    
    // Price range filter
    if (activeFilters.minPrice !== null) {
        filteredArtworks = filteredArtworks.filter(artwork => 
            artwork.price >= activeFilters.minPrice
        );
    }
    
    if (activeFilters.maxPrice !== null) {
        filteredArtworks = filteredArtworks.filter(artwork => 
            artwork.price <= activeFilters.maxPrice
        );
    }
    
    // Rating filter
    if (activeFilters.minRating !== null) {
        filteredArtworks = filteredArtworks.filter(artwork => {
            if (artwork.ratings.length === 0) return false;
            
            const avgRating = artwork.ratings.reduce((sum, r) => sum + r, 0) / artwork.ratings.length;
            return avgRating >= activeFilters.minRating;
        });
    }
    
    displayFilteredArtworks(filteredArtworks);
}

// Display filtered artworks
function displayFilteredArtworks(artworks) {
    const grid = document.getElementById('artworks-grid');
    grid.innerHTML = '';
    
    if (artworks.length === 0) {
        grid.innerHTML = '<div class="no-results">No artworks match your filters.</div>';
        return;
    }
    
    artworks.forEach(artwork => {
        const card = createArtworkCard(artwork);
        grid.appendChild(card);
    });
    
    document.getElementById('artwork-count').textContent = `${artworks.length} Artwork${artworks.length !== 1 ? 's' : ''}`;
}

// Update filter badges
function updateFilterBadges() {
    const badgeContainer = document.getElementById('filter-badges');
    badgeContainer.innerHTML = '';
    
    let hasFilters = false;
    
    for (let filterType in activeFilters) {
        if (activeFilters[filterType] !== null) {
            hasFilters = true;
            
            const badge = document.createElement('div');
            badge.className = 'filter-badge';
            
            let filterText = '';
            
            // Format filter display text
            switch(filterType) {
                case 'category':
                    filterText = `Category: ${activeFilters.category}`;
                    break;
                case 'artist':
                    filterText = `Artist: ${activeFilters.artist}`;
                    break;
                case 'minPrice':
                    filterText = `Min Price: $${formatPrice(activeFilters.minPrice)}`;
                    break;
                case 'maxPrice':
                    filterText = `Max Price: $${formatPrice(activeFilters.maxPrice)}`;
                    break;
                case 'minRating':
                    filterText = `Min Rating: ${activeFilters.minRating}★`;
                    break;
            }
            
            badge.innerHTML = `
                ${filterText}
                <span class="badge-remove" onclick="clearFilter('${filterType}')">✕</span>
            `;
            
            badgeContainer.appendChild(badge);
        }
    }
    
    // Show or hide the clear all button
    document.getElementById('clear-filters-btn').style.display = hasFilters ? 'block' : 'none';
    
    // Update active filter count
    const filterCount = Object.values(activeFilters).filter(val => val !== null).length;
    document.getElementById('filter-count').textContent = filterCount > 0 ? `(${filterCount})` : '';
}

// Clear a specific filter
function clearFilter(filterType) {
    activeFilters[filterType] = null;
    
    // Reset the filter input
    const inputId = `filter-${filterType}`;
    const input = document.getElementById(inputId);
    if (input) {
        if (input.type === 'checkbox') {
            input.checked = false;
        } else {
            input.value = '';
        }
    }
    
    updateFilterBadges();
    applyFilters();
}

// Clear all filters
function clearAllFilters() {
    for (let filterType in activeFilters) {
        activeFilters[filterType] = null;
    }
    
    // Reset all filter inputs
    document.querySelectorAll('.filter-input').forEach(input => {
        if (input.type === 'checkbox') {
            input.checked = false;
        } else {
            input.value = '';
        }
    });
    
    updateFilterBadges();
    showAllArtworks(); // Show all artworks again
}

// Load user dashboard data
function loadDashboard() {
    if (!galleryData.currentUser) {
        return;
    }
    
    // Update user statistics
    updateUserStats();
    updateRatingDistribution();
    updateCategoryDistribution();
    loadUserFavorites();
}

// Update user statistics
function updateUserStats() {
    // Count of rated artworks (simulating user ratings)
    const ratedArtworks = galleryData.artworks.filter(artwork => artwork.ratings.length > 0);
    document.getElementById('user-rated-count').textContent = ratedArtworks.length;
    
    // Recently viewed (simulating views with ratings as proxy)
    document.getElementById('user-viewed-count').textContent = ratedArtworks.length;
    
    // Find favorite category - most rated category
    const categoryCounts = {};
    
    ratedArtworks.forEach(artwork => {
        categoryCounts[artwork.category] = (categoryCounts[artwork.category] || 0) + 1;
    });
    
    // Find category with highest count
    let favoriteCategory = '-';
    let maxCount = 0;
    
    for (const category in categoryCounts) {
        if (categoryCounts[category] > maxCount) {
            maxCount = categoryCounts[category];
            favoriteCategory = category;
        }
    }
    
    document.getElementById('user-favorite-category').textContent = favoriteCategory;
}

// Update rating distribution chart
function updateRatingDistribution() {
    // Count ratings of each value
    const ratingCounts = {1: 0, 2: 0, 3: 0, 4: 0, 5: 0};
    let totalRatings = 0;
    
    galleryData.artworks.forEach(artwork => {
        artwork.ratings.forEach(rating => {
            ratingCounts[rating]++;
            totalRatings++;
        });
    });
    
    // Update chart bars and counts
    for (let i = 1; i <= 5; i++) {
        const count = ratingCounts[i];
        const percentage = totalRatings > 0 ? (count / totalRatings) * 100 : 0;
        
        document.getElementById(`rating-${i}-bar`).style.width = `${percentage}%`;
        document.getElementById(`rating-${i}-count`).textContent = count;
    }
}

// Update category distribution chart
function updateCategoryDistribution() {
    const categoryChart = document.getElementById('category-chart');
    categoryChart.innerHTML = '';
    
    // Count artworks by category
    const categoryCounts = {};
    
    galleryData.artworks.forEach(artwork => {
        categoryCounts[artwork.category] = (categoryCounts[artwork.category] || 0) + 1;
    });
    
    // Sort categories by count
    const sortedCategories = Object.keys(categoryCounts).sort((a, b) => 
        categoryCounts[b] - categoryCounts[a]
    );
    
    // Get total artworks
    const totalArtworks = galleryData.artworks.length;
    
    // Create category bars
    sortedCategories.forEach(category => {
        const count = categoryCounts[category];
        const percentage = (count / totalArtworks) * 100;
        
        const categoryItem = document.createElement('div');
        categoryItem.className = 'category-item';
        categoryItem.innerHTML = `
            <div class="category-name">${category}</div>
            <div class="category-bar-wrapper">
                <div class="category-bar" style="width: ${percentage}%">${count}</div>
            </div>
        `;
        
        categoryChart.appendChild(categoryItem);
    });
}

// Load user favorites
function loadUserFavorites() {
    const favoritesGrid = document.getElementById('user-favorites');
    favoritesGrid.innerHTML = '';
    
    // Get highest rated artworks (simulating favorites)
    const favoriteArtworks = [...galleryData.artworks]
        .filter(artwork => artwork.ratings.length > 0)
        .sort((a, b) => {
            const avgA = a.ratings.reduce((sum, r) => sum + r, 0) / a.ratings.length;
            const avgB = b.ratings.reduce((sum, r) => sum + r, 0) / b.ratings.length;
            return avgB - avgA;
        })
        .slice(0, 3);
    
    if (favoriteArtworks.length === 0) {
        favoritesGrid.innerHTML = '<p class="no-favorites">You haven\'t rated any artworks yet.</p>';
        return;
    }
    
    favoriteArtworks.forEach(artwork => {
        const card = document.createElement('div');
        card.className = 'favorite-card';
        card.onclick = () => showArtworkDetail(artwork);
        
        // Calculate average rating
        const avgRating = artwork.ratings.reduce((sum, r) => sum + r, 0) / artwork.ratings.length;
        const stars = '★'.repeat(Math.round(avgRating)) + '☆'.repeat(5 - Math.round(avgRating));
        
        card.innerHTML = `
            <div class="favorite-image-container">
                <img src="images/${artwork.image || 'placeholder.jpg'}" alt="${artwork.title}" class="favorite-image">
            </div>
            <div class="favorite-info">
                <div class="favorite-title">${artwork.title}</div>
                <div class="favorite-artist">${artwork.artist}</div>
                <div class="favorite-rating">${stars}</div>
            </div>
        `;
        
        favoritesGrid.appendChild(card);
    });
}

// Load recommendations for the user
function loadRecommendations() {
    if (!galleryData.currentUser) {
        return;
    }
    
    const recommendationsContainer = document.getElementById('recommendations-container');
    recommendationsContainer.innerHTML = `
        <h3>Recommended Artworks</h3>
        <div id="recommended-artworks" class="recommendation-grid"></div>
    `;
    
    // Get recommended artworks (based on favorites' categories)
    const favoriteArtworks = [...galleryData.artworks]
        .filter(artwork => artwork.ratings.length > 0)
        .sort((a, b) => {
            const avgA = a.ratings.reduce((sum, r) => sum + r, 0) / a.ratings.length;
            const avgB = b.ratings.reduce((sum, r) => sum + r, 0) / b.ratings.length;
            return avgB - avgA;
        });
    
    if (favoriteArtworks.length === 0) {
        // If no favorites, show most popular artworks
        const popularArtworks = [...galleryData.artworks]
            .sort((a, b) => b.ratings.length - a.ratings.length)
            .slice(0, 4);
        
        displayRecommendations(popularArtworks);
        return;
    }
    
    // Get categories from favorite artworks
    const favoriteCategories = new Set();
    favoriteArtworks.slice(0, 3).forEach(artwork => {
        favoriteCategories.add(artwork.category);
    });
    
    // Find artworks in favorite categories that aren't already favorites
    const recommendations = galleryData.artworks.filter(artwork => {
        return favoriteCategories.has(artwork.category) && 
               !favoriteArtworks.slice(0, 3).some(fav => fav.id === artwork.id);
    }).slice(0, 4);
    
    displayRecommendations(recommendations.length > 0 ? recommendations : galleryData.artworks.slice(0, 4));
}

// Display recommendations
function displayRecommendations(artworks) {
    const recommendedGrid = document.getElementById('recommended-artworks');
    recommendedGrid.innerHTML = '';
    
    if (artworks.length === 0) {
        recommendedGrid.innerHTML = '<p class="no-recommendations">No recommendations available.</p>';
        return;
    }
    
    artworks.forEach(artwork => {
        const card = createArtworkCard(artwork);
        recommendedGrid.appendChild(card);
    });
}

// Load similar artworks for the detail view
function loadSimilarArtworks(artwork) {
    // Find similar artworks (same category or artist)
    const similarArtworks = galleryData.artworks.filter(a => 
        a.id !== artwork.id && (a.category === artwork.category || a.artist === artwork.artist)
    ).slice(0, 3);
    
    if (similarArtworks.length > 0) {
        const container = document.createElement('div');
        container.className = 'similar-artworks';
        container.innerHTML = `<h3>Similar Artworks</h3>`;
        
        const grid = document.createElement('div');
        grid.className = 'recommendation-grid';
        
        similarArtworks.forEach(similar => {
            const card = createArtworkCard(similar);
            grid.appendChild(card);
        });
        
        container.appendChild(grid);
        document.getElementById('artwork-modal-content').appendChild(container);
    }
}
