/* Assignment C++: 1
   Author: Tomer Benveniste, ID: 207961954 / Carmi Friedman, ID: 206463846
   */

/* iostream is a library in C++ that provides input and output functionality. It allows us to read
 * from the standard input (keyboard) and write to the standard output (console). */
#include <iostream>
/* We include the header file "Menu.h" which contains the declaration of the Menu class.
 * This allows us to use the Menu class and its member functions in this implementation file. */
#include "Menu.h"
/* the using namespace std; directive allows us to use names from the standard library (like cout and cin)
 * without having to prefix them with std::. */
using namespace std;

/* The mainMenu function is the entry point of the menu system. It displays the main menu
 * options and handles user input to navigate to the stack menu, queue menu, or exit the program. */
void Menu::mainMenu() {
    // We use an infinite loop to continuously display the main menu until the user chooses to exit.
    while (true) {
        // Display the main menu options to the user.
        cout << "Main Menu" << endl;
        cout << "1. stackMenu" << endl;
        cout << "2. queueMenu" << endl;
        cout << "3. Exit" << endl;
        // Read the user's input for menu selection.
        int user_input;
        cin >> user_input;
        // Based on the user's input, we call the appropriate menu function or exit the program.
        if (user_input == 1) {
        // If the user selects option 1, we call the stackMenu function to display the stack menu and handle stack operations.
        this->stackMenu();
        }
        else if (user_input == 2) {
            // If the user selects option 2, we call the queueMenu function to display the queue menu and handle queue operations.
            this->queueMenu();
        }
        else if (user_input == 3) {
            // If the user selects option 3, we print "Exit" and terminate the program using exit(0).
            cout << "Exit" << endl;
            cout << "Goodbye!" << endl;
            exit(0);
            
        }
        else {
            // If the user enters an invalid option, we display an error message and prompt them to try again.
            cout << "Invalid input. Please try again." << endl;
        }
    }
  

}
/* The stackMenu function displays the stack menu options and handles user input to perform stack
 * operations such as push, pop, check if the stack is empty, print the stack, or return to the main menu. */
void Menu::stackMenu() {
    while (true) {
        cout << "stackMenu" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. isEmpty" << endl;      
        cout << "4. Print Stack " << endl;
        cout << "5. Return to Main Menu" << endl;
        int user_input;
        cin >> user_input;
        /* Based on the user's input, we perform the corresponding stack operation.
         * If the user selects option 1, we prompt them to enter an element to push into the stack,
         * read the input, and call the push function of the stack. */
        if (user_input == 1) {
                cout << "Enter element to push: ";
                int element;
                cin >> element;
                this->stack.push(element);
        }
        // If the user selects option 2, we call the pop function of the stack to remove the top element.
        else if (user_input == 2)
        {
            this->stack.pop();
        }
        // If the user selects option 3, we check if the stack is empty and print the appropriate message.
        else if (user_input == 3)
        {
            cout << "Stack is " << (this->stack.isEmpty() ? "empty" : "not empty") << endl;
        }
        // If the user selects option 4, we call the print_stack function of the stack to display the contents of the stack.
        else if (user_input == 4)
        {
            cout << "Print Stack" << endl;
            cout << this->stack;
        }
        // If the user selects option 5, we break out of the loop and return to the main menu.
        else if (user_input == 5)
        {
            break;
        }
            else {
            cout << "Invalid input. Please try again." << endl;
        }
    }   

}
/* The queueMenu function displays the queue menu options and handles user input to perform queue operations
 * such as printing the queue, adding an element, removing an element, printing the first element,
 * or returning to the main menu. */
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
        // Based on the user's input, we perform the corresponding queue operation.
        // If the user selects option 1, we call the print_queue function of the queue
        if (user_input == 1) {
            cout << "Print Queue" << endl;  
            this->queue.print_queue();
        }   
        /* If the user selects option 2, we check if the queue is full. If it is full, we display a message
         * and return to the queue menu. Otherwise, we prompt the user to enter an element to add to the queue,
         * read the input, and call the enQueue function of the queue. */
        else if (user_input == 2)
        {
            if (this->queue.is_full()) {
                cout << "Queue is full. Cannot add element." << endl;
                continue;
            }
            cout << "Enter element to add: ";
            int element;
            cin >> element;
            this->queue.enQueue(element);
        }
        // If the user selects option 3, we call the deQueue function of the queue to remove the front element.
        else if (user_input == 3)
        {
            cout << "Remove Element" << endl;
            this->queue.deQueue();
        }
        // If the user selects option 4, we call the peek function of the queue to get the front element and print it.
        else if (user_input == 4)
        {
            cout << "Print First Element" << endl;
            cout << this->queue.peek() << endl;
        }
        // If the user selects option 5, we break out of the loop and return to the main menu.
        else if (user_input == 5)
        {
            break;
        }
            else {
            cout << "Invalid input. Please try again." << endl;
        }
    }
}

// The constructor of the Menu class initializes
Menu::Menu() : queue(0), stack() {
    // No additional initialization needed
}
// The destructor of the Menu class is called when an object of the Menu class goes out of scope or is explicitly deleted. It prints a message indicating that the destructor has been called.
Menu::~Menu() {
    // No manual cleanup needed since we are using standard library containers and dynamic memory is managed within those containers.
    }
