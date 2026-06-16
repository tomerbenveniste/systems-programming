/****************************************
Assignment C++: 2 Author: Tomer Benveniste, ID: 207961954 / Carmi Frank, ID: 206463846
*****************************************/

#include "ShoppingCart.h"

ShoppingCart::ShoppingCart() {}

ShoppingCart::~ShoppingCart() {}

bool ShoppingCart::add_Product(const Product &p)              { return false; }
bool ShoppingCart::add_Product(const Product &p, int quantity){ return false; }
bool ShoppingCart::remove_Product(const Product &p)              { return false; }
bool ShoppingCart::remove_Product(const Product &p, int quantity){ return false; }

const vector<Product> &ShoppingCart::Get_List() const { return items; }
void ShoppingCart::printcart() const {}
double ShoppingCart::Get_total() const { return 0; }

ostream &operator<<(ostream &os, const ShoppingCart &cart) { return os; }
Product *ShoppingCart::operator[](int id) { return nullptr; }
