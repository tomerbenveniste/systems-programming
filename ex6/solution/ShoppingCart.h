/****************************************
Assignment C++: 2 Author: Tomer Benveniste, ID: 207961954 / Carmi Frank, ID: 206463846
*****************************************/

#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H

#include <vector>
#include "Product.h"

// Holds a list of products and a running total price for a customer's cart
class ShoppingCart {
protected:
    vector<Product> items;  // products currently in the cart
    double total_price;     // sum of (price * quantity) for all items

public:
    // Initialises an empty cart with total_price = 0
    ShoppingCart();

    virtual ~ShoppingCart();

    // Adds all units of p to the cart; total_price += p.price * p.quantity
    bool add_Product(const Product &p);

    // Adds a specific quantity of p to the cart; total_price += p.price * quantity
    bool add_Product(const Product &p, int quantity);

    // Removes product p entirely from the cart and subtracts its cost from total_price
    bool remove_Product(const Product &p);

    // Reduces quantity of p in the cart by the given amount; adjusts total_price
    bool remove_Product(const Product &p, int quantity);

    // Returns a const reference to the items vector
    const vector<Product> &Get_List() const;

    // Prints: "Shopping Cart Details:\n[products]\nTotal Price: X"
    void printcart() const;

    // Returns the current total price
    virtual double Get_total() const;

    // Prints: "Shopping Cart:\n[products]\nTotal Price: X" (used during checkout)
    friend ostream &operator<<(ostream &os, const ShoppingCart &cart);

    // Finds and returns a pointer to the product with the given ID; nullptr if not found
    Product *operator[](int id);
};

#endif
