/*Assignment C++: 3
Author: Tomer Benveniste, ID: 207961954 / Carmi Frank, ID: 206463846
*/
#include "Square.h"
#include <stdexcept>
#include <iostream>
using namespace std;

// default Constructor
Square::Square() : side(1.0) {
}

// parameterized Constructor
Square::Square(const char* color, int width, double side) : Shape(color, width) {
    this->setSide(side);
}

// Destructor
Square::~Square() {
}

// Getters & Setters
double Square::getSide() const {
    return this->side; // return side value
}

void Square::setSide(double newSide) {
    // input validation
    if (newSide <= 0) {
        throw invalid_argument("Square::setSide: non-positive side - invalid input");
    }
    // input is valid
    this->side = newSide;
}

// draw method draws in '*' the square given its side (lower value rounding id necessary)
void Square::draw() const {
    int lower_side = (int) this->side; // getting lower value of side for the drawing
    // if side is 0 -> no '*' should be printed
    if (lower_side <= 0) {
        throw invalid_argument("Square::draw: non-positive side - no drawing available");
    }
    // loop that draws the square
    for (int i = 0; i < lower_side; i++) {
        for (int j = 0; j < lower_side; j++) {
            cout << "*";
        }
        cout << endl;
    }
}

// Implementation of abstract methods
double Square::getPerimeter() const {
    // calculating square perimeter
    return 4 * this->side; // return perimeter value
}

double Square::getArea() const {
    // calculating square area
    return (this->side * this->side); // return area value
}