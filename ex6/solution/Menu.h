/****************************************
Assignment C++: 2 Author: Tomer Benveniste, ID: 207961954 / Carmi Frank, ID: 206463846
*****************************************/

#ifndef MENU_H
#define MENU_H

#include "Supplier.h"
#include "Customer.h"

class Menu {
private:
    Supplier supplier;
    Customer *customer;

public:
    Menu();
    ~Menu();

    void mainMenu();
    void supplierMenu();
    void buyerMenu();
};

#endif
