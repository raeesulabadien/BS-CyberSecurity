// This program calculates the number of years until (or since) a father is (or was) twice as old as his son.

#include <iostream>
#include <cmath>

using namespace std;

// Function to calculate the number of years until (or since) the father is (or was) twice as old as his son.
int yearsUntilTwiceAge(int fatherAge, int sonAge) {
    return abs(fatherAge - 2 * sonAge);
}

int main() {
    int fatherAge, sonAge;
    
    // Prompt the user to enter the father's current age.
    cout << "Enter father's current age: ";
    cin >> fatherAge;
    
    // Prompt the user to enter the son's current age.
    cout << "Enter son's current age: ";
    cin >> sonAge;

    // Calculate the number of years until (or since) the father is (or was) twice as old as his son.
    int years = yearsUntilTwiceAge(fatherAge, sonAge);
    
    // Determine if the father was twice as old as his son in the past or will be in the future.
    if (fatherAge > 2 * sonAge) {
        cout << "The father was twice as old as his son " << years << " years ago." << endl;
    } else {
        cout << "The father will be twice as old as his son in " << years << " years." << endl;
    }

    return 0;
}
