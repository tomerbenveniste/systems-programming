/****************************************
Assignment C++: 2 Author: Tomer Benveniste, ID: 207961954 / Carmi Frank, ID: 206463846
*****************************************/

#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H

#include <vector>
#include "Product.h"

class ShoppingCart {
protected:
    vector<Product> items;
    double total_price;

public:
    ShoppingCart();
    virtual ~ShoppingCart();

    bool add_Product(const Product &p);
    bool add_Product(const Product &p, int quantity);
    bool remove_Product(const Product &p);
    bool remove_Product(const Product &p, int quantity);
    const vector<Product> &Get_List() const;
    void printcart() const;
    virtual double Get_total() const;

    friend ostream &operator<<(ostream &os, const ShoppingCart &cart);
    Product *operator[](int id);
};

#endif
