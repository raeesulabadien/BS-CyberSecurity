// Program to calculate the area and perimeter of a circle
// Author: Raees

#include <iostream>
#include <cmath>

using namespace std;

class Circle {
private:
    double radius;

public:
    // Constructor
    Circle(double r) : radius(r) {}

    // Getter for area
    double getArea() const {
        return M_PI * radius * radius;
    }

    // Getter for perimeter (circumference)
    double getPerimeter() const {
        return 2 * M_PI * radius;
    }
};

int main() {
    Circle circle(5.0); // Example radius

    // Output the area of the circle
    cout << "Area: " << circle.getArea() << endl;

    // Output the perimeter of the circle
    cout << "Perimeter: " << circle.getPerimeter() << endl;

    return 0;
}