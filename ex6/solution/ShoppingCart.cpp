/****************************************
Assignment C++: 2 Author: Tomer Benveniste, ID: 207961954 / Carmi Frank, ID: 206463846
*****************************************/

#include "ShoppingCart.h"

// Initializes an empty cart — no items, total is 0
ShoppingCart::ShoppingCart() : total_price(0) {}

// Destructor — vector cleans up automatically
ShoppingCart::~ShoppingCart() {}

// Adds the product with its full quantity; if product already in cart, increases its quantity
// total_price += p.price * p.quantity
bool ShoppingCart::add_Product(const Product &p) {
    return add_Product(p, (int)p.get_quantity());
}

// Adds a specific quantity of p; if product already in cart, increases its quantity
// total_price += p.price * quantity
bool ShoppingCart::add_Product(const Product &p, int quantity) {
    // searching for the given product in the shopping cart vector
    Product *existing = (*this)[(int)p.get_id()];
    if (existing == nullptr) {
        // product not in cart — add a copy with the requested quantity
        items.push_back(Product(p, quantity));
    } else {
        // product already in cart — increase its quantity
        *existing += quantity;
    }
    total_price += p.get_price() * quantity;
    return true;
}

// Removes the product entirely from items; total_price -= product cost
// Returns false if product not found in cart
bool ShoppingCart::remove_Product(const Product &p) { return false; }

// Reduces quantity of p by the given amount; removes entirely if quantity reaches 0
// total_price -= p.price * quantity
bool ShoppingCart::remove_Product(const Product &p, int quantity) { return false; }

// Returns a const reference to the internal items list
const vector<Product> &ShoppingCart::Get_List() const { return items; }

// Prints the cart with header "Shopping Cart Details:" followed by each product and total
void ShoppingCart::printcart() const {}

// Returns the running total price of all items in the cart
double ShoppingCart::Get_total() const { return 0; }

// Prints: "Shopping Cart:\n[each product]\nTotal Price: X" — used during checkout
ostream &operator<<(ostream &os, const ShoppingCart &cart) { return os; }

// Searches items by ID; returns pointer to matching Product or nullptr if not found
Product *ShoppingCart::operator[](int id) {
    for (int i =0 ; i < items.size(); i++) {
        if (items[i] == id) {
            return &items[i];
        }
    }
    return nullptr;
}
