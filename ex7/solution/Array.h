/*Assignment C++: 3
Author: Israel Israeli, ID: 01234567
*/
#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>

template <class T>
class Array {
private:
    int size; // Array size[cite: 1]
    T* elements; // Pointer to the first element in the array[cite: 1]

public:
    // Constructors and Destructor
    Array(); // Default constructor[cite: 1]
    ~Array(); // Destructor to clean up dynamic memory[cite: 1]

    // Methods
    void Add(T element); // Adds an element to the end of the array[cite: 1]
    T remove(int index); // Removes an element by index and returns the deleted value[cite: 1]
    int getSize() const; // Returns the array size[cite: 1]

    // Operators[cite: 1]
    T& operator[](int index);
    const T& operator[](int index) const;

    // Declaration of the print operator (for templates, usually declared as friend or implemented inline)[cite: 1]
    template <class U>
    friend std::ostream& operator<<(std::ostream& os, const Array<U>& arr);
};

#endif // ARRAY_H