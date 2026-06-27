/*Assignment C++: 3
Author: Tomer Benveniste, ID: 207961954 / Carmi Frank, ID: 206463846
*/
#include "Shape.h"
#include <cstring> // For dynamic string operations
#include <stdexcept> // for throwing exceptions
using namespace std;

// default Constructor
Shape::Shape() {
    this->color = nullptr;
}

// parameterized Constructor
Shape::Shape(const char* color, int width) {
    this->color = nullptr; // needed because setColor() deletes this->color, therefore needed to be initialized
    this->setColor(color);
    this->setWidth(width);
}

// Destructor
Shape::~Shape() {
    delete[] this->color;
}

// Getters & Setters
const char* Shape::getColor() const {
    return this->color; // Return color value
}

void Shape::setColor(const char* newColor) {
    // Input validation
    if (newColor == nullptr) {
        throw invalid_argument("User entered nullptr - invalid input");
    }
    if (strcmp(newColor, "red") != 0 && strcmp(newColor, "blue") != 0 && strcmp(newColor, "green") != 0) {
        throw invalid_argument("User entered a wrong color - invalid input");
    }
    // input is valid
    delete[] this->color; // Freeing prior color memory
    int length = strlen(newColor); // defining new length to suit new color string
    this->color = new char[length + 1]; // pointing to the new allocated memory
    strcpy(this->color, newColor); // copy the new color string into the new allocated memory
}

int Shape::getWidth() const {
    return this->width; // Return width value
}

void Shape::setWidth(int newWidth) {
    // input validation
    if (newWidth <= 0) {
        throw invalid_argument("User entered a non-positive width - invalid input");
    }
    this->width = newWidth;
}

// Note: getPerimeter() and getArea() are pure virtual (= 0) in Shape.h, 
// so they do not get implemented in Shape.cpp.