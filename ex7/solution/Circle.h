/*Assignment C++: 3
Author: Tomer Benveniste, ID: 207961954 / Carmi Friedman, ID: 206463846
*/
#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"

class Circle : public Shape {
private:
    int radius; // רדיוס[cite: 1]

public:
    // בנאים והורסים
    Circle(); // בנאי דיפולטיבי[cite: 1]
    Circle(const char* color, int width, int radius);
    virtual ~Circle(); // Destructor[cite: 1]

    // מתודות Get & Set[cite: 1]
    int getRadius() const;
    void setRadius(int newRadius);

    // מימוש מתודות אבסטרקטיות (אין draw למעגל)[cite: 1]
    virtual double getPerimeter() const override;
    virtual double getArea() const override;
};

#endif // CIRCLE_H