/****************************************
Assignment C++: 2 Author: Tomer Benveniste, ID: 207961954 / Carmi Frank, ID: 206463846
*****************************************/

#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
#include <iostream>
using namespace std;

// Represents a single product with an auto-assigned ID, name, price, and quantity
class Product {
private:
    static int next_id; // shared counter - incremented each time a brand-new product is created
    int id; // unique identifier assigned from next_id at construction
    string name; // product name
    double price; // price per unit
    unsigned int quantity; // number of units available

public:
    // Copy constructor - preserves the original product's ID
    Product(const Product &p);

    // Copy constructor with quantity override - same ID as source, but different quantity
    Product(const Product &p, int q);

    // Primary constructor - assigns the next available ID and initializes fields
    Product(string name, double price, int q = 1);

    ~Product();

    // Accessors
    double get_price() const; // returns price per unit
    double get_quantity() const; // returns current quantity
    double get_id() const; // returns unique product ID
    string get_name() const; // returns product name
    void set_price(double new_price); // updates the unit price

    // Prints: "Product ID: X, Name: Y, Price: Z, Quantity: W"
    friend ostream &operator<<(ostream &os, const Product &p);

    // Equality - compares by ID
    bool operator==(const Product &other) const;
    bool operator==(int other_id) const;

    // Inequality - compares by ID
    bool operator!=(const Product &other) const;
    bool operator!=(int other_id) const;

    // Prefix increment - increases quantity by 1
    Product &operator++();

    // Adds q units to quantity
    Product &operator+=(unsigned int q);

    // Removes q units from quantity
    Product &operator-=(unsigned int q);
};

#endif
