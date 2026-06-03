#include <iostream>
#include "Menu.h"
using namespace std;

class Menu
{    
public:

    void print_menu() {
        cout << "1. stackMenu" << endl;
        cout << "2. queueMenu" << endl;
        cout << "3. Exit" << endl;
        int user_input;
        cin >> user_input;
        this->input_manager(user_input);

    }
    void input_manager(int user_input) {
        if (user_input == 1) {
            cout << "stackMenu" << endl;
            this->stackMenu();
        }
        else if (user_input == 2) {
            cout << "queueMenu" << endl;
            this->queueMenu();
        }
        else if (user_input == 3) {
            cout << "Exit" << endl;
           
        }
        else {
            cout << "Invalid input. Please try again." << endl;
        }

    }
    void stackMenu() {
        cout << "stackMenu" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. isEmpty" << endl;      
        cout << "4. Print Stack " << endl;
        cout << "5. Return to Main Menu" << endl;
        int user_input;
        cin >> user_input;
        if (user_input == 1) {
            cout << "Push" << endl;
        }
        else if (user_input == 2)
        {
            /* code */
        }
        else if (user_input == 3)
        {
            /* code */
        }
        else if (user_input == 4)
        {
            /* code */
        }
        else if (user_input == 5)
        {
            cout << "Return to Main Menu" << endl;
            this->print_menu();
        }
         else {
            cout << "Invalid input. Please try again." << endl;
        }
        this->stackMenu();
    
    }
    void queueMenu() {
        cout << "queueMenu" << endl;
        cout << "1. Print Queue" << endl;
        cout << "2. Add Element" << endl;
        cout << "3. Remove Element" << endl;      
        cout << "4. Print First Element" << endl;
        cout << "5. Return to Main Menu" << endl;
        int user_input;
        cin >> user_input;
        if (user_input == 1) {
            cout << "Print Queue" << endl;  
        }   
        else if (user_input == 2)
        {
            cout << "Add Element" << endl;
        }
        else if (user_input == 3)
        {
            cout << "Remove Element" << endl;
        }
        else if (user_input == 4)
        {
            cout << "Print First Element" << endl;
        }
        else if (user_input == 5)
        {
            cout << "Return to Main Menu" << endl;
            this->print_menu();
        }
         else {
            cout << "Invalid input. Please try again." << endl;
        }
        this->queueMenu();
    }
    Menu() {
        // Constructor code here
    }   
    
};

int main()
{
    Menu menu;
    menu.print_menu();
    
}
