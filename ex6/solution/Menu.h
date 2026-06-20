/****************************************
Assignment C++: 2 Author: Tomer Benveniste, ID: 207961954 / Carmi Frank, ID: 206463846
*****************************************/

#ifndef MENU_H
#define MENU_H

#include "Supplier.h"
#include "Customer.h"

// Top-level controller - owns the supplier and a polymorphic customer pointer
class Menu {
private:
    Supplier supplier;   // the store's single supplier (persists for the whole session)
    Customer *customer;  // pointer - set when buyer menu is entered, nullptr otherwise

public:
    // Initialises supplier and sets customer pointer to nullptr
    Menu();

    // Destructor - deletes customer if one was allocated
    ~Menu();

    // Main loop: option 1 = supplier menu, 2 = buyer menu, 3 = exit ("Goodbye!")
    void mainMenu();

    // Supplier loop: 1=print store, 2=add/restock, 3=change price, 4=remove, 5=profit, 6=back
    void supplierMenu();

    // Buyer loop: 1=print store, 2=add to cart, 3=remove from cart, 4=view cart, 5=checkout, 6=back
    // Creates a Customer or BusinessCustomer on entry (persists across re-entries)
    void buyerMenu();
};

#endif
