/****************************************
 Assignment C++: 2
 Author: Tomer Benveniste, ID: 207961954 / Carmi Farjon, ID: 206463846
*****************************************/

#ifndef SUPPLIER_H
#define SUPPLIER_H

#include <vector>
#include "Product.h"

// Forward declarations to avoid circular includes
class Customer;
class ShoppingCart;

// Manages the store's inventory and tracks total profit
// counter starts negative (cost of stocking inventory) and rises with each sale
class Supplier {
private:
    double counter; // running profit: decreases when adding inventory, increases on sale
    vector<Product> inventory; // all products currently stocked in the store
    int find_index(int id) const; // returns index in inventory, -1 if not found

public:

    
    // Initializes with counter = 0 and an empty inventory
    Supplier();
    // Dtor
    ~Supplier();

    // Removes product p entirely from inventory
    bool remove_Product(const Product &p);

    // Removes a specific quantity of p from inventory
    bool remove_Product(const Product &p, int quantity);

    // Processes a customer's cart checkout: adds cart total to counter
    // Also decrements inventory quantities for each purchased item
    bool customer_purchases(Customer &c);

    // Overload: processes a cart directly (used when Customer object is not available)
    bool customer_purchases(const ShoppingCart &cart);

    // Finds product by ID and updates its price; prints error if not found
    bool change_price(int id, double new_price);

    // Returns the current value of counter (total profit so far)
    double get_total_profit() const;

    // Provides read access to the inventory vector
    const vector<Product> &get_inventory() const;

    // Prints all inventory products and the total profit
    // Format: "Supplier Details:\n[products]\nTotal Profit: X"
    friend ostream &operator<<(ostream &os, const Supplier &supplier);

    // adds full quantity; counter -= price * quantity
    bool add_Product(const Product &p);

    // adds specific quantity; counter -= price * quantity
    bool add_Product(const Product &p, int quantity);\

    void print_inv() const;
};

#endif
