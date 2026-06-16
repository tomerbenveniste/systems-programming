/****************************************
Assignment C++: 2 Author: Tomer Benveniste, ID: 207961954 / Carmi Frank, ID: 206463846
*****************************************/

#include "Customer.h"

// Default constructor — name left empty, cart initialised by ShoppingCart()
Customer::Customer() {}

// Constructs a customer with the given name; cart is default-initialised (empty)
Customer::Customer(string name) {}

// Destructor — no dynamic memory owned directly
Customer::~Customer() {}

// Delegates to cart.add_Product with the specified quantity
bool Customer::add_to_cart(const Product &p, int quantity) { return false; }

// Finds product by id in cart and removes the given quantity
bool Customer::remove_from_cart(int id, int quantity)      { return false; }

// Empties the cart, prints its contents via operator<<, and returns the total price
// Cart is cleared after printing so the customer starts fresh
double Customer::checkout()   { return 0; }

// Delegates to cart.printcart() which prints "Shopping Cart Details:" + items + total
void Customer::print_cart() const {}

// Returns mutable reference to cart (needed by Supplier::customer_purchases)
ShoppingCart &Customer::get_cart()             { return cart; }

// Returns const reference to cart (for read-only access)
const ShoppingCart &Customer::get_cart() const { return cart; }

// Prints the customer's name and their current cart
ostream &operator<<(ostream &os, const Customer &c) { return os; }

// ---- BusinessCustomer ----

// Initialises the base Customer fields plus company name and discount rate
BusinessCustomer::BusinessCustomer(string name, string company_name, double discount_rate) {}

// Destructor — no extra dynamic memory
BusinessCustomer::~BusinessCustomer() {}

// Checkout with discount: computes total, applies discount_rate, prints, clears cart
// Discounted total = base_total * (1 - discount_rate)
double BusinessCustomer::checkout() { return 0; }

// Prints business customer info: name, company, and discount alongside cart summary
ostream &operator<<(ostream &os, const BusinessCustomer &bc) { return os; }
