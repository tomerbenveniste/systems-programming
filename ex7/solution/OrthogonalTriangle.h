/*Assignment C++: 3
Author: Tomer Benveniste, ID: 207961954 / Carmi Friedman, ID: 206463846
*/

#ifndef ORTHOGONALTRIANGLE_H
#define ORTHOGONALTRIANGLE_H

#include "Shape.h"

class OrthogonalTriangle : public Shape {
private:
    double side; // אורך השוקיים[cite: 1]

public:
    // בנאים והורסים
    OrthogonalTriangle(); // בנאי דיפולטיבי[cite: 1]
    OrthogonalTriangle(const char* color, int width, double side);
    virtual ~OrthogonalTriangle(); // Destructor[cite: 1]

    // מתודות Get & Set[cite: 1]
    double getSide() const;
    void setSide(double newSide);

    // מתודות ייחודיות
    void draw() const; // מציגה משולש ישר זווית של כוכביות[cite: 1]

    // מימוש מתודות אבסטרקטיות[cite: 1]
    virtual double getPerimeter() const override;
    virtual double getArea() const override;
};

#endif // ORTHOGONALTRIANGLE_H