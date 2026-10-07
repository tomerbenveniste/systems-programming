/*Assignment C++: 3
Author: Tomer Benveniste, ID: 207961954  /  Carmi Frank, ID: 206463846
*/
#ifndef SHAPE_H
#define SHAPE_H

class Shape {
private:
    char* color; // Dynamic string, possible colors: blue, red, green
    int width; // Shape thickness/width

public:
    // Constructors and Destructor
    Shape(); // Default constructor
    Shape(const char* color, int width); // parameterized Constructor
    virtual ~Shape(); // Virtual default destructor

protected:
    // Copying is protected so derived shapes can be copied, but a Shape& can't be assigned
    // from a different shape type (slicing)
    Shape(const Shape& other); // Copy constructor - deep copies the color string
    Shape& operator=(const Shape& other); // Assignment operator - deep copies the color string

public:
    // Getters & Setters
    const char* getColor() const;
    void setColor(const char* newColor);
    int getWidth() const;
    void setWidth(int newWidth);

    // Abstract methods
    virtual double getPerimeter() const = 0; // Returns perimeter
    virtual double getArea() const = 0; // Returns area
};

#endif // SHAPE_H