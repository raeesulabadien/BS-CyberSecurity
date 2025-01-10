// Program to calculate the number of full 360° rotations
// Author: Raees

#include <iostream>
#include <string>

using namespace std;

int calculateFullRotations(const string directions[], int size) {
    int angle = 0;

    // Iterate through each direction in the list
    for (int i = 0; i < size; ++i) {
        if (directions[i] == "left") {
            angle -= 90; // Subtract 90° for each "left" direction
        } else if (directions[i] == "right") {
            angle += 90; // Add 90° for each "right" direction
        }
    }

    // Calculate the number of full 360° rotations
    int fullRotations = abs(angle) / 360;
    return fullRotations;
}

int main() {
    string directions[] = {"right", "right", "right", "right", "left", "left", "left", "left"};
    int size = sizeof(directions) / sizeof(directions[0]);
    int rotations = calculateFullRotations(directions, size);
    cout << "Full 360° rotations: " << rotations << endl;
    return 0;
}