/****************************************
Assignment C++: 2 Author: Tomer Benveniste, ID: 207961954 / Carmi Frank, ID: 206463846
*****************************************/

#include "Menu.h"
#include <iostream>
using namespace std;

// Initialises the menu: supplier is default-constructed, customer starts as nullptr
Menu::Menu() {}

// Frees the dynamically allocated customer object if one was created
Menu::~Menu() {}

// Loops until the user chooses to exit:
//   1 -> supplierMenu()
//   2 -> ask regular (1) or business (2), collect name/company/discount, create Customer*, call buyerMenu()
//   3 -> print "Goodbye!" and return
// Invalid input -> "Invalid option. Please try again."
void Menu::mainMenu() {}

// Loops until the user chooses to go back:
//   1 -> cout << supplier  (shows inventory + total profit)
//   2 -> list inventory, ask ID; if found: ask qty to restock; if not found: ask name/price/qty, create new Product
//   3 -> list inventory with prices, ask ID; if found: print it, ask new price, update; else "Product not found."
//   4 -> list inventory, ask ID; if found: remove from inventory; else "Product not found."
//   5 -> print "Total profit: X"
//   6 -> print "Exiting supplier menu." and return
// Invalid input -> "Invalid option. Please try again."
void Menu::supplierMenu() {}

// Loops until the user chooses to go back:
//   1 -> print "Items in the store:\n" then cout << supplier
//   2 -> show store, ask ID and quantity; cap at available stock if over; add to customer cart
//   3 -> show cart via printcart(), ask ID, remove from cart
//   4 -> print "Items in the cart:\n" then customer->print_cart()
//   5 -> print total, ask "Would you like to check out? (y/n)":
//          y -> customer->checkout(), then supplier.customer_purchases(*customer)
//          n -> return to loop unchanged
//   6 -> print "Exiting shopping cart menu." and return
// Invalid input -> "Invalid option. Please try again."
void Menu::buyerMenu() {}
