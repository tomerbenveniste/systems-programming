/****************************************
Assignment C++: 2 Author: Tomer Benveniste, ID: 207961954 / Carmi Frank, ID: 206463846
*****************************************/

#include "Menu.h"
#include <iostream>
using namespace std;

// Initialises the menu: supplier is default-constructed, customer starts as nullptr
Menu::Menu() : supplier(), customer(nullptr) {
}

// Deletes a created customer when the menu is destroyed
Menu::~Menu() {
    delete customer;
}

// Helper to find a product in inventory by ID; returns index or -1 if not found
static int find_product_index(const vector<Product> &inventory, int id) {
    for (int i = 0; i < (int)inventory.size(); i++) {
        if (inventory[i] == id) {
            return i;
        }
    }
    return -1;
}

void Menu::mainMenu() {
    cout << endl;
    int user_input;

    while (true) {
        
        cout << "Main Menu:" << endl;
        cout << "1. Store Menu" << endl;
        cout << "2. Shopping Cart Menu" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";

        cin >> user_input;
        

        if (user_input == 1) {
            supplierMenu();
        } else if (user_input == 2) {
            buyerMenu();
        } else if (user_input == 3) {
            cout << "Goodbye!" << endl;
            return;
        } else {
            cout << "Invalid option. Please try again." ;
        }
    }
}

void Menu::supplierMenu() {
    while (true) {
        cout << endl;
        cout << "Store Menu:" << endl;
        cout << "1. Print store" << endl;
        cout << "2. Add quantity to existing product or add new product" << endl;
        cout << "3. Change existing product price" << endl;
        cout << "4. Remove product from the store" << endl;
        cout << "5. View total profit" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";

        int user_input;
        cin >> user_input;

        if (user_input == 1) {
            cout << supplier;
        } else if (user_input == 2) {
            cout << supplier;
            cout << endl;

            
            cout << "Enter product ID: ";
            int id;
            cin >> id;
            

            const vector<Product> &inventory = supplier.get_inventory();
            int index = find_product_index(inventory, id);

            if (index == -1) {
                cout << "Product not found." << endl;
                cout << "Adding new product." << endl;
                string name;
                double price;
                int quantity;
                cout << "Enter product name: ";
                cin >> name;
                cout << "Enter product price: ";
                cin >> price;
                cout << "Enter quantity: ";
                cin >> quantity;
                Product p(name, price);
                supplier.add_Product(p, quantity);
                cout << "Product added." ;
            } else {
                int quantity;
                cout << "Enter quantity: ";
                cin >> quantity;
                Product p = inventory[index];
                supplier.add_Product(p, quantity);
                cout << "Product added." ;
            }
        } else if (user_input == 3) {
            cout << supplier;
            cout << endl;

            
            cout << "Enter product ID: ";
            int id;
            cin >> id ;
            const vector<Product> &inventory = supplier.get_inventory();
            int index = find_product_index(inventory, id);
            if (index == -1) {
                cout << "Product not found." ;

            } else {
                cout << "Product found: " << inventory[index] << endl;
                double price;
                cout << "Enter new price: ";
                cin >> price;
                supplier.change_price(id, price);
                cout << "Price updated successfully." ;
            }
        } else if (user_input == 4) {
            cout << supplier;
            int id;
            cin >> id;
            cout << endl;

            cout << "Enter product ID: ";
            
            const vector<Product> &inventory = supplier.get_inventory();
            int index = find_product_index(inventory, id);
            if (index == -1) {
                cout << "Product not found." ;

            } else {
                Product p = inventory[index];
                supplier.remove_Product(p);
            }
        } else if (user_input == 5) {
            cout << "Total profit: " << supplier.get_total_profit() ;
        } else if (user_input == 6) {
            cout << "Exiting supplier menu." << endl;
            cout << "" << endl;

            return;
        } else {
            cout << "Invalid option. Please try again." ;
        }

        cout << endl;
    }
}

void Menu::buyerMenu() {
    if (customer == nullptr) {
        customer = new Customer("Customer");
    }

    while (true) {
        cout << endl;
        cout << "Shopping Cart Menu:" << endl;
        cout << "1. Print items in store" << endl;
        cout << "2. Add product to cart from store" << endl;
        cout << "3. Remove product" << endl;
        cout << "4. View cart" << endl;
        cout << "5. Check out" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";

        int user_input;
        cin >> user_input;

        if (user_input == 1) {
            cout << "Items in the store:" << endl;
            cout << supplier;
        } else if (user_input == 2) {
            cout << "Items in the store:" << endl;
            cout << supplier<<endl;

            int id;
            cout << "Enter product ID to add: ";
            cin >> id;

            const vector<Product> &inventory = supplier.get_inventory();
            int index = find_product_index(inventory, id);
            if (index == -1) {
                cout << "Product not found." ;

            } else {
                int quantity;
                cout << "Enter quantity: ";
                cin >> quantity;

                const Product &store_product = inventory[index];
                int available = (int)store_product.get_quantity();
                if (quantity > available) {
                    cout << "Not enough stock." << endl;
                    quantity = available;
                }
                customer->add_to_cart(store_product, quantity);
                cout << "Product added to cart." ;
            }
        } else if (user_input == 3) {
            cout << "Items in the cart:" << endl;
            customer->print_cart();
            int id;
            cout << "Enter product ID to remove: ";
            cin >> id;

            Product *product = customer->get_cart()[id];
            if (product == nullptr) {
                cout << "Product not found." << endl;

            } else {
                int quantity;
                cout << "Enter quantity: ";
                cin >> quantity;
                customer->remove_from_cart(id, quantity);
            }
        } else if (user_input == 4) {
            cout << "Items in the cart:" << endl;
            cout << customer->get_cart();
        } else if (user_input == 5) {
            double total_price = customer->get_cart().Get_total();
            cout << "Total price: " << total_price ;
            char answer;
            cout<<endl;
            cout << "Would you like to check out? (y/n): "<<endl;

            cin >> answer;

            if (answer == 'y' || answer == 'Y') {
                supplier.customer_purchases(*customer);
                cout <<endl;

                customer->checkout();
            }
        } else if (user_input == 6) {
            cout << "Exiting shopping cart menu." << endl;
            cout << endl;
            return;
        } else {
            cout << "Invalid option. Please try again.";
        }

        cout << endl;
    }
}
