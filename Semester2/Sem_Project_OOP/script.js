// Debug version of script.js
document.addEventListener('DOMContentLoaded', function() {
    console.log('Page loaded, attempting to load gallery data...');
    loadGalleryData();
});

async function loadGalleryData() {
    try {
        console.log('Attempting to fetch gallery_data.json...');
        
        // First, let's try to see if the file exists
        const response = await fetch('gallery_data.json');
        console.log('Fetch response:', response);
        console.log('Response status:', response.status);
        console.log('Response ok:', response.ok);
        
        if (!response.ok) {
            throw new Error(`HTTP error! status: ${response.status}`);
        }
        
        const galleryData = await response.json();
        console.log('Gallery data loaded successfully:', galleryData);
        
        if (!galleryData.artworks || galleryData.artworks.length === 0) {
            throw new Error('No artworks found in gallery data');
        }
        
        displayArtworks(galleryData.artworks);
        setupCategories(galleryData.artworks);
        
        // Store globally for other functions
        window.galleryData = galleryData;
        
    } catch (error) {
        console.error('Error loading gallery data:', error);
        displayError('Error loading gallery data: ' + error.message + 
                    '<br><br>Debug info:<br>' +
                    '1. Make sure gallery_data.json exists in the same folder<br>' +
                    '2. Check browser console (F12) for more details<br>' +
                    '3. Try using a local server instead of opening the file directly');
    }
}

// Rest of your functions remain the same...
function displayArtworks(artworks) {
    const container = document.getElementById('artworks-grid');
    
    if (!artworks || artworks.length === 0) {
        container.innerHTML = '<div class="error">No artworks found.</div>';
        return;
    }
    
    container.innerHTML = artworks.map(artwork => `
        <div class="artwork-card" onclick="showArtworkDetail(${artwork.id})">
            <img src="${artwork.imageUrl}" alt="${artwork.title}" class="artwork-image" 
                 onerror="this.src='data:image/svg+xml;base64,PHN2ZyB3aWR0aD0iMzAwIiBoZWlnaHQ9IjIwMCIgeG1sbnM9Imh0dHA6Ly93d3cudzMub3JnLzIwMDAvc3ZnIj48cmVjdCB3aWR0aD0iMTAwJSIgaGVpZ2h0PSIxMDAlIiBmaWxsPSIjZGRkIi8+PHRleHQgeD0iNTAlIiB5PSI1MCUiIGZvbnQtZmFtaWx5PSJBcmlhbCIgZm9udC1zaXplPSIxOCIgZmlsbD0iIzk5OSIgdGV4dC1hbmNob3I9Im1pZGRsZSIgZHk9Ii4zZW0iPkltYWdlIE5vdCBGb3VuZDwvdGV4dD48L3N2Zz4='">
            <div class="artwork-info">
                <div class="artwork-title">${artwork.title}</div>
                <div class="artwork-artist">by ${artwork.artist}</div>
                <div class="artwork-category">${artwork.category}</div>
                <div class="artwork-price">$${formatPrice(artwork.price)}</div>
            </div>
        </div>
    `).join('');
}

function formatPrice(price) {
    return price.toLocaleString('en-US', {
        minimumFractionDigits: 0,
        maximumFractionDigits: 0
    });
}

function setupCategories(artworks) {
    const categories = [...new Set(artworks.map(artwork => artwork.category))];
    const container = document.getElementById('categories-list');
    
    container.innerHTML = categories.map(category => {
        const count = artworks.filter(artwork => artwork.category === category).length;
        return `
            <div class="category-card" onclick="filterByCategory('${category}')">
                <h3>${category}</h3>
                <p>${count} artwork${count !== 1 ? 's' : ''}</p>
            </div>
        `;
    }).join('');
}

function displayError(message) {
    const container = document.getElementById('artworks-grid');
    container.innerHTML = `<div class="error">${message}</div>`;
}

// Add basic navigation functions
function showAllArtworks() {
    document.querySelectorAll('.content-section').forEach(s => s.classList.remove('active'));
    document.getElementById('artworks-section').classList.add('active');
    document.querySelectorAll('.nav-btn').forEach(b => b.classList.remove('active'));
    document.getElementById('all-btn').classList.add('active');
}

function showCategories() {
    document.querySelectorAll('.content-section').forEach(s => s.classList.remove('active'));
    document.getElementById('categories-section').classList.add('active');
    document.querySelectorAll('.nav-btn').forEach(b => b.classList.remove('active'));
    document.getElementById('cat-btn').classList.add('active');
}

function showSearch() {
    document.querySelectorAll('.content-section').forEach(s => s.classList.remove('active'));
    document.getElementById('search-section').classList.add('active');
    document.querySelectorAll('.nav-btn').forEach(b => b.classList.remove('active'));
    document.getElementById('search-btn').classList.add('active');
}