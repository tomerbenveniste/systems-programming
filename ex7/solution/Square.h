/*Assignment C++: 3
Author: Tomer Benveniste, ID: 207961954  /  Carmi Frank, ID: 206463846
*/
#ifndef SQUARE_H
#define SQUARE_H

#include "Shape.h"

class Square : public Shape {
private:
    double side; // Side length of the square

public:
    Square(); // Default constructor
    Square(const char* color, int width, double side); // parameterized constructor
    virtual ~Square(); // Destructor

    // Getters & Setters
    double getSide() const;
    void setSide(double newSide);

    // Specific methods
    void draw() const; // Displays a square of asterisks

    // Implementation of abstract methods
    virtual double getPerimeter() const override;
    virtual double getArea() const override;
};

#endif // SQUARE_H