#include <iostream>

using namespace std;

// Function to check if all cargo can fit on the ship
bool canFitCargo(int totalCargo, const char cargoHolds[], int size) {
    int totalSpace = 0;

    for (int i = 0; i < size; ++i) {
        switch (cargoHolds[i]) {
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
                cerr << "Invalid cargo hold type: " << cargoHolds[i] << endl;
                return false;
        }
    }

    return totalCargo <= totalSpace;
}

int main() {
    // Total cargo to be transported
    int totalCargo = 350;
    // Types of cargo holds in the ship
    char cargoHolds[] = {'S', 'M', 'L', 'M'};
    int size = sizeof(cargoHolds) / sizeof(cargoHolds[0]);

    // Check if all cargo can fit on the ship
    if (canFitCargo(totalCargo, cargoHolds, size)) {
        cout << "All cargo can fit on the ship." << endl;
    } else {
        cout << "Not all cargo can fit on the ship." << endl;
    }

    return 0;
}

// Program by Raees
