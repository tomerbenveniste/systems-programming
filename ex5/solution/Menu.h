#include "MyQueue.h"
#include "Stack.h"

class Menu
{
    private:
    MyQueue queue;
    Stack stack;

    public:
    void mainMenu();
    void input_manager(int user_input);
    void stackMenu();
    void queueMenu();       
    Menu();
    ~Menu();
};