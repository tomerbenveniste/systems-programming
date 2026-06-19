/****************************************
Assignment C++: 2 Author: Tomer Benveniste, ID: 207961954 / Carmi Frank, ID: 206463846
*****************************************/

#include "ShoppingCart.h"

// Initializes an empty cart — no items, total is 0
ShoppingCart::ShoppingCart() : total_price(0) {}

// Destructor — vector cleans up automatically
ShoppingCart::~ShoppingCart() {}

// Adds the product with its full quantity; if product already in cart, increases its quantity
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
        if(existing->get_quantity()>= quantity)
        {
            *existing += quantity;
        }
        
    }
    total_price += p.get_price() * quantity;
    return true;
}

// Removes the product entirely from items;
// Returns false if product not found in cart
bool ShoppingCart::remove_Product(const Product &p) {
    // making sure we are pointing at the product that in the cart
    Product *existing = (*this)[(int)p.get_id()];
    if (existing == nullptr)
        return false;
    return remove_Product(p, (int)existing->get_quantity());
}

// Reduces quantity of p by the given amount - removes entirely if quantity reaches 0
bool ShoppingCart::remove_Product(const Product &p, int quantity) {
    // searching for the given product in the shopping cart vector
    Product *existing = (*this)[(int)p.get_id()];
    if (existing == nullptr) {
        // product in not in the cart — nothing to remove
        return false;
    }
    // if the given quantity exceeds the number that in the cart - need to remove the product from the cart
    if ((int)existing->get_quantity() <= quantity) {
        // the max units to decrease is the actual quantity in the cart
        total_price -= p.get_price() * existing->get_quantity();
        // remove the product entirely from the vector
        int index = existing - &items[0];
        items.erase(items.begin() + index);
    } else {
        total_price -= p.get_price() * quantity; // decrease the total price
        *existing -= quantity; // decrease the quantity
    }
    return true;
}

// Returns a const reference to the internal items list
const vector<Product> &ShoppingCart::Get_List() const { return items; }

// Prints the cart products and total price - view cart use
void ShoppingCart::printcart() const {
    // prints the header
    cout << "Shopping Cart:" << endl;
    // loop to print all products in the cart
    for (int i = 0; i < items.size(); i++) {
        cout << items[i] << endl;
    }
    cout << "Total Price: " << total_price ; // print total price of the cart
}

// Returns the running total price of all items in the cart
double ShoppingCart::Get_total() 
{ 
    total_price = 0;
    for (int i = 0; i < this->items.size(); i++) {
        total_price = total_price + this->items[i].get_price() * this->items[i].get_quantity();

    }
    return total_price;

}

// Prints Shopping Cart — used during checkout
ostream &operator<<(ostream &os, const ShoppingCart &cart) {
    // prints the header
    os << "Shopping Cart:" << endl;
    // loop to print all products in the cart
    for (int i = 0; i < cart.items.size(); i++) {
        os << cart.items[i] << endl;
    }
    os << "Total Price: " << cart.total_price ; // print total price of the cart
    return os;
}

// Searches items by ID operator - returns pointer to matching Product or nullptr if not found
Product *ShoppingCart::operator[](int id) {
    for (int i =0 ; i < items.size(); i++) {
        if (items[i] == id) {
            return &items[i];
        }
    }
    return nullptr;
}

bool ShoppingCart::clear_cart() {
    items.clear();
    total_price = 0;
    return true;
}

bool ShoppingCart::checkout() {
    double total = total_price;
    this->clear_cart();
    return total;
}

