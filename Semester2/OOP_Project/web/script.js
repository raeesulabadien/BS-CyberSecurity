// Enhanced gallery data with all C++ backend functions
let galleryData = {
    name: "Digital Art Gallery",
    artworks: [
        {
            id: 1,
            title: "Starry Night",
            artist: "Van Gogh",
            category: "Impressionism",
            price: 100000000
        },
        {
            id: 2,
            title: "Mona Lisa",
            artist: "Da Vinci",
            category: "Renaissance",
            price: 850000000
        },
        {
            id: 3,
            title: "The Scream",
            artist: "Munch",
            category: "Expressionism",
            price: 120000000
        }
    ]
};

// Initialize when page loads
document.addEventListener('DOMContentLoaded', function() {
    showAllArtworks();
    updateArtworkCount();
});

// Navigation - Show specific section
function showSection(sectionName) {
    // Hide all sections
    const sections = document.querySelectorAll('.section');
    sections.forEach(section => section.classList.remove('active'));
    
    // Show selected section
    document.getElementById(sectionName + '-section').classList.add('active');
    
    // Update nav buttons
    const navBtns = document.querySelectorAll('.nav-btn');
    navBtns.forEach(btn => btn.classList.remove('active'));
    event.target.classList.add('active');
    
    // Load content based on section
    if (sectionName === 'all') {
        showAllArtworks();
    }
}

// Display all artworks (matches C++ showAll function)
function showAllArtworks() {
    const grid = document.getElementById('artworks-grid');
    grid.innerHTML = '';
    
    galleryData.artworks.forEach(artwork => {
        const card = createArtworkCard(artwork);
        grid.appendChild(card);
    });
    
    updateArtworkCount();
}

// Create artwork card with improved design
function createArtworkCard(artwork) {
    const card = document.createElement('div');
    card.className = 'artwork-card';
    card.onclick = () => showArtworkDetail(artwork);
    
    card.innerHTML = `
        <div class="artwork-id">#${artwork.id}</div>
        <div class="artwork-title">${artwork.title}</div>
        <div class="artwork-artist">by ${artwork.artist}</div>
        <div class="artwork-category">${artwork.category}</div>
        <div class="artwork-price">$${formatPrice(artwork.price)}</div>
    `;
    
    return card;
}

// Search by Artist (matches C++ searchByArtist function)
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

// Search by Category (matches C++ searchByCategory function)
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

// Find by ID (matches C++ findById function)
function findById() {
    const id = parseInt(document.getElementById('id-input').value);
    if (!id) {
        showToast('Please enter a valid ID', 'error');
        return;
    }
    
    const result = galleryData.artworks.find(artwork => artwork.id === id);
    const results = result ? [result] : [];
    
    displaySearchResults(results, `ID ${id}`);
}

// Display search results
function displaySearchResults(results, searchTerm) {
    const container = document.getElementById('search-results');
    container.innerHTML = '';
    
    if (results.length === 0) {
        container.innerHTML = `<div class="error">No artworks found for ${searchTerm}</div>`;
        return;
    }
    
    results.forEach(artwork => {
        const card = createArtworkCard(artwork);
        container.appendChild(card);
    });
    
    showToast(`Found ${results.length} artwork(s) for ${searchTerm}`);
}

// Add New Artwork (matches C++ add functionality)
function addArtwork(event) {
    event.preventDefault();
    
    const id = parseInt(document.getElementById('new-id').value);
    const title = document.getElementById('new-title').value.trim();
    const artist = document.getElementById('new-artist').value.trim();
    const category = document.getElementById('new-category').value.trim();
    const price = parseFloat(document.getElementById('new-price').value);
    
    // Check if ID already exists
    if (galleryData.artworks.find(artwork => artwork.id === id)) {
        showToast('Artwork with this ID already exists!', 'error');
        return;
    }
    
    // Add new artwork
    const newArtwork = { id, title, artist, category, price };
    galleryData.artworks.push(newArtwork);
    
    // Reset form
    document.getElementById('add-form').reset();
    
    // Show success message
    showToast('Artwork added successfully!');
    
    // Update display
    updateArtworkCount();
    
    // Switch to all artworks view
    showSection('all');
    showAllArtworks();
}

