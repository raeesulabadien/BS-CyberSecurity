// Program to calculate the number of full 360° rotations
// Author: Raees

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int calculateFullRotations(const vector<string>& directions) {
    int angle = 0;

    // Iterate through each direction in the list
    for (const string& direction : directions) {
        if (direction == "left") {
            angle -= 90; // Subtract 90° for each "left" direction
        } else if (direction == "right") {
            angle += 90; // Add 90° for each "right" direction
        }
    }

    // Calculate the number of full 360° rotations
    int fullRotations = abs(angle) / 360;
    return fullRotations;
}

int main() {
    vector<string> directions = {"right", "right", "right", "right", "left", "left", "left", "left"};
    int rotations = calculateFullRotations(directions);
    cout << "Full 360° rotations: " << rotations << endl;
    return 0;
}