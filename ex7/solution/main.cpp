/*Assignment C++: 3
Author: Tomer Benveniste, ID: 207961954  /  Carmi Frank, ID: 206463846
*/
#include <iostream>
#include <cstring>
#include <stdexcept>
#include "Array.h"
#include "Shape.h"
#include "Square.h"
#include "Circle.h"
#include "OrthogonalTriangle.h"
using namespace std;

// Returns true if the given color string is one of the three allowed colors
bool isValidColor(const char* color)
{
    return strcmp(color, "red") == 0 ||
           strcmp(color, "green") == 0 ||
           strcmp(color, "blue") == 0;
}

// Prompts the user for a color until a valid one is entered.
// Returns a heap-allocated copy - caller is responsible for delete[].
char* readColor()
{
    char buffer[100];

    while (true)
    {
        try
        {
            cout << "Enter shape color (red/green/blue): ";
            cin >> buffer;

            if (!isValidColor(buffer))
                throw invalid_argument("Invalid color. Please enter red, green, or blue.");

            // Allocate and return a copy so the caller owns the string
            char* color = new char[strlen(buffer) + 1];
            strcpy(color, buffer);
            return color;
        }
        catch (const exception& e)
        {
            cout << e.what() << endl;
            // Loop continues - re-prompt the user
        }
    }
}

// Prompts the user with 'message' until a valid positive integer is entered.
// Clears cin on non-integer input so the stream does not stay in a fail state.
int readPositiveInt(const char* message)
{
    int value;

    while (true)
    {
        try
        {
            cout << message;
            if (!(cin >> value))
            {
                cin.clear();
                cin.ignore(10000, '\n');
                throw invalid_argument("Invalid input. Please enter a positive integer.");
            }

            if (value <= 0)
                throw invalid_argument("Value must be positive.");

            return value;
        }
        catch (const exception& e)
        {
            cout << e.what() << endl;
        }
    }
}

// Prompts the user with 'message' until a valid positive double is entered.
// Clears cin on non-numeric input so the stream does not stay in a fail state.
double readPositiveDouble(const char* message)
{
    double value;

    while (true)
    {
        try
        {
            cout << message;
            if (!(cin >> value))
            {
                cin.clear();
                cin.ignore(10000, '\n');
                throw invalid_argument("Invalid input. Please enter a positive number.");
            }

            if (value <= 0)
                throw invalid_argument("Value must be positive.");

            return value;
        }
        catch (const exception& e)
        {
            cout << e.what() << endl;
        }
    }
}

// Prompts the user for an index and validates it is within [0, size).
// Re-prompts on bad input or out-of-range values.
int readIndex(int size)
{
    int index;
    
    while (true)
    {
        try
        {
            cout << "Enter index: ";
            if (!(cin >> index))
            {
                cin.clear();
                cin.ignore(10000, '\n');
                throw invalid_argument("Invalid input. Please enter an integer index.");
            }

            if (index < 0 || index >= size)
                throw out_of_range("Invalid index.");

            return index;
        }
        catch (const exception& e)
        {
            cout << e.what() << endl;
        }
    }
}

// Prints the details of a shape using RTTI (dynamic_cast) to identify the concrete type.
// Square and OrthogonalTriangle also call draw(); Circle has no draw method.
void printShapeDetails(Shape* shape)
{
    // Use dynamic_cast to determine the runtime type of the shape
    Square* square = dynamic_cast<Square*>(shape);
    Circle* circle = dynamic_cast<Circle*>(shape);
    OrthogonalTriangle* triangle = dynamic_cast<OrthogonalTriangle*>(shape);

    if (square != NULL)
    {
        cout << "Square details:" << endl;
        cout << "color=" << square->getColor()
             << ", width=" << square->getWidth()
             << ", side=" << square->getSide()
             << ", area=" << square->getArea()
             << ", perimeter=" << square->getPerimeter()
             << endl;

        // Draw the square as a grid of asterisks
        square->draw();
    }
    else if (circle != NULL)
    {
        cout << "Circle details:" << endl;
        cout << "color=" << circle->getColor()
             << ", width=" << circle->getWidth()
             << ", radius=" << circle->getRadius()
             << ", area=" << circle->getArea()
             << ", perimeter=" << circle->getPerimeter()
             << endl;
        // Circle has no draw() method
    }
    else if (triangle != NULL)
    {
        cout << "OrthogonalTriangle details:" << endl;
        cout << "color=" << triangle->getColor()
             << ", width=" << triangle->getWidth()
             << ", side=" << triangle->getSide()
             << ", area=" << triangle->getArea()
             << ", perimeter=" << triangle->getPerimeter()
             << endl;

        // Draw the triangle as a staircase of asterisks
        triangle->draw();
    }
}

int main()
{
    Array<Shape*> shapes; // Dynamic array that holds pointers to Shape objects
    int choice = 0;

    do
    {
        // Display the menu options
        cout << endl;
        cout << "Menu:" << endl;
        cout << "1. Add shape" << endl;
        cout << "2. Remove shape by index" << endl;
        cout << "3. Print shape by index" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";

        // Read menu choice - if input is not an integer, force an invalid choice
        if (!(cin >> choice))
        {
            cin.clear();
            cin.ignore(10000, '\n');
            choice = -1;
        }

        try
        {
            if (choice == 1)
            {
                // Ask which shape type to create
                int type;
                cout << "Choose 1 for Square, 2 for Circle, 3 for Triangle: ";
                cin >> type;

                if (type < 1 || type > 3)
                    throw invalid_argument("Invalid shape type.");

                // Read common shape fields shared by all types
                char* color = readColor();
                int width = readPositiveInt("Enter shape width: ");

                // Create the specific shape and add it to the array
                if (type == 1)
                {
                    double side = readPositiveDouble("Enter Square's side: ");
                    shapes.Add(new Square(color, width, side));
                }
                else if (type == 2)
                {
                    int radius = readPositiveInt("Enter Circle's radius: ");
                    shapes.Add(new Circle(color, width, radius));
                }
                else
                {
                    double side = readPositiveDouble("Enter Triangle's side: ");
                    shapes.Add(new OrthogonalTriangle(color, width, side));
                }

                // Shape constructor copied the color string, so free the local buffer
                delete[] color;
            }
            else if (choice == 2)
            {
                if (shapes.getSize() == 0)
                    throw out_of_range("Array is empty.");

                int index = readIndex(shapes.getSize());

                // remove() returns the pointer - we must delete it to free the heap object
                Shape* removedShape = shapes.remove(index);
                delete removedShape;

                cout << "Shape removed successfully." << endl;
            }
            else if (choice == 3)
            {
                if (shapes.getSize() == 0)
                    throw out_of_range("Array is empty.");

                int index = readIndex(shapes.getSize());
                printShapeDetails(shapes[index]);
            }
            else if (choice == 4)
            {
                cout << "Exiting program." << endl;
            }
            else
            {
                throw invalid_argument("Invalid menu choice.");
            }
        }
        catch (const exception& e)
        {
            // Catch all errors (invalid input, out-of-range, etc.) and keep the program running
            cout << e.what() << endl;
        }

    } while (choice != 4);

    // Free all remaining Shape objects before the program exits
    while (shapes.getSize() > 0)
    {
        Shape* shape = shapes.remove(0);
        delete shape;
    }

    return 0;
}
