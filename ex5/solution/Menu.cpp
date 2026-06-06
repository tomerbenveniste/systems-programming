#include <iostream>
#include "Menu.h"
#include "MyQueue.h"

using namespace std;

void Menu::mainMenu() {
    while (true) {
        cout << "Main Menu" << endl;
        cout << "1. stackMenu" << endl;
        cout << "2. queueMenu" << endl;
        cout << "3. Exit" << endl;
        int user_input;
        cin >> user_input;
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
            exit(0);
            
        }
        else {
            cout << "Invalid input. Please try again." << endl;
        }
    }
  

}
void Menu::input_manager(int user_input) {
    

}
void Menu::stackMenu() {
    int user_input;
    while (true) {
        cout << "stackMenu" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. isEmpty" << endl;      
        cout << "4. Print Stack " << endl;
        cout << "5. Return to Main Menu" << endl;
        int user_input;
        cin >> user_input;
        if (user_input == 1) {
                cout << "Enter element to push: ";
                int* element = new int;
                cin >> *element;
                this->stack.push(*element);
                delete element;
        }
        else if (user_input == 2)
        {
            this->stack.pop();
        }
        else if (user_input == 3)
        {
            cout << "Stack is " << (this->stack.isEmpty() ? "empty" : "not empty") << endl;
        }
        else if (user_input == 4)
        {
            cout << "Print Stack" << endl;
            this->stack.print_stack();  
        }
        else if (user_input == 5)
        {
            break;
        }
            else {
            cout << "Invalid input. Please try again." << endl;
        }
    }   

}
void Menu::queueMenu() {
    while (true) {
        if(this->queue.get_maxQ() == 0) {
            cout << "Enter queue size: " << endl;
            int maxQ;
            cin >> maxQ;
            this->queue.set_maxQ(maxQ);
        }
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
            this->queue.print_queue();
        }   
        else if (user_input == 2)
        {
            if (this->queue.is_full()) {
                cout << "Queue is full. Cannot add element." << endl;
                this->queueMenu();
                return;
            }
            cout << "Enter element to add: ";
            int* element = new int;
            cin >> *element;
            bool result = this->queue.enQueue(*element);
            delete element;
        }
        else if (user_input == 3)
        {
            cout << "Remove Element" << endl;
            this->queue.deQueue();
        }
        else if (user_input == 4)
        {
            cout << "Print First Element" << endl;
            cout << this->queue.peek() << endl;
        }
        else if (user_input == 5)
        {
            break;
        }
            else {
            cout << "Invalid input. Please try again." << endl;
        }
    }
}
Menu::Menu() : queue(0), stack() {
    cout << "Menu constructor called" << endl;
}
Menu::~Menu() {
    cout << "Menu destructor called" << endl;
}



int main()
{

     Menu menu;
    menu.mainMenu();
    return 0;
    
}
