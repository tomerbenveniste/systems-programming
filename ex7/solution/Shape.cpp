/*Assignment C++: 3
Author: Tomer Benveniste, ID: 207961954 / Carmi Frank, ID: 206463846
*/
#include "Shape.h"
#include <cstring> // For dynamic string operations

// Constructors and Destructor
Shape::Shape() {
}

Shape::Shape(const char* color, int width) {
}

Shape::~Shape() {
}

// Getters & Setters
const char* Shape::getColor() const {
    return nullptr; // Temporary return value
}

void Shape::setColor(const char* newColor) {
}

int Shape::getWidth() const {
    return 0; // Temporary return value
}

void Shape::setWidth(int newWidth) {
}

// Note: getPerimeter() and getArea() are pure virtual (= 0) in Shape.h, 
// so they do not get implemented in Shape.cpp.