// Program to determine the final state of YouTube like/dislike buttons
// Programmer: Raees

#include <iostream>
#include <vector>
#include <string>

using namespace std;

enum class ButtonState {
    NONE,
    LIKE,
    DISLIKE
};

ButtonState getFinalState(const vector<string>& inputs) {
    ButtonState state = ButtonState::NONE;

    for (const auto& input : inputs) {
        if (input == "like") {
            if (state == ButtonState::LIKE) {
                state = ButtonState::NONE; // Undo like
            } else {
                state = ButtonState::LIKE; // Set to like
            }
        } else if (input == "dislike") {
            if (state == ButtonState::DISLIKE) {
                state = ButtonState::NONE; // Undo dislike
            } else {
                state = ButtonState::DISLIKE; // Set to dislike
            }
        }
    }

    return state;
}

int main() {
    vector<string> inputs = {"like", "dislike", "like", "like", "dislike"};
    ButtonState finalState = getFinalState(inputs);

    switch (finalState) {
        case ButtonState::NONE:
            cout << "Final state: NONE" << endl;
            break;
        case ButtonState::LIKE:
            cout << "Final state: LIKE" << endl;
            break;
        case ButtonState::DISLIKE:
            cout << "Final state: DISLIKE" << endl;
            break;
    }

    return 0;
}