#include <iostream>
using namespace std;

// Function to calculate the number of trees that can be planted on the edges of the given land
int plantTrees(int w, int l, int g) {
    // Check if the layout is symmetrical
    if ((w - 1) % (g + 1) != 0 || (l - 1) % (g + 1) != 0) {
        return -1; // Return -1 if the layout is not symmetrical
    }

    // Calculate the number of trees that can be planted on the edges
    int treesOnWidth = (w - 1) / (g + 1) + 1;
    int treesOnLength = (l - 1) / (g + 1) + 1;

    // Calculate the total number of trees
    int totalTrees = 2 * (treesOnWidth + treesOnLength - 2);

    return totalTrees;
}

int main() {
    // Test cases
    cout << "Number of trees that can be planted: " << plantTrees(3, 3, 1) << endl; // Output: 4
    cout << "Number of trees that can be planted: " << plantTrees(3, 3, 3) << endl; // Output: 2
    cout << "Number of trees that can be planted: " << plantTrees(4, 4, 1) << endl; // Output: -1 (unsymmetrical)

    return 0;
}

// Raees