/****************************************
Assignment C++: 2 Author: Tomer Benveniste, ID: 207961954 / Carmi Frank, ID: 206463846
*****************************************/

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include "ShoppingCart.h"

class Customer {
protected:
    string name;
    ShoppingCart cart;

public:
    Customer();
    Customer(string name);
    virtual ~Customer();

    virtual bool add_to_cart(const Product &p, int quantity);
    virtual bool remove_from_cart(int id, int quantity);
    virtual double checkout();
    void print_cart() const;
    ShoppingCart &get_cart();
    const ShoppingCart &get_cart() const;

    friend ostream &operator<<(ostream &os, const Customer &c);
};

class BusinessCustomer : public Customer {
private:
    string company_name;
    double discount_rate;

public:
    BusinessCustomer(string name, string company_name, double discount_rate);
    virtual ~BusinessCustomer();

    virtual double checkout() override;

    friend ostream &operator<<(ostream &os, const BusinessCustomer &bc);
};

#endif
