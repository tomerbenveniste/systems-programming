/*Assignment C++: 3
Author: Tomer Benveniste, ID: 207961954 / Carmi Frank, ID: 206463846
*/
#include "Circle.h"
#define _USE_MATH_DEFINES
#include <cmath> // M_PI is defined here
#include <stdexcept> // for throwing exceptions

// default Constructor
Circle::Circle() : radius(1) {
}

// parametrized constructor with an initialized list for a derived class (Circle inherits from Shape)
Circle::Circle(const char* color, int width, int radius) : Shape(color, width), radius(radius) {
}

// Destructor
Circle::~Circle() {
}

// Getters & Setters
int Circle::getRadius() const {
    return this->radius; // return radius value
}

void Circle::setRadius(int newRadius) {
    // input validation
    if (newRadius <= 0) {
        throw std::invalid_argument("Circle::setRadius - non-positive radius - invalid input");
    }
    // input is valid
    this->radius = newRadius;
}

// Implementation of abstract methods
double Circle::getPerimeter() const {
    // perimeter calculation using M_PI
    return 2 * M_PI * this->radius; // return perimeter value
}

double Circle::getArea() const {
    // area calculation using M_PI
    return M_PI * (this->radius) * (this->radius); // return area value
}