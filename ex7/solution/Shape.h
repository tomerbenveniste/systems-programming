/*Assignment C++: 3
Author: Israel Israeli, ID: 01234567
*/
#ifndef SHAPE_H
#define SHAPE_H

class Shape {
private:
    char* color; // Dynamic string, possible colors: blue, red, green[cite: 1]
    int width; // Shape thickness/width[cite: 1]

public:
    // Constructors and Destructor
    Shape(); // Default constructor[cite: 1]
    Shape(const char* color, int width); // Constructor with all parameters[cite: 1]
    virtual ~Shape(); // Virtual default destructor[cite: 1]

    // Getters & Setters[cite: 1]
    const char* getColor() const;
    void setColor(const char* newColor);
    int getWidth() const;
    void setWidth(int newWidth);

    // Abstract methods[cite: 1]
    virtual double getPerimeter() const = 0; // Returns perimeter[cite: 1]
    virtual double getArea() const = 0; // Returns area[cite: 1]
};

#endif // SHAPE_H