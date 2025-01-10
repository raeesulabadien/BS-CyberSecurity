// This program simulates the like and dislike button functionality on YouTube.
// Author: Raees

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Function to determine the final state of the like/dislike buttons
string finalState(const vector<string>& inputs) {
    string state = "none";

    for (const auto& input : inputs) {
        if (input == "like") {
            if (state == "like") {
                state = "none"; // Undo like
            } else {
                state = "like"; // Set to like
            }
        } else if (input == "dislike") {
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
    vector<string> inputs = {"like", "dislike", "like", "like"};
    cout << "Final state: " << finalState(inputs) << endl;
    return 0;
}