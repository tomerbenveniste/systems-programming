/****************************************
Assignment C++: 2 Author: Tomer Benveniste, ID: 207961954 / Carmi Frank, ID: 206463846
*****************************************/

#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
#include <iostream>
using namespace std;

class Product {
private:
    static int next_id;
    int id;
    string name;
    double price;
    unsigned int quantity;

public:
    Product(const Product &p);
    Product(const Product &p, int q);
    Product(string name, double price, int q = 1);
    ~Product();

    double get_price() const;
    double get_quantity() const;
    double get_id() const;
    string get_name() const;
    void set_price(double new_price);

    friend ostream &operator<<(ostream &os, const Product &p);
    bool operator==(const Product &other) const;
    bool operator==(int other_id) const;
    bool operator!=(const Product &other) const;
    bool operator!=(int other_id) const;
    Product &operator++();
    Product &operator+=(unsigned int q);
    Product &operator-=(unsigned int q);
};

#endif
