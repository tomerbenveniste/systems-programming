#include "MyQueue.h"

class Menu
{
    private:
    MyQueue queue;

    public:
    void print_menu();
    void input_manager(int user_input);
    void stackMenu();
    void queueMenu();       
    Menu();
    ~Menu();
};