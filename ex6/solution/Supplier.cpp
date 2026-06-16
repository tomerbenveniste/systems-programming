/****************************************
Assignment C++: 2 Author: Tomer Benveniste, ID: 207961954 / Carmi Frank, ID: 206463846
*****************************************/

#include "Supplier.h"
#include "Customer.h"

// Initialises supplier with zero profit and an empty inventory
Supplier::Supplier() {}

// Destructor — vector cleans up automatically
Supplier::~Supplier() {}

// Removes product p entirely from inventory
// Returns false if product is not found
bool Supplier::remove_Product(const Product &p)              { return false; }

// Reduces quantity of p in inventory by the given amount
// Removes entirely if quantity reaches 0
bool Supplier::remove_Product(const Product &p, int quantity){ return false; }

// Processes the customer's full cart:
//   counter += cart total price
//   Decrements inventory quantities for each purchased product
bool Supplier::customer_purchases(Customer &c)               { return false; }

// Overload used when working directly with a ShoppingCart (e.g. after checkout)
//   counter += cart.total_price
bool Supplier::customer_purchases(const ShoppingCart &cart)  { return false; }

// Searches inventory by ID and sets the new price
// Prints "Product not found." if no matching ID; returns false in that case
bool Supplier::change_price(int id, double new_price)        { return false; }

// Returns current value of counter (negative = net loss, positive = net profit)
double Supplier::get_total_profit() const                    { return 0; }

// Returns const reference to the inventory vector (used by Menu to display store items)
const vector<Product> &Supplier::get_inventory() const       { return inventory; }

// Prints all inventory products followed by the total profit
// Format: "Supplier Details:\n[each product]\nTotal Profit: X"
ostream &operator<<(ostream &os, const Supplier &supplier) { return os; }
