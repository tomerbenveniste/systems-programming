/****************************************
Assignment C++: 2 Author: Tomer Benveniste, ID: 207961954 / Carmi Frank, ID: 206463846
*****************************************/

#include "Customer.h"

Customer::Customer() {}
Customer::Customer(string name) {}
Customer::~Customer() {}

bool Customer::add_to_cart(const Product &p, int quantity) { return false; }
bool Customer::remove_from_cart(int id, int quantity)      { return false; }
double Customer::checkout()   { return 0; }
void Customer::print_cart() const {}
ShoppingCart &Customer::get_cart()             { return cart; }
const ShoppingCart &Customer::get_cart() const { return cart; }

ostream &operator<<(ostream &os, const Customer &c) { return os; }

BusinessCustomer::BusinessCustomer(string name, string company_name, double discount_rate) {}
BusinessCustomer::~BusinessCustomer() {}
double BusinessCustomer::checkout() { return 0; }
ostream &operator<<(ostream &os, const BusinessCustomer &bc) { return os; }
