/*Assignment C++: 3
Author: Tomer Benveniste, ID: 207961954 / Carmi Friedman, ID: 206463846
*/

#ifndef SQUARE_H
#define SQUARE_H

#include "Shape.h"

class Square : public Shape {
private:
    double side; // אורך צלע הריבוע[cite: 1]

public:
    // בנאים והורסים
    Square(); // בנאי דיפולטיבי[cite: 1]
    Square(const char* color, int width, double side);
    virtual ~Square(); // Destructor[cite: 1]

    // מתודות Get & Set[cite: 1]
    double getSide() const;
    void setSide(double newSide);

    // מתודות ייחודיות
    void draw() const; // מציגה ריבוע של כוכביות[cite: 1]

    // מימוש מתודות אבסטרקטיות[cite: 1]
    virtual double getPerimeter() const override;
    virtual double getArea() const override;
};

#endif // SQUARE_H