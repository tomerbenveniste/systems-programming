/****************************************
Assignment C++: 2 Author: Tomer Benveniste, ID: 207961954 / Carmi Frank, ID: 206463846
*****************************************/

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include "ShoppingCart.h"

// Base class for a store customer — holds a name and a shopping cart
class Customer {
protected:
    string name; // customer's display name
    ShoppingCart cart; // the customer's personal shopping cart

public:
    Customer(); // default constructor (used for polymorphic pointer initialisation)

    // Constructs a customer with the given name
    Customer(string name);

    Customer(string name, ShoppingCart cart);


    virtual ~Customer();

    // Adds the given quantity of product p to the cart
    virtual bool add_to_cart(const Product &p, int quantity);

    // Removes the given quantity of product with matching id from the cart
    virtual bool remove_from_cart(int id, int quantity);

    // Empties the cart, prints its contents, and returns the total price paid
    virtual double checkout();

    // Prints the cart using ShoppingCart::printcart()
    void print_cart() const;

    // Returns a mutable reference to the cart (used by Supplier to process purchases)
    ShoppingCart &get_cart();

    // Returns a const reference to the cart
    const ShoppingCart &get_cart() const;

    // Prints customer name and cart summary
    friend ostream &operator<<(ostream &os, const Customer &c);
};

// Derived customer with a company affiliation and a discount applied at checkout
class BusinessCustomer : public Customer {
private:
    string company_name;   // name of the associated company
    double discount_rate;  // fraction to discount, e.g. 0.1 = 10% off

public:
    // Constructs a business customer with name, company, and discount rate
    BusinessCustomer(string name, string company_name, double discount_rate);

    virtual ~BusinessCustomer();

    // Checkout with discount applied: total *= (1 - discount_rate)
    virtual double checkout() override;

    // Prints business customer info including company and discount rate
    friend ostream &operator<<(ostream &os, const BusinessCustomer &bc);
};

#endif
