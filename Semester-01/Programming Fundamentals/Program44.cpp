// This program simulates the like and dislike button functionality on YouTube.
// Author: Raees

#include <iostream>
#include <string>

using namespace std;

// Function to determine the final state of the like/dislike buttons
string finalState(const string inputs[], int size) {
    string state = "none";

    for (int i = 0; i < size; ++i) {
        if (inputs[i] == "like") {
            if (state == "like") {
                state = "none"; // Undo like
            } else {
                state = "like"; // Set to like
            }
        } else if (inputs[i] == "dislike") {
            if (state == "dislike") {
                state = "none"; // Undo dislike
            } else {
                state = "dislike"; // Set to dislike
            }
        }
    }

    return state;
}

int main() {
    string inputs[] = {"like", "dislike", "like", "like"};
    int size = sizeof(inputs) / sizeof(inputs[0]);
    cout << "Final state: " << finalState(inputs, size) << endl;
    return 0;
}