/****************************************
Assignment C++: 2 Author: Tomer Benveniste, ID: 207961954 / Carmi Frank, ID: 206463846
*****************************************/

#include "Customer.h"

// Default constructor — name left empty, cart initialised by ShoppingCart()
Customer::Customer()
{
    this->name = "";
    ShoppingCart cart;
    this->cart = cart;
}

// Constructs a customer with the given name; cart is default-initialised (empty)
Customer::Customer(string name) 
{
    this->name = name;
    ShoppingCart cart;
    this->cart = cart;
}

// Constructs a customer with the given name and shopping cart
Customer::Customer(string name, ShoppingCart cart) 
{
    this->name = name;
    this->cart = cart;
}

// Destructor — no dynamic memory owned directly
Customer::~Customer() 
{
    this->name = "";
    this->cart.clear_cart();
}

// Delegates to cart.add_Product with the specified quantity
bool Customer::add_to_cart(const Product &p, int quantity) 
{ 
    this->cart.add_Product(p, quantity);
    return true; 
}

// Finds product by id in cart and removes the given quantity
bool Customer::remove_from_cart(int id, int quantity)      
{ 
    Product *existing = this->cart[id];
    if (existing == nullptr) {
        return false;
    }
    return this->cart.remove_Product(*existing, quantity);
}

// Empties the cart, prints its contents via operator<<, and returns the total price
// Cart is cleared after printing so the customer starts fresh
double Customer::checkout() 
{
    double total = this->cart.Get_total();
    cout << "Total price: " << total << endl;
    cout << this->cart;
    this->cart.clear_cart();
    return total; 
}


// Delegates to cart.printcart() which prints "Shopping Cart Details:" + items + total
void Customer::print_cart() const 
{
    this->cart.printcart();
}

// Returns mutable reference to cart (needed by Supplier::customer_purchases)
ShoppingCart &Customer::get_cart()             
{ 
    return this->cart; 
}

// Returns const reference to cart (for read-only access)
const ShoppingCart &Customer::get_cart() const 
{
    return this->cart; 
    
}

// Prints the customer's name and their current cart
ostream &operator<<(ostream &os, const Customer &c) 
{ 
    os << "Customer Name: " << c.name << endl;
    os << "Cart:" << endl;
    os << c.cart << endl; 
    return os; 
}

// ---- BusinessCustomer ----

// Initialises the base Customer fields plus company name and discount rate
BusinessCustomer::BusinessCustomer(string name, string company_name, double discount_rate) : Customer(name)
{
    this->company_name = company_name;
    this->discount_rate = discount_rate;
}

// Destructor — no extra dynamic memory
BusinessCustomer::~BusinessCustomer() 
{
}

// Checkout with discount: computes total, prints cart contents, clears cart
double BusinessCustomer::checkout() 
{
    double total = this->cart.Get_total();
    double discounted_total = total * (1.0 - discount_rate);
    cout << "Total price: " << discounted_total << endl;
    cout << this->cart;
    this->cart.clear_cart();
    return discounted_total;
}

// Prints business customer info: name, company, and discount alongside cart summary
ostream &operator<<(ostream &os, const BusinessCustomer &bc) 
{ 
    os << "BusinessCustomer:" << endl;
    os << static_cast<const Customer&>(bc);
    os << "company:" << bc.company_name << endl;
    os << "discount" << bc.discount_rate << endl;
    return os; 
}