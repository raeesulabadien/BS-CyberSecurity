// Program to determine the final state of YouTube like/dislike buttons
// Programmer: Raees

#include <iostream>
#include <string>

using namespace std;

enum class ButtonState {
    NONE,
    LIKE,
    DISLIKE
};

ButtonState getFinalState(const string inputs[], int size) {
    ButtonState state = ButtonState::NONE;

    for (int i = 0; i < size; ++i) {
        if (inputs[i] == "like") {
            if (state == ButtonState::LIKE) {
                state = ButtonState::NONE; // Undo like
            } else {
                state = ButtonState::LIKE; // Set to like
            }
        } else if (inputs[i] == "dislike") {
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
    string inputs[] = {"like", "dislike", "like", "like", "dislike"};
    int size = sizeof(inputs) / sizeof(inputs[0]);
    ButtonState finalState = getFinalState(inputs, size);

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