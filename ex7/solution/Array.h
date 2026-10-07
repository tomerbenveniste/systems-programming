/*Assignment C++: 3
Author: Tomer Benveniste, ID: 207961954  /  Carmi Frank, ID: 206463846
*/
#ifndef ARRAY_H
#define ARRAY_H
#include <stdexcept> // for dealing with exceptions
#include <iostream>
#include <utility> // for std::swap

template <class T>
class Array {
private:
    int size; // Array size
    T* elements; // Pointer to the first element in the array

public:
    Array(); // Default constructor
    Array(const Array& other); // Copy constructor - deep copies other's elements into a new block
    Array& operator=(Array other); // Assignment operator - copy-and-swap, safe for self-assignment
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

// -------------------------------------- Implementation of Template Class ---------------------------------------------

// default Constructor
template <typename T>
Array<T>::Array() : size(0), elements(nullptr) {
}

// Copy Constructor - allocates its own block so the two arrays never share (and double-delete) memory
template <typename T>
Array<T>::Array(const Array& other) : size(other.size), elements(nullptr) {
    if (other.size > 0) {
        this->elements = new T[other.size];
        for (int i = 0; i < other.size; i++) {
            this->elements[i] = other.elements[i];
        }
    }
}

// Assignment operator - 'other' arrives as a copy (by value), so we swap our contents with it
// and its destructor frees our old block
template <typename T>
Array<T>& Array<T>::operator=(Array other) {
    std::swap(this->size, other.size);
    std::swap(this->elements, other.elements);
    return *this;
}

// Destructor
template <typename T>
Array<T>::~Array() {
    delete[] elements;
}

// gets the array size
template <typename T>
int Array<T>::getSize() const {
    return this->size;
}

// [] operator for a by-value call (allows writing to array)
template <typename T>
T& Array<T>::operator[](int index) {
    // input validation
    if (index < 0 || index >= this->size) {
        throw std::out_of_range("Out of range");
    }
    // input is valid
    return this->elements[index];
}

// override [] operator for a reference call (read-only)
template <typename T>
const T& Array<T>::operator[](int index) const {
    if (index < 0 || index >= this->size) {
        throw std::out_of_range("Out of range");
    }
    return this->elements[index];
}

// add element to array
template <typename T>
void Array<T>::Add(T element) {
    T* newArray = new T[this->size + 1]; // allocating new memory for new elements array
    // copying all elements to the new array
    for (int i = 0; i < this->size; i++) {
        newArray[i] = this->elements[i];
    }
    // all prior elements copied, only left to insert the additional one
    newArray[this->size] = element; // adding the element at the end of the array
    delete[] this->elements; // freeing the old elements array
    this->elements = newArray; // updating the array to point the new one
    this->size++; // updating size by 1 more
}

// remove element from array
template <typename T>
T Array<T>::remove(int index) {
    // input validation
    if (index < 0 || index >= this->size) {
        throw std::out_of_range("Out of range");
    }
    // input is valid
    T* newArray = new T[this->size - 1]; // allocating new memory for new elements array
    T removed_element = this->elements[index]; // saving the removed element for later return
    // copying all elements to the new array except the given one from the index
    for (int i = 0, j = 0; i < this->size; i++) {
        if (i != index) {
            newArray[j] = this->elements[i];
            j++; // moving back index i for proper insertion to array
        }
    }
    // all relevant elements copied
    delete[] this->elements; // freeing the old elements array
    this->elements = newArray; // updating the array to point the new one
    this->size--; // updating size by 1 less
    return removed_element;
}

// << operator
template <typename U>
std::ostream& operator<<(std::ostream& os, const Array<U>& arr) {
    // chaining all elements to printout
    for (int i = 0; i < arr.getSize(); i++) {
        os << arr[i];
    }
    return os;
}

#endif // ARRAY_H