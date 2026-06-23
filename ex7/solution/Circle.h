/*Assignment C++: 3
Author: Israel Israeli, ID: 01234567
*/
#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"

class Circle : public Shape {
private:
    int radius; // Radius[cite: 1]

public:
    // Constructors and Destructor
    Circle(); // Default constructor[cite: 1]
    Circle(const char* color, int width, int radius);
    virtual ~Circle(); // Destructor[cite: 1]

    // Getters & Setters[cite: 1]
    int getRadius() const;
    void setRadius(int newRadius);

    // Implementation of abstract methods (No draw method for circle)[cite: 1]
    virtual double getPerimeter() const override;
    virtual double getArea() const override;
};

#endif // CIRCLE_H