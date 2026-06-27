/*Assignment C++: 3
Author: Tomer Benveniste, ID: 207961954  /  Carmi Frank, ID: 206463846
*/
#include <iostream>
#include <stdexcept>
#include "Array.h"
#include "Shape.h"
#include "Square.h"
#include "Circle.h"
#include "OrthogonalTriangle.h"

using namespace std;

int main() {
    // Create an array of Shape pointers
    Array<Shape*> shapesArray;
    int choice = 0;

    while (choice != 4) {
        // Display menu
        cout << "\nMenu:\n";
        cout << "(1) Add a new shape\n"; // Add a new shape
        cout << "(2) Delete a shape by index\n"; // Delete shape by index
        cout << "(3) Print shape details by index\n"; // Print shape details
        cout << "(4) Exit\n"; // Exit program
        cout << "Enter your choice: ";
        cin >> choice;

        try {
            // Exception handling - ensure invalid input throws an appropriate Exception
            
            if (choice == 1) {
                // Add a shape to the end of the array
                // TODO: Request data (shape type, color, width, dimensions) and create a new object
                // Example: shapesArray.Add(newShape);
            } 
            else if (choice == 2) {
                // Delete shape by index
                // TODO: Get index, call shapesArray.remove(index) and free the memory (delete)
            } 
            else if (choice == 3) {
                // Print shape details and use RTTI[cite: 1]
                // TODO: Get index and print area, perimeter, and additional fields.
                // TODO: Use dynamic_cast to check if the shape is a Square or OrthogonalTriangle and call draw()
            }
        } 
        catch (const std::exception& e) {
            // Catch Exceptions (e.g., out of bounds) and print a message without crashing
            cout << "Error: " << e.what() << ". Please try again.\n" << endl;
        }
    }

    // Finish and free memory - delete all Shape pointers from the array upon exit
    return 0;
}