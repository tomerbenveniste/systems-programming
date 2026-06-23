/*Assignment C++: 3
Author: Israel Israeli, ID: 01234567
*/
#ifndef ORTHOGONALTRIANGLE_H
#define ORTHOGONALTRIANGLE_H

#include "Shape.h"

class OrthogonalTriangle : public Shape {
private:
    double side; // Leg length[cite: 1]

public:
    // Constructors and Destructor
    OrthogonalTriangle(); // Default constructor[cite: 1]
    OrthogonalTriangle(const char* color, int width, double side);
    virtual ~OrthogonalTriangle(); // Destructor[cite: 1]

    // Getters & Setters[cite: 1]
    double getSide() const;
    void setSide(double newSide);

    // Specific methods
    void draw() const; // Displays an orthogonal triangle of asterisks[cite: 1]

    // Implementation of abstract methods[cite: 1]
    virtual double getPerimeter() const override;
    virtual double getArea() const override;
};

#endif // ORTHOGONALTRIANGLE_H