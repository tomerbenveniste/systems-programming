/****************************************
Assignment C++: 2 Author: Tomer Benveniste, ID: 207961954 / Carmi Frank, ID: 206463846
*****************************************/

#include "Supplier.h"
#include "Customer.h"

Supplier::Supplier() {}
Supplier::~Supplier() {}

bool Supplier::remove_Product(const Product &p)              { return false; }
bool Supplier::remove_Product(const Product &p, int quantity){ return false; }
bool Supplier::customer_purchases(Customer &c)               { return false; }
bool Supplier::customer_purchases(const ShoppingCart &cart)  { return false; }
bool Supplier::change_price(int id, double new_price)        { return false; }
double Supplier::get_total_profit() const                    { return 0; }
const vector<Product> &Supplier::get_inventory() const       { return inventory; }

ostream &operator<<(ostream &os, const Supplier &supplier) { return os; }
