/*Assignment C++: 3
Author: Tomer Benveniste, ID: 207961954 / Carmi Frank, ID: 206463846
*/
#include "OrthogonalTriangle.h"
#include <stdexcept>
#include <cmath> // sqrt() is defined here
#include <iostream>
using namespace std;

// default Constructor
OrthogonalTriangle::OrthogonalTriangle() : side(1.0) {
}

// parameterized Constructor
OrthogonalTriangle::OrthogonalTriangle(const char* color, int width, double side) : Shape(color, width) {
    this->setSide(side);
}

// Destructor
OrthogonalTriangle::~OrthogonalTriangle() {
}

// Getters & Setters
double OrthogonalTriangle::getSide() const {
    return this->side; // return side value
}

void OrthogonalTriangle::setSide(double newSide) {
    // input validation
    if (newSide <= 0.0) {
        throw invalid_argument("Out of range");
    }
    // input is valid
    this->side = newSide;
}

// draw method that draws the triangle with '*'
void OrthogonalTriangle::draw() const {
    int lower_side = (int) this->side;
    // if lower_side = 0 -> nothing to print
    if (lower_side == 0) {
        throw invalid_argument("Out of range");
    }
    // loop that draws the orthogonal triangle
    for (int i = 0; i < lower_side; i++) {
        for (int j = 0; j <= i; j++) {
            cout << "*";
        }
        cout << endl;
    }
}

// Implementation of abstract methods
double OrthogonalTriangle::getPerimeter() const {
    // calculation of orthogonal triangle perimeter
    double hypotenuse = sqrt(this->side * this->side + this->side * this->side);
    return 2 * this->side + hypotenuse; // return perimeter value
}

double OrthogonalTriangle::getArea() const {
    // calculation of orthogonal triangle area
    return (this->side * this->side) / 2.0; // return area value
}