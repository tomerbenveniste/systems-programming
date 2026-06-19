/****************************************
Assignment C++: 2 Author: Tomer Benveniste, ID: 207961954 / Carmi Frank, ID: 206463846
*****************************************/

#include "Supplier.h"
#include "Customer.h"

// Initializes supplier with zero profit and an empty inventory
Supplier::Supplier() : counter(0) {}

// Destructor — vector cleans up automatically
Supplier::~Supplier() {}

// Removes product p entirely from inventory
// Returns false if product is not found
bool Supplier::remove_Product(const Product &p) {
    int i = find_index(p.get_id());
    if (i == -1) { return false; } // product does not exist
    // product exist
    return remove_Product(p, inventory[i].get_quantity()); // delegate
}

// Reduces quantity of p in inventory by the given amount
// Removes entirely if quantity reaches 0
bool Supplier::remove_Product(const Product &p, int quantity) {
    int i = find_index(p.get_id());
    if (i == -1) { return false; } // product does not exist
    // product exist
    inventory[i] -= quantity; // reduce quantity
    if (inventory[i].get_quantity() <0) {
        inventory.erase(inventory.begin() + i); // remove if empty
    }
    return true;
}

// Processes the customer's full cart:
//   counter += cart total price
//   Decrements inventory quantities for each purchased product
bool Supplier::customer_purchases(Customer &c) {
    return customer_purchases(c.get_cart());
}

// Overload used when working directly with a ShoppingCart (e.g. before checkout)
bool Supplier::customer_purchases(const ShoppingCart &cart) {
    for (const Product &p : cart.Get_List()) {
        remove_Product(p, (int)p.get_quantity());
    }
    counter += cart.Get_total();
    return true;
}

// Searches inventory by ID and sets the new price
// Prints "Product not found." if no matching ID; returns false in that case
bool Supplier::change_price(int id, double new_price) {
    // looking for product in inventory via ID
    int i = find_index(id);
    // not jound
    if (i == -1) {
        cout << "Product not found." << endl;
        cout << "" << endl;

        return false;
    }
    //found
    inventory[i].set_price(new_price); // updating price
    return true;
}

// Returns current value of counter (negative = net loss, positive = net profit)
double Supplier::get_total_profit() const { return counter; }

// Returns const reference to the inventory vector (used by Menu to display store items)
const vector<Product> &Supplier::get_inventory() const { return inventory; }

// Prints all inventory products followed by the total profit
ostream &operator<<(ostream &os, const Supplier &supplier) {
    os << "Supplier Details:" << endl;
    for (const Product &p : supplier.inventory) {
        os << p << endl;
    }
    os << "Total Profit: " << supplier.counter << endl;
    return os;
}

// Helper to find a Product in the Inventory - if exists return the index in inventory, if not returns -1
int Supplier::find_index(int id) const {
    for (int i = 0; i < (int)inventory.size(); i++) {
        if (inventory[i] == id) {
            return i;
        }
    }
    return -1;
}

// adds full quantity; counter -= price * quantity
bool Supplier::add_Product(const Product &p) {
    return add_Product(p, p.get_quantity()); // delegate
}

// adds specific quantity; counter -= price * quantity
bool Supplier::add_Product(const Product &p, int quantity) {
    // looking for product in inventory via ID
    int i = find_index(p.get_id());
    // if it doesn't exist, we need to insert to the vector
    if (i == -1) {
        inventory.push_back(Product(p, quantity));
    } else {
        inventory[i] += quantity; // exist - increasing quantity
    }
    counter -= p.get_price() * quantity; // decreasing price
    return true;
}

void Supplier:: print_inv() const
{
    for (const Product &p : this->get_inventory())
            {
                cout << p << endl;
            }
}