// Save to File (matches C++ saveToFile function)
function saveToFile() {
    const data = formatGalleryData();
    downloadFile('gallery_data.txt', data);
    showToast('Gallery data saved to file!');
}

// Show Statistics (matches C++ gallery statistics)
function showStats() {
    const totalArtworks = galleryData.artworks.length;
    const categories = [...new Set(galleryData.artworks.map(a => a.category))];
    const artists = [...new Set(galleryData.artworks.map(a => a.artist))];
    
    const prices = galleryData.artworks.map(a => a.price);
    const minPrice = Math.min(...prices);
    const maxPrice = Math.max(...prices);
    const avgPrice = prices.reduce((sum, price) => sum + price, 0) / prices.length;
    const totalValue = prices.reduce((sum, price) => sum + price, 0);
    
    const statsHtml = `
        <h3>Gallery Statistics</h3>
        <div style="display: grid; grid-template-columns: repeat(auto-fit, minmax(200px, 1fr)); gap: 20px; margin-top: 20px;">
            <div style="text-align: center; padding: 20px; background: rgba(15, 23, 42, 0.6); border-radius: 8px;">
                <div style="font-size: 2rem; font-weight: bold; color: #3b82f6;">${totalArtworks}</div>
                <div style="color: #94a3b8;">Total Artworks</div>
            </div>
            <div style="text-align: center; padding: 20px; background: rgba(15, 23, 42, 0.6); border-radius: 8px;">
                <div style="font-size: 2rem; font-weight: bold; color: #10b981;">${categories.length}</div>
                <div style="color: #94a3b8;">Categories</div>
            </div>
            <div style="text-align: center; padding: 20px; background: rgba(15, 23, 42, 0.6); border-radius: 8px;">
                <div style="font-size: 2rem; font-weight: bold; color: #f59e0b;">${artists.length}</div>
                <div style="color: #94a3b8;">Artists</div>
            </div>
            <div style="text-align: center; padding: 20px; background: rgba(15, 23, 42, 0.6); border-radius: 8px;">
                <div style="font-size: 1.5rem; font-weight: bold; color: #34d399;">$${formatPrice(avgPrice)}</div>
                <div style="color: #94a3b8;">Average Price</div>
            </div>
        </div>
        
        <div style="margin-top: 30px;">
            <h4 style="margin-bottom: 15px; color: #e2e8f0;">Categories:</h4>
            <div style="display: flex; flex-wrap: wrap; gap: 10px;">
                ${categories.map(cat => `<span style="background: rgba(59, 130, 246, 0.2); color: #93c5fd; padding: 6px 12px; border-radius: 15px; font-size: 0.9rem;">${cat}</span>`).join('')}
            </div>
        </div>
        
        <div style="margin-top: 20px;">
            <h4 style="margin-bottom: 15px; color: #e2e8f0;">Artists:</h4>
            <div style="display: flex; flex-wrap: wrap; gap: 10px;">
                ${artists.map(artist => `<span style="background: rgba(16, 185, 129, 0.2); color: #6ee7b7; padding: 6px 12px; border-radius: 15px; font-size: 0.9rem;">${artist}</span>`).join('')}
            </div>
        </div>
        
        <div style="margin-top: 30px; padding: 20px; background: rgba(15, 23, 42, 0.6); border-radius: 8px;">
            <h4 style="margin-bottom: 15px; color: #e2e8f0;">Price Statistics:</h4>
            <div style="display: grid; grid-template-columns: repeat(auto-fit, minmax(150px, 1fr)); gap: 15px; text-align: center;">
                <div>
                    <div style="color: #94a3b8; font-size: 0.9rem;">Minimum</div>
                    <div style="color: #f8fafc; font-weight: bold;">$${formatPrice(minPrice)}</div>
                </div>
                <div>
                    <div style="color: #94a3b8; font-size: 0.9rem;">Maximum</div>
                    <div style="color: #f8fafc; font-weight: bold;">$${formatPrice(maxPrice)}</div>
                </div>
                <div>
                    <div style="color: #94a3b8; font-size: 0.9rem;">Total Value</div>
                    <div style="color: #34d399; font-weight: bold;">$${formatPrice(totalValue)}</div>
                </div>
            </div>
        </div>
    `;
    
    document.getElementById('stats-display').innerHTML = statsHtml;
}

