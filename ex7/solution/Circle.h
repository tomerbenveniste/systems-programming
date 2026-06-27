/*Assignment C++: 3
Author: Tomer Benveniste, ID: 207961954  /  Carmi Frank, ID: 206463846
*/
#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"

class Circle : public Shape {
private:
    int radius; // Radius

public:
    // Constructors and Destructor
    Circle(); // Default constructor
    Circle(const char* color, int width, int radius); // parameterized constructor
    virtual ~Circle(); // Destructor

    // Getters & Setters
    int getRadius() const;
    void setRadius(int newRadius);

    // Implementation of abstract methods (No draw method for circle)
    virtual double getPerimeter() const override;
    virtual double getArea() const override;
};

#endif // CIRCLE_H