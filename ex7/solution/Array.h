/*Assignment C++: 3
Author: Tomer Benveniste, ID: 207961954  /  Carmi Frank, ID: 206463846
*/
#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>

template <class T>
class Array {
private:
    int size; // Array size
    T* elements; // Pointer to the first element in the array

public:
    // Constructors and Destructor
    Array(); // Default constructor
    ~Array(); // Destructor to clean up dynamic memory

    // Methods
    void Add(T element); // Adds an element to the end of the array
    T remove(int index); // Removes an element by index and returns the deleted value
    int getSize() const; // Returns the array size

    // Operators
    T& operator[](int index);
    const T& operator[](int index) const;

    // Declaration of the print operator (for templates, usually declared as friend or implemented inline)
    template <class U>
    friend std::ostream& operator<<(std::ostream& os, const Array<U>& arr);
};

#endif // ARRAY_H