/****************************************
Assignment C++: 2 Author: Tomer Benveniste, ID: 207961954 / Carmi Frank, ID: 206463846
*****************************************/

#include "Menu.h"
#include <iostream>
using namespace std;

// Initialises the menu: supplier is default-constructed, customer starts as nullptr
Menu::Menu(): supplier(),customer(nullptr)
{
}
// Frees the dynamically allocated customer object if one was created
Menu::~Menu()
{
    delete customer;
}

// Loops until the user chooses to exit:
//   1 -> supplierMenu()
//   2 -> ask regular (1) or business (2), collect name/company/discount, create Customer*, call buyerMenu()
//   3 -> print "Goodbye!" and return
// Invalid input -> "Invalid option. Please try again."
void Menu::mainMenu() 
{
    while (true) {
        cout << "Main Menu:" << endl;
        cout << "1. Store Menu" << endl;
        cout << "2. Shopping Cart Menu" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: " ;

        int user_input;
        cin >> user_input;

        if (user_input == 1) {
            this->supplierMenu();
        }
        else if (user_input == 2) {
            
            this->buyerMenu();
        }
        else if (user_input == 3) {
            cout << "Goodbye!" << endl;
            return;
        }
        else {
            cout << "Invalid selection." << endl;
        }
    }
}

// Loops until the user chooses to go back:
//   1 -> cout << supplier  (shows inventory + total profit)
//   2 -> list inventory, ask ID; if found: ask qty to restock; if not found: ask name/price/qty, create new Product
//   3 -> list inventory with prices, ask ID; if found: print it, ask new price, update; else "Product not found."
//   4 -> list inventory, ask ID; if found: remove from inventory; else "Product not found."
//   5 -> print "Total profit: X"
//   6 -> print "Exiting supplier menu." and return
// Invalid input -> "Invalid option. Please try again."
void Menu::supplierMenu() 
{
    int user_input;

    while(user_input != 6)
    {
        cout << "Store Menu:" << endl;
        cout << "1. Print store" << endl;
        cout << "2. Add quantity to existing product or add new product" << endl;
        cout << "3. Change existing product price" << endl;
        cout << "4. Remove product from the store" << endl;
        cout << "5. View total profit" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: " ;

        cin >> user_input;
        cout << "" <<endl;
        if(user_input == 1)
        {
            this->supplier.print_inv();
        }
        else if(user_input == 2)
        {
            string name;
            double price;
            int q;
            cout << "Add prodact" <<endl;
            cout << "Add name" <<endl;
            cin >> name; 

            cout << "Add price" <<endl;
            cin >> price;

            cout << "Add quantity" <<endl;
            cin >> q;
            Product p(name, price);
            this->supplier.add_Product(p, q);
        }
        else if(user_input == 3)
        {   
            int id;
            double price;
            this->supplier.print_inv();
            cout << "Add id to change price" <<endl;
            cin >> id;
            cout << "Type the new price" <<endl;
            cin >> price;
            this->supplier.change_price(id,price);

        }
        else if(user_input == 4)
        {
            int id;
            double price;
            this->supplier.print_inv();
            cout << "Type id to remove "<<endl;
            cin >> id;
            vector inv = supplier.get_inventory();
            Product p = inv[id -1];
            this->supplier.remove_Product(p);
        }
        else if(user_input == 5)
        {
          cout << "Total profits" << endl;
          cout << this->supplier.get_total_profit() << endl;   
        }


    }
}

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
void Menu::buyerMenu() 
{
    string name, company;
    double discount = 0.0;
    int type, id, q;
    int user_input;

  

    cout << "Enter customer type (1 for regular, 2 for business): ";
    cin >> type;

    if (type == 1) {
        cout << "Enter customer name: ";
        cin >> name;
        customer = new Customer(name);
    }
    else if (type == 2) {
        cout << "Enter business name: ";
        cin >> company;
        cout << "Enter discount percentage: ";
        cin >> discount;
        customer = new BusinessCustomer(name, company, discount);
    }
   
    while(user_input != 6)
    {
        cout << "Buyer Menu" << endl;
        cout << "(1) Avilable prodacts" << endl;
        cout << "(2) Add prodact" << endl;
        cout << "(3) Remove prodact" << endl;
        cout << "(4) Print cart" << endl;
        cout << "(5) Buy all prodacts in cart" << endl;
        cout << "(6) Return to main menu" << endl;
        cout << "Enter your choice: " ;


        
        cin >> user_input;
        cout << "" << endl;

        if(user_input == 1)
        {
            this->supplier.print_inv();
        }
        else if(user_input == 2)
        {
            this->supplier.print_inv();

            cout << "Enter prodact id to add" << endl;
            cin >> id;
            cout << "Enter prodact quantity to add" << endl;
            cin >> q;

            Product p = (this->customer->get_cart().Get_List())[id-1];

            this->customer->add_to_cart(p, q);


        }
        else if(user_input == 3)
        {
            this->customer->print_cart();

            cout << "Enter prodact id to remove" << endl;
            cin >> id;
            cout << "Enter prodact quantity to remove" << endl;
            cin >> q;

            Product p = (this->customer->get_cart().Get_List())[id-1];

            this->customer->remove_from_cart(id, q);
        }
        else if(user_input == 4)
        {
            this->customer->print_cart();


        }
        else if(user_input == 5)
        {
            string answer;
            double total_price = this->customer->get_cart().Get_total();
            cout << "The price of all prodacts in the cart are " << total_price << endl;
            cout << "Do you want to pay? (yes/no)"<< endl;
            cin >> answer;
            if(answer == "yes")
            {
                this->supplier.customer_purchases(*(this->customer)); 

                this->customer->checkout();
            }

            

        }


    }
}