// Export Data (matches C++ export functionality)
function exportData() {
    const jsonData = JSON.stringify(galleryData, null, 2);
    downloadFile('gallery_export.json', jsonData);
    showToast('Gallery data exported successfully!');
}

// Show artwork detail in modal
function showArtworkDetail(artwork) {
    const modal = document.getElementById('artwork-modal');
    const detail = document.getElementById('artwork-detail');
    
    detail.innerHTML = `
        <h2 style="margin-bottom: 20px; color: #e2e8f0;">${artwork.title}</h2>
        <div style="display: grid; gap: 15px;">
            <div><strong>ID:</strong> ${artwork.id}</div>
            <div><strong>Artist:</strong> ${artwork.artist}</div>
            <div><strong>Category:</strong> ${artwork.category}</div>
            <div><strong>Price:</strong> <span style="color: #34d399; font-weight: bold;">$${formatPrice(artwork.price)}</span></div>
        </div>
    `;
    
    modal.style.display = 'block';
}

// Close modal
function closeModal() {
    document.getElementById('artwork-modal').style.display = 'none';
}

// Format price with commas
function formatPrice(price) {
    return price.toLocaleString();
}

// Update artwork count display
function updateArtworkCount() {
    document.getElementById('artwork-count').textContent = `${galleryData.artworks.length} Artworks`;
}

// Format gallery data for file export (matches C++ file format)
function formatGalleryData() {
    let data = `${galleryData.name}\n`;
    data += `${galleryData.artworks.length}\n`;
    
    galleryData.artworks.forEach(artwork => {
        data += `${artwork.id}\n`;
        data += `${artwork.title}\n`;
        data += `${artwork.artist}\n`;
        data += `${artwork.category}\n`;
        data += `${artwork.price}\n`;
    });
    
    return data;
}

// Download file utility
function downloadFile(filename, content) {
    const element = document.createElement('a');
    element.setAttribute('href', 'data:text/plain;charset=utf-8,' + encodeURIComponent(content));
    element.setAttribute('download', filename);
    element.style.display = 'none';
    document.body.appendChild(element);
    element.click();
    document.body.removeChild(element);
}

// Show toast notification
function showToast(message, type = 'success') {
    const toast = document.getElementById('toast');
    toast.textContent = message;
    
    if (type === 'error') {
        toast.style.background = 'linear-gradient(135deg, #dc2626, #ef4444)';
    } else {
        toast.style.background = 'linear-gradient(135deg, #059669, #10b981)';
    }
    
    toast.classList.add('show');
    setTimeout(() => {
        toast.classList.remove('show');
    }, 3000);
}

// Close modal when clicking outside
window.onclick = function(event) {
    const modal = document.getElementById('artwork-modal');
    if (event.target === modal) {
        closeModal();
    }
}

// Enter key support for search inputs
document.getElementById('artist-input').addEventListener('keypress', function(e) {
    if (e.key === 'Enter') searchByArtist();
});

document.getElementById('category-input').addEventListener('keypress', function(e) {
    if (e.key === 'Enter') searchByCategory();
});

document.getElementById('id-input').addEventListener('keypress', function(e) {
    if (e.key === 'Enter') findById();
});