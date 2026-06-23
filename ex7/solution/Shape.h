/*Assignment C++: 3
Author: Tomer Benveniste, ID: 207961954 / Carmi Friedman, ID: 206463846
*/
#ifndef SHAPE_H
#define SHAPE_H

class Shape {
private:
    char* color; // מחרוזת דינמית, צבעים אפשריים: blue, red, green[cite: 1]
    int width; // עובי צורה[cite: 1]

public:
    // בנאים והורסים
    Shape(); // בנאי דיפולטיבי[cite: 1]
    Shape(const char* color, int width); // בנאי המקבל את כל הפרמטרים[cite: 1]
    virtual ~Shape(); // Destructor דיפולטיבי וירטואלי[cite: 1]

    // מתודות Get & Set[cite: 1]
    const char* getColor() const;
    void setColor(const char* newColor);
    int getWidth() const;
    void setWidth(int newWidth);

    // מתודות אבסטרקטיות[cite: 1]
    virtual double getPerimeter() const = 0; // מחזירה היקף[cite: 1]
    virtual double getArea() const = 0; // מחזירה שטח[cite: 1]
};

#endif // SHAPE_H