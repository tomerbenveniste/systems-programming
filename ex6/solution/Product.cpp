/****************************************
Assignment C++: 2 Author: Tomer Benveniste, ID: 207961954 / Carmi Frank, ID: 206463846
*****************************************/

#include "Product.h"

// Static counter — shared across all Product instances, starts at 0 (first product gets ID 1)
int Product::next_id = 0;

// Copy constructor — copies all fields including the original ID (no new ID assigned)
Product::Product(const Product &p) : id(p.id), name(p.name), price(p.price), quantity(p.quantity) 
{}

// Copy-with-quantity constructor — same ID as source, but quantity is overridden to q
Product::Product(const Product &p, int q) : id(p.id), name(p.name), price(p.price), quantity(q) {}

// Primary constructor — assigns the next available ID, then increments next_id
Product::Product(string name, double price, int q) : id(++next_id), name(name), price(price), quantity(q) {}

// Destructor — no dynamic memory to free
Product::~Product() {}

// Returns price per unit
double Product::get_price() const 
{ 
    return this->price; 
}

// Returns current quantity
double Product::get_quantity() const { return this->quantity; }

// Returns this product's unique ID
double Product::get_id() const { return this->id; }

// Returns product name
string Product::get_name() const { return this->name; }

// Updates the unit price to new_price
void Product::set_price(double new_price) { this->price = new_price; }

// Prints: "Product ID: X, Name: Y, Price: Z, Quantity: W"
ostream &operator<<(ostream &os, const Product &p) {
    os << "Product ID: " << p.id << ", Name: " << p.name << ", Price: " << p.price << ", Quantity: " << p.quantity;
    return os;
}

// True if both products share the same ID
bool Product::operator==(const Product &other) const { return this->id == other.id; }

// True if this product's ID equals other_id
bool Product::operator==(int other_id) const { return this->id == other_id; }

// True if the products have different IDs (reuse == operator)
bool Product::operator!=(const Product &other) const { return !(*this == other); }

// True if this product's ID differs from other_id (reuse == operator)
bool Product::operator!=(int other_id) const { return !(*this == other_id); }

// Prefix increment — adds 1 to quantity, returns *this
Product &Product::operator++() {
    this->quantity++;
    return *this;
}

// Adds q units to quantity, returns *this
Product &Product::operator+=(unsigned int q) {
    this->quantity += q;
    return *this;
}

// Removes q units from quantity, returns *this
Product &Product::operator-=(unsigned int q) {
    if (this->quantity <= q) {
        this->quantity = 0;
    } else {
        this->quantity -= q;
    }
    return *this;
}