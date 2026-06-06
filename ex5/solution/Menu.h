// Menu.h
// The Menu class provides a user interface for interacting with a stack and a queue. It includes functions to display the main menu, stack menu, and queue menu, allowing users to perform various operations on the stack and queue.
#include "MyQueue.h"
#include "Stack.h"

class Menu
{
    private:
    // We declare two member variables: queue of type MyQueue and stack of type Stack. These will be used to perform operations on the queue and stack respectively.
    MyQueue queue;
    Stack stack;

    public:
    // We declare the member functions of the Menu class. These functions will handle the display and user interaction for the main menu, stack menu, and queue menu.
    // The mainMenu function is the entry point of the menu system. It displays the main menu options and handles user input to navigate to the stack menu, queue menu, or exit the program.
    void mainMenu();
    // The stackMenu function displays the stack menu options and handles user input to perform stack operations such as push, pop, check if the stack is empty, print the stack, or return to the main menu.
    void stackMenu();
    // The queueMenu function displays the queue menu options and handles user input to perform queue operations such as printing the queue, adding an element, removing an element, printing the first element, or returning to the main menu.
    void queueMenu();    
    // The constructor of the Menu class initializes   
    Menu();
    // The destructor of the Menu class
    ~Menu();
};