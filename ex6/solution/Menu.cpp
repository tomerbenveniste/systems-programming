/****************************************
Assignment C++: 2
Author: Tomer Benveniste, ID: 207961954 / Carmi Frank, ID: 206463846
*****************************************/

#include "Menu.h"
#include <iostream>
#include <vector>

using namespace std;

// Initializes the menu:
// supplier is default-constructed,
// customer starts as nullptr because no customer exists yet.
Menu::Menu() : supplier(), customer(nullptr) {
}

// Deletes the customer if it was created dynamically.
Menu::~Menu() {
    delete customer;
}

// Helper function:
// Finds a product in a vector by its ID.
// Returns the index if found, otherwise returns -1.
static int find_product_index(const vector<Product> &products, int id) {
    for (int i = 0; i < (int)products.size(); i++) {
        if (products[i] == id) {
            return i;
        }
    }

    return -1;
}

void Menu::mainMenu() {
    int user_input;

    while (true) {
        cout << endl;
        cout << "Main Menu:" << endl;
        cout << "1. Store Menu" << endl;
        cout << "2. Shopping Cart Menu" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";

        cin >> user_input;

        if (user_input == 1) {
            supplierMenu();
        } else if (user_input == 2) {
            // create customer on first entry; keep existing customer (and cart) on re-entry
            if (customer == nullptr) {
                customer = new Customer("Customer");
            }
            buyerMenu();
        } else if (user_input == 3) {
            cout << "Goodbye!" << endl;
            return;
        } else {
            cout << "Invalid option. Please try again." << endl;
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
            cout << supplier << endl;
        }

        else if (user_input == 2) {
            cout << supplier << endl; // show current inventory before asking

            int id;
            cout << "Enter product ID: ";
            cin >> id;

            const vector<Product> &inventory = supplier.get_inventory();
            int index = find_product_index(inventory, id);

            if (index == -1) {
                // ID not found - create a brand-new product (gets auto-assigned ID)
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

                if (quantity <= 0) {
                    cout << "Quantity must be positive." << endl;
                } else {
                    Product p(name, price); // auto-ID assigned here
                    supplier.add_Product(p, quantity);
                    cout << "Product added." << endl;
                }
            } else {
                // ID found - restock existing product by the given quantity
                int quantity;

                cout << "Enter quantity: ";
                cin >> quantity;

                if (quantity <= 0) {
                    cout << "Quantity must be positive." << endl;
                } else {
                    Product p = inventory[index]; // copy so we can pass by const ref
                    supplier.add_Product(p, quantity);
                    cout << "Product added." << endl;
                }
            }
        }

        else if (user_input == 3) {
            cout << supplier << endl;

            int id;
            cout << "Enter product ID: ";
            cin >> id;

            const vector<Product> &inventory = supplier.get_inventory();
            int index = find_product_index(inventory, id);

            if (index == -1) {
                cout << "Product not found." << endl;
            } else {
                cout << "Product found: " << inventory[index] << endl;

                double price;
                cout << "Enter new price: ";
                cin >> price;

                if (price < 0) {
                    cout << "Price cannot be negative." << endl;
                } else {
                    supplier.change_price(id, price);
                    cout << "Price updated successfully." << endl;
                }
            }
        }

        else if (user_input == 4) {
            cout << supplier << endl;

            int id;
            cout << "Enter product ID: ";
            cin >> id;

            const vector<Product> &inventory = supplier.get_inventory();
            int index = find_product_index(inventory, id);

            if (index == -1) {
                cout << "Product not found." << endl;
            } else {
                Product p = inventory[index];
                supplier.remove_Product(p);
                cout << "Product removed from store." << endl;
            }
        }

        else if (user_input == 5) {
            cout << "Total profit: " << supplier.get_total_profit() << endl;
        }

        else if (user_input == 6) {
            cout << "Exiting supplier menu." << endl;
            return;
        }

        else {
            cout << "Invalid option. Please try again." << endl;
        }
    }
}

void Menu::buyerMenu() {
    // customer is always created by mainMenu() before this is called
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
            cout << supplier << endl;
        }

        else if (user_input == 2) {
            cout << "Items in the store:" << endl;
            cout << supplier << endl;

            int id;
            cout << "Enter product ID to add: ";
            cin >> id;

            const vector<Product> &inventory = supplier.get_inventory();
            int index = find_product_index(inventory, id);

            if (index == -1) {
                cout << "Product not found." << endl;
            } else {
                int quantity;
                cout << "Enter quantity: ";
                cin >> quantity;


                const Product &store_product = inventory[index];

                // check how many units are already reserved in the cart
                const vector<Product> &products_in_cart_vec = customer->get_cart().Get_List();
                int index_in_cart = find_product_index(products_in_cart_vec, id);

                int quantity_already_in_cart = 0;
                if (index_in_cart != -1) {
                    // product is in the cart - read its reserved quantity
                    quantity_already_in_cart = products_in_cart_vec[index_in_cart].get_quantity();
                }

                // available = store stock minus what's already reserved in cart
                int available = store_product.get_quantity() - quantity_already_in_cart;

                if (available < 0) {
                    // cart already holds more than store has (shouldn't normally happen)
                    cout << "Not enough stock." << endl;
                    continue;
                }

                if (quantity > available) {
                    if (available > 0) {
                        cout << "Not enough stock." << endl;
                    }
                    quantity = available; // cap to what's actually available
                }
                customer->add_to_cart(store_product, quantity);
                cout << "Product added to cart." << endl;
            }
        }

        else if (user_input == 3) {
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

                if (quantity <= 0) {
                    cout << "Quantity must be positive." << endl;
                } else {
                    customer->remove_from_cart(id, quantity);
                    cout << "Product removed from cart." << endl;
                }
            }
        }

        else if (user_input == 4) {
            cout << "Items in the cart:" << endl;
            customer->print_cart();
        }

        else if (user_input == 5) {
            // get_checkout_total() is polymorphic - returns discounted total for business customers
            cout << "Total price: " << customer->get_checkout_total() << endl;
            cout << "Would you like to check out? (y/n): ";

            char answer;
            cin >> answer;

            if (answer == 'y' || answer == 'Y') {
                // reduce inventory first, while the cart still holds the items
                supplier.reduce_inventory(customer->get_cart());
                // checkout() is polymorphic - applies discount for business customers
                // it prints cart contents, clears the cart, and returns the final amount paid
                double final_amount = customer->checkout();
                // add the actual payment (possibly discounted) to the supplier's counter
                supplier.add_profit(final_amount);
            }
        }

        else if (user_input == 6) {
            cout << "Exiting shopping cart menu." << endl;
            return;
        }

        else {
            cout << "Invalid option. Please try again." << endl;
        }
    }
}