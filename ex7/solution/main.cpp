/*Assignment C++: 3
Author: Israel Israeli, ID: 01234567
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
    // Create an array of Shape pointers[cite: 1]
    Array<Shape*> shapesArray;
    int choice = 0;

    while (choice != 4) {
        // Display menu[cite: 1]
        cout << "\nMenu:\n";
        cout << "(1) Add a new shape\n"; // Add a new shape[cite: 1]
        cout << "(2) Delete a shape by index\n"; // Delete shape by index[cite: 1]
        cout << "(3) Print shape details by index\n"; // Print shape details[cite: 1]
        cout << "(4) Exit\n"; // Exit program[cite: 1]
        cout << "Enter your choice: ";
        cin >> choice;

        try {
            // Exception handling - ensure invalid input throws an appropriate Exception[cite: 1]
            
            if (choice == 1) {
                // Add a shape to the end of the array[cite: 1]
                // TODO: Request data (shape type, color, width, dimensions) and create a new object[cite: 1]
                // Example: shapesArray.Add(newShape);
            } 
            else if (choice == 2) {
                // Delete shape by index[cite: 1]
                // TODO: Get index, call shapesArray.remove(index) and free the memory (delete)[cite: 1]
            } 
            else if (choice == 3) {
                // Print shape details and use RTTI[cite: 1]
                // TODO: Get index and print area, perimeter, and additional fields.[cite: 1]
                // TODO: Use dynamic_cast to check if the shape is a Square or OrthogonalTriangle and call draw()[cite: 1]
            }
        } 
        catch (const std::exception& e) {
            // Catch Exceptions (e.g., out of bounds) and print a message without crashing[cite: 1]
            cout << "Error: " << e.what() << ". Please try again.\n" << endl;
        }
    }

    // Finish and free memory - delete all Shape pointers from the array upon exit[cite: 1]
    return 0;
}