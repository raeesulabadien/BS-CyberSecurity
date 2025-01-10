#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

// Function to check if all cargo can fit on the ship
bool canFitCargo(int totalCargo, const vector<char>& cargoHolds) {
    int totalSpace = 0;

    for (char hold : cargoHolds) {
        switch (hold) {
            case 'S':
                totalSpace += 50;
                break;
            case 'M':
                totalSpace += 100;
                break;
            case 'L':
                totalSpace += 200;
                break;
            default:
                cerr << "Invalid cargo hold type: " << hold << endl;
                return false;
        }
    }

    return totalCargo <= totalSpace;
}

int main() {
    // Total cargo to be transported
    int totalCargo = 350;
    // Types of cargo holds in the ship
    vector<char> cargoHolds = {'S', 'M', 'L', 'M'};

    // Check if all cargo can fit on the ship
    if (canFitCargo(totalCargo, cargoHolds)) {
        cout << "All cargo can fit on the ship." << endl;
    } else {
        cout << "Not all cargo can fit on the ship." << endl;
    }

    return 0;
}

// Program by Raees