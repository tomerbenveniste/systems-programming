/****************************************
Assignment C++: 2 Author: Tomer Benveniste, ID: 207961954 / Carmi Frank, ID: 206463846
*****************************************/

#include "Product.h"

// Static counter — shared across all Product instances, starts at 1
int Product::next_id = 1;

// Copy constructor — copies all fields including the original ID (no new ID assigned)
Product::Product(const Product &p) {}

// Copy-with-quantity constructor — same ID as source, but quantity is overridden to q
Product::Product(const Product &p, int q) {}

// Primary constructor — assigns the next available ID, then increments next_id
Product::Product(string name, double price, int q) {}

// Destructor — no dynamic memory to free
Product::~Product() {}

// Returns price per unit
double Product::get_price() const    { return 0; }

// Returns current quantity
double Product::get_quantity() const { return 0; }

// Returns this product's unique ID
double Product::get_id() const       { return 0; }

// Returns product name
string Product::get_name() const     { return ""; }

// Updates the unit price to new_price
void   Product::set_price(double new_price) {}

// Prints: "Product ID: X, Name: Y, Price: Z, Quantity: W"
ostream &operator<<(ostream &os, const Product &p) { return os; }

// True if both products share the same ID
bool Product::operator==(const Product &other) const { return false; }

// True if this product's ID equals other_id
bool Product::operator==(int other_id) const         { return false; }

// True if the products have different IDs
bool Product::operator!=(const Product &other) const { return false; }

// True if this product's ID differs from other_id
bool Product::operator!=(int other_id) const         { return false; }

// Prefix increment — adds 1 to quantity, returns *this
Product &Product::operator++()              { return *this; }

// Adds q units to quantity, returns *this
Product &Product::operator+=(unsigned int q){ return *this; }

// Removes q units from quantity, returns *this
Product &Product::operator-=(unsigned int q){ return *this; }
