/*Assignment C++: 3
Author: Tomer Benveniste, ID: 207961954  /  Carmi Frank, ID: 206463846
*/
#ifndef ORTHOGONALTRIANGLE_H
#define ORTHOGONALTRIANGLE_H

#include "Shape.h"

class OrthogonalTriangle : public Shape {
private:
    double side; // Leg length

public:
    // Constructors and Destructor
    OrthogonalTriangle(); // Default constructor
    OrthogonalTriangle(const char* color, int width, double side);
    virtual ~OrthogonalTriangle(); // Destructor

    // Getters & Setters
    double getSide() const;
    void setSide(double newSide);

    // Specific methods
    void draw() const; // Displays an orthogonal triangle of asterisks

    // Implementation of abstract methods
    virtual double getPerimeter() const override;
    virtual double getArea() const override;
};

#endif // ORTHOGONALTRIANGLE_H