/****************************************
 Assignment C++: 2
 Author: Tomer Benveniste, ID: 207961954 / Carmi Farjon, ID: 206463846
*****************************************/

#ifndef SUPPLIER_H
#define SUPPLIER_H

#include <vector>
#include "Product.h"

class Customer;
class ShoppingCart;

class Supplier {
private:
    double counter;
    vector<Product> inventory;

public:
    Supplier();
    ~Supplier();

    bool remove_Product(const Product &p);
    bool remove_Product(const Product &p, int quantity);
    bool customer_purchases(Customer &c);
    bool customer_purchases(const ShoppingCart &cart);
    bool change_price(int id, double new_price);
    double get_total_profit() const;
    const vector<Product> &get_inventory() const;

    friend ostream &operator<<(ostream &os, const Supplier &supplier);
};

#endif
