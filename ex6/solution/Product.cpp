/****************************************
Assignment C++: 2 Author: Tomer Benveniste, ID: 207961954 / Carmi Frank, ID: 206463846
*****************************************/

#include "Product.h"

int Product::next_id = 1;

Product::Product(const Product &p) {}

Product::Product(const Product &p, int q) {}

Product::Product(string name, double price, int q) {}

Product::~Product() {}

double Product::get_price() const    { return 0; }
double Product::get_quantity() const { return 0; }
double Product::get_id() const       { return 0; }
string Product::get_name() const     { return ""; }
void   Product::set_price(double new_price) {}

ostream &operator<<(ostream &os, const Product &p) { return os; }

bool Product::operator==(const Product &other) const { return false; }
bool Product::operator==(int other_id) const         { return false; }
bool Product::operator!=(const Product &other) const { return false; }
bool Product::operator!=(int other_id) const         { return false; }

Product &Product::operator++()              { return *this; }
Product &Product::operator+=(unsigned int q){ return *this; }
Product &Product::operator-=(unsigned int q){ return *this; }
