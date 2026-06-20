# Project Context for Claude

## What this project is
This repo is the hub for all C/C++ programming assignments in the Intro to System Programming course.
Assignments are organized by folder (`ex3/`, `ex4/`, `ex5/` etc.). The root-level `main.c` is an old draft — ignore it.
Work is done in pairs with school partner Carmi (GitHub: CarmiF). IDs: 207961954 (Tomer) and 206463846 (Carmi).

---

## ex6 — Assignment 2 C++: Shopping System (IN PROGRESS)

### Topics
Operator overloading, inheritance (polymorphism), friend functions

### Status
- `Product` class: **COMPLETE** — merged to main via PR #9 (branch `ex6-tomer-class-product`)
- `ShoppingCart` class: **COMPLETE** — PR #10 open (branch `ex6-tomer-shopping-cart-class`)
- `Supplier` class: **COMPLETE** — merged to main via PR #11 (branch `ex6-tomer-supplier-class`)
- `Customer` / `BusinessCustomer`: **IN PROGRESS** — on branch `tomer_ex6` (branched from `origin/carmi_ex6`); Carmi wrote initial version, Tomer cleaned up (removed extra ctors, fixed destructor, propagated return value, `Get_total() const`, `BusinessCustomer::checkout()` endl)
- `Menu`: **IN PROGRESS** — on branch `tomer_ex6`; Carmi wrote full implementation; known remaining bugs (see below)
- All source in `ex6/solution/`
- Reference input/output: `ex6/moodle_files/in.txt` / `ex6/moodle_files/out.txt`
- Assignment PDF: `ex6/moodle_files/assignment2CPP2026B.pdf`
- VPL entry point: `ex6/moodle_files/assignment2.cpp` (provided — don't modify; just `#include "Menu.h"` and calls `Menu a; a.mainMenu();`)

### Known remaining bugs (found by running diff against out.txt)
1. `ShoppingCart::printcart()` prints header `"Shopping Cart:"` — should be `"Shopping Cart Details:"`
2. `buyerMenu` option 4 (view cart) uses `cout << customer->get_cart()` (calls `operator<<` → wrong header) — should call `customer->print_cart()` instead
3. Cart item ordering: when adding a product already in cart with 0 available, `add_Product(..., 0)` may reorder items — expected order in out.txt differs from ours

### Teaching approach
- Working lesson-by-lesson: Tomer writes code, Claude reviews before moving on
- Emphasis on OOP principles + C++ syntax at each step
- Each class gets its own branch, PR to main when done

### Files status (all in `ex6/solution/`)
- `Product.h` / `Product.cpp` — **DONE**
- `ShoppingCart.h` / `ShoppingCart.cpp` — **DONE** (bug: `printcart()` header wrong — see known bugs)
- `Supplier.h` / `Supplier.cpp` — **DONE**
- `Customer.h` / `Customer.cpp` — **DONE** (cleaned up on `tomer_ex6`)
- `Menu.h` / `Menu.cpp` — **IN PROGRESS** (has bugs — see known bugs above)

### Class specifications

#### Product
```cpp
class Product {
private:
    static int next_id;       // auto-increments for each new Product(name,price,q)
    int id;
    string name;
    double price;
    unsigned int quantity;
public:
    Product(const Product &p);            // copy: same ID
    Product(const Product &p, int q);     // copy: same ID, different quantity
    Product(string name, double price, int q = 1); // new ID assigned from next_id
    double get_price() const;
    double get_quantity() const;
    double get_id() const;
    friend ostream &operator<<(ostream &os, const Product &p);
    bool operator==(const Product &other) const; // compares IDs
    bool operator==(int other_id) const;
    bool operator!=(const Product &other) const;
    bool operator!=(int other_id) const;
    Product &operator++();        // quantity += 1
    Product &operator+=(unsigned int q);
    Product &operator-=(unsigned int q);
};
```
- `operator<<` format: `Product ID: X, Name: Y, Price: Z, Quantity: W`
- IDs auto-assigned starting at 1; user never chooses the ID when creating

#### ShoppingCart
```cpp
class ShoppingCart {
protected:
    vector<Product> items;
    double total_price;
public:
    ShoppingCart();
    virtual ~ShoppingCart();
    bool add_Product(const Product &p);                  // adds full quantity; total_price += price * quantity
    bool add_Product(const Product &p, int quantity);    // total_price += price * quantity
    bool remove_Product(const Product &p);               // remove entirely
    bool remove_Product(const Product &p, int quantity); // reduce quantity
    const vector<Product> &Get_List() const;
    void printcart() const;                // prints "Shopping Cart Details:\n[products]\nTotal Price: X"
    virtual double Get_total() const;
    friend ostream &operator<<(ostream &os, const ShoppingCart &cart);
    Product* operator[](int id);           // find by ID, nullptr if not found
};
```
- `printcart()` output header: `Shopping Cart Details:`
- `operator<<` output header: `Shopping Cart:` (used in checkout context)

#### Supplier
```cpp
class Supplier {
private:
    double counter = 0;          // total profit: decreases when adding inventory, increases on customer purchase
    vector<Product> inventory;
public:
    Supplier();
    ~Supplier();
    bool remove_Product(const Product &p);
    bool remove_Product(const Product &p, int quantity);
    bool customer_purchases(Customer &c);              // processes customer cart, adds total to counter
    bool customer_purchases(const ShoppingCart &cart); // adds cart.total_price to counter
    bool change_price(int id, double new_price);
    double get_total_profit() const;
    friend ostream &operator<<(ostream &os, const Supplier &supplier);
};
```
- `operator<<` format:
  ```
  Supplier Details:
  Product ID: 1, Name: Milk, Price: 3.5, Quantity: 10
  Total Profit: -65
  ```
- **Counter behavior**: when supplier ADDS products to inventory → `counter -= price * quantity` (cost). When customer PURCHASES → `counter += total`. So counter starts negative (inventory cost) and rises with sales.
- `change_price` prints error if ID not found

#### Customer & BusinessCustomer
```cpp
class Customer {
protected:
    string name;
    ShoppingCart cart;
public:
    Customer(string name);
    virtual ~Customer();
    virtual bool add_to_cart(const Product &p, int quantity);
    virtual bool remove_from_cart(int id, int quantity);
    virtual double checkout();  // empties cart, prints cart contents, returns total
    void print_cart() const;
    friend ostream &operator<<(ostream &os, const Customer &c);
};

class BusinessCustomer : public Customer {
private:
    string company_name;
    double discount_rate;   // e.g. 0.1 = 10% discount
public:
    BusinessCustomer(string name, string company_name, double discount_rate);
    virtual ~BusinessCustomer();
    virtual double checkout() override;  // applies discount before returning total
    friend ostream &operator<<(ostream &os, const BusinessCustomer &bc);
};
```

#### Menu
```cpp
class Menu {
private:
    Supplier supplier;
    Customer* customer;   // polymorphic pointer — created when entering buyer menu
public:
    Menu();
    ~Menu();
    void mainMenu();     // loops: 1=supplierMenu, 2=buyerMenu (ask regular/business), 3=exit "Goodbye!"
    void supplierMenu(); // loops: 1=print store, 2=add/restock, 3=change price, 4=remove, 5=profit, 6=back
    void buyerMenu();    // loops: 1=print store, 2=add to cart, 3=remove from cart, 4=view cart, 5=checkout, 6=back
};
```

### Menu behavior details (from out.txt)

#### mainMenu
- Option 1: enter `supplierMenu()`
- Option 2: silently create `new Customer("Customer")` and call `buyerMenu()` — **out.txt is the authority: no customer type/name prompts appear in the reference output**
- Option 3: print `Goodbye!` and exit

#### supplierMenu
- Option 1: print `supplier` via `operator<<` (shows all inventory + total profit)
- Option 2: print all products (ID, name, qty), ask for product ID:
  - Found → ask quantity to add, call `++`/`+=` on product, `counter -= price * added_qty`
  - Not found → `"Adding new product."` → ask name, price, qty → create `Product` (gets auto-ID)
- Option 3: show all products (ID, name, price, qty), ask ID:
  - Found → `"Product found: [product]"` → ask new price → update → `"Price updated successfully."`
  - Not found → `"Product not found."`
- Option 4: show all products, ask ID:
  - Found → remove from inventory
  - Not found → `"Product not found."`
- Option 5: print `"Total profit: X"` (different from `operator<<` which prints `"Total Profit: X"`)
- Option 6: print `"Exiting supplier menu."`, return to main

#### buyerMenu
- Option 1: print `"Items in the store:\n"` then `cout << supplier`
- Option 2: print `"Items in the store:\n"` then `cout << supplier`, ask `"Enter product ID to add:"`, ask `"Enter quantity:"`:
  - Requested qty > supplier stock → `"Not enough stock."` (still adds, capped at available stock) + `"Product added to cart."`
  - Qty fits → `"Product added to cart."`
  - ID not found → `"Product not found."`
- Option 3: print `"Items in the cart:\n"` (from `printcart()`), ask ID, remove from cart
- Option 4: print `"Items in the cart:\n"` then `customer->print_cart()` (shows `Shopping Cart Details:` + products + total)
- Option 5 (checkout):
  - Print `"Total price: X\nWould you like to check out? (y/n): "`
  - If `y`: call `customer->checkout()` (prints `"Total price: X\nShopping Cart:\n[items]\nTotal Price: X"`, empties cart, returns total) → call `supplier.customer_purchases(*customer)` (adds total to counter)
  - If `n`: back to menu, cart unchanged
- Option 6: print `"Exiting shopping cart menu."`, return to main

### Output format key observations
- After supplier option 2 adds product: `"Product added."`
- Invalid menu option: `"Invalid option. Please try again."`
- Supplier inventory DOES NOT decrease when items added to cart — only decreases at checkout
- Customer object persists across buyer menu sessions (cart survives exit/re-enter)
- Product quantities in cart: if requested > available, caps at supplier stock (prints warning but adds capped amount)

### How to compile & test (Windows PowerShell, from project root)
```powershell
$env:PATH = "C:\Program Files\JetBrains\CLion 2026.1.1\bin\mingw\bin;" + $env:PATH
g++ ex6/solution/Product.cpp ex6/solution/ShoppingCart.cpp ex6/solution/Supplier.cpp ex6/solution/Customer.cpp ex6/solution/Menu.cpp ex6/moodle_files/assignment2.cpp -I ex6/solution -o ex6.exe -std=c++17
cmd /c '.\ex6.exe < "ex6\moodle_files\in.txt" > my_ex6_output.txt'
diff (Get-Content my_ex6_output.txt) (Get-Content "ex6\moodle_files\out.txt")
```

### Submission requirements
- All `.h` and `.cpp` files (Product, ShoppingCart, Supplier, Customer, Menu) + assignment2.cpp
- Header comment in every file:
  ```
  /****************************************
   Assignment C++: 2
   Author: Tomer Benveniste, ID: 207961954 / Carmi ..., ID: 206463846
  *****************************************/
  ```
- No C library functions — C++ only (`<iostream>`, `<string>`, `<vector>` etc.)
- Constants as `const`, `#define`, or `enum`
- English comments on every method and every 2–3 lines of code
- `const` on all non-mutating methods
- No duplicate code

---

## ex5 — Assignment 1 C++: Stack, Queue & Menu (IN PROGRESS)

### Status
- Carmi completed: StackNode, Stack (basic ops), MyQueue, Menu (basic menus)
- **Remaining: Stack operator overloads** (`+`, `+=`, `==`, `<<`) — the main missing piece
- Minor issue: `Stack::peek()` should return `INT_MIN` when empty (Carmi returns -1)

### Branch & file setup
- Working branch: `ex5-tomer-1` (branched from `origin/carmi_ex5_1`)
- All source in `ex5/solution/`
- Reference binary (Linux): `ex5/solution/program` and `ex5/moodle_files/executable1.exe`
- Assignment PDF: `ex5/moodle_files/assignment1CPP2026.pdf`

### Files (8 to submit — do NOT submit assignment1.cpp, it's provided by VPL)
- `StackNode.h` / `StackNode.cpp`
- `Stack.h` / `Stack.cpp`
- `MyQueue.h` / `MyQueue.cpp`
- `Menu.h` / `Menu.cpp`

### Classes overview

#### StackNode
- Private: `int data`, `StackNode* next`
- Public: default + parameterized constructors, destructor, `get_data()`, `get_next()`, `set_next()`

#### Stack (linked-list based, dynamic size)
- Private: `StackNode* top`
- Public: `Stack()` (top=nullptr), `~Stack()`, `push(int)`, `pop()` (prints "Stack is empty" if empty), `isEmpty() const`, `peek() const` (returns **INT_MIN** if empty)
- **Required operator overloads (not yet implemented):**
  - `operator+` (Stack + Stack): concatenates, returns new Stack with S1 bottom, S2 on top
  - `operator+` (Stack + int): appends int to top; `operator+` (int + Stack): prepends int at bottom
  - `operator+=` (Stack += int): pushes int onto stack (i.e. `S += 4` → 4 is new top)
  - `operator==` (Stack == Stack): true if same elements in same order
  - `operator<<` (ostream <<): prints stack elements numbered 1..n from bottom to top

#### MyQueue (vector-based, bounded capacity)
- Private: `vector<int> queue`, `int maxQ`
- Public: `MyQueue()`, `MyQueue(int maxQ)`, `~MyQueue()`, `enQueue(int)` (returns bool), `deQueue()` (returns bool), `isEmpty() const`, `peek() const` (returns -1 if empty), `print_queue()`, `is_full()`, `get_maxQ()`, `set_maxQ(int)`

#### Menu
- Private: `MyQueue queue`, `Stack stack`
- Public: `Menu()`, `~Menu()`, `mainMenu()`, `stackMenu()`, `queueMenu()`
- `mainMenu`: options 1 (stack menu), 2 (queue menu), 3 (exit — print "Goodbye!" then exit)
- `stackMenu`: options 1 (push), 2 (pop), 3 (isEmpty), 4 (print), 5 (back to main)
- `queueMenu`: first asks user for queue size if not set, then options 1 (print), 2 (add), 3 (remove), 4 (print first), 5 (back to main)
- `main()` is currently in `Menu.cpp` — check if assignment1.cpp is the VPL wrapper

### Stack operator << print format
From the assignment example (`S1={1,5}, S2={8,9}`, `cout << S1+S2`):
```
1. 1
2. 5
3. 8
4. 9
```
Elements printed bottom-to-top, numbered from 1.

### Submission requirements
- 8 files (see above), submitted by **both** students
- Header comment in every file:
  ```
  /* Assignment C++: 1
   Author: Tomer Benveniste, ID: 207961954 / Carmi ..., ID: 206463846
  */
  ```
- No C library functions — C++ only (`<iostream>`, `<vector>`, `<climits>` etc.)
- All logical constants as `const`, `#define`, or `enum`
- Extensive English comments on every method and every 2–3 lines
- Use `const` everywhere possible on methods that don't modify the object
- No duplicate code

### How to compile & test (Windows PowerShell, from project root)
```powershell
$env:PATH = "C:\Program Files\JetBrains\CLion 2026.1.1\bin\mingw\bin;" + $env:PATH
g++ ex5/solution/StackNode.cpp ex5/solution/Stack.cpp ex5/solution/MyQueue.cpp ex5/solution/Menu.cpp -o ex5.exe -std=c++17
.\ex5.exe
```

### Known issues in Carmi's code to fix
1. `Stack::peek()` returns -1 when empty — should return `INT_MIN` (per spec)
2. `Stack.h` and `StackNode.h` missing `#ifndef` include guards
3. `stackMenu()` declares `int user_input` twice (shadowed variable)
4. `queueMenu()` makes a recursive call when full — replace with a `continue`
5. Operator overloads (`+`, `+=`, `==`, `<<`) completely missing from Stack

---

## ex4 — EX2: Inventory Management System (COMPLETED)

### Status
- **Implementation complete** — all commands working, tests pass, output matches `output01.txt`
- **Now creating Q&A discussion** about the exercise (see `ex4/Task02/tomer_gpt.txt` and `ex4/Task02/gpt_context.md`)

### Branch & file setup
- Working branch: `ex4-tomer-1` (branched from `main`, includes Carmi's branch `origin/ex4_carmi_1` merged in)
- `ex4/Task02/ex02.c` — **the final submission file**
- `ex4/Task02/main_template.c` — plain professor's scaffold, restored to original
- Carmi's original work lives on `origin/ex4_carmi_1`

### Overview
Linked-list based inventory system associating items to warehouses. Single-file submission.
- Source: `ex4/Task02/ex02.c`
- Compile (Linux): `gcc ex02.c -o ex02.out`
- Reference binary: `ex4/Task02/task02.out` (Linux) and `ex4/Task02/task02` (also Linux, added by Carmi)
- Test files: `ex4/Task02/input01.txt` (stdin), `ex4/Task02/output01.txt` (expected stdout)
- Do NOT modify `main()`, `getstring()`, or `print_error_message()` in the template

### Implemented functions
- `search_item_by_id`, `search_warehouse_by_code` — recursive search
- `add_sorted_itemlst`, `add_sorted_whs` — insert into linked list in ascending id/code order
- `create_item`, `create_warehouse` — malloc + strdup + sorted insert; reuse if id/code exists
- `assign_item_to_warehouse` — adds item to warehouse's list AND warehouse to item's list (both sides)
- `unassign_item_from_warehouse` — removes from both sides without freeing item/warehouse
- `print_item_lst`, `print_whs_lst`, `print_items` — print formatted output
- `generate_and_assign` — srand(1948), creates warehouses 0–9, items 0–99, assigns each via rand()%10
- `free_all` — frees all malloc'd memory

### Data structures (from main_template.c)
```c
typedef struct item {
    char* name;           // dynamically allocated
    int id;
    struct wlst* warehouses;  // linked list of warehouses this item is in
} item;

typedef struct warehouse {
    char* location;       // dynamically allocated
    int code;
    struct itemlst* items;    // linked list of items in this warehouse
} warehouse;

typedef struct itemlst {
    item* data;
    struct itemlst* next;
} itemlst;

typedef struct wlst {
    warehouse* data;
    struct wlst* next;
} wlst;
```

Global state in main:
```c
itemlst* items = 0;
wlst* warehouses = 0;
```

### Commands
- `i` — new item: prompt for name then id; if id already exists, reuse the existing item unchanged
- `w` — new warehouse: prompt for location then code; if code already exists, reuse existing
- `a` — assign item (by id) to warehouse (by code)
- `u` — unassign item from warehouse (remove from both sides; do NOT delete item or warehouse)
- `p` — print status (see print format below)
- `g` — generate 100 items (id 0–99, name "Item<id>") and 10 warehouses (code 0–9, name "Warehouse<code>"), then assign each item to a random warehouse using `srand(1948)` and `int randomCode = rand() % 10`; if id/code already exists, reuse it
- `q` — quit

### Input reading (from template — do not change)
```c
// In main loop — reads command char:
while ((c = (char)getchar()) == '\n');
getchar();  // consumes newline after command char

// getstring: reads one whitespace-delimited token into buf
getstring(buf, 100);   // uses scanf("%s", buf), strips trailing \n

// Numeric input:
scanf("%d", &id);
```

### Print format (from output01.txt)
```
item LIST:
<id>:<name>
Item Warehouses: <code>-<location>, <code>-<location>   ← only printed if item has warehouses
...
warehouse LIST:
Warehouse code <code>, Warehouse name: <location>
items: ID <id> Name <name> | ID <id> Name <name> |      ← only printed if warehouse has items; trailing " | "
```
- Items printed in ascending id order
- Warehouses printed in ascending code order
- A blank line follows the warehouse list before the next menu
- "Item Warehouses:" line omitted entirely if item has no warehouses
- "items:" line omitted entirely if warehouse has no items

### DEBUGON and error handling
```c
//#define DEBUGON   ← comment out for submission

void print_error_message(int errid) {
    #ifdef DEBUGON
    fprintf(stderr, "BGU ERROR %d\n", errid);
    #else
    fprintf(stderr, "BGU ERROR\n");
    #endif
    exit(-1);
}
```
Call `print_error_message(anyCode)` on any error. Always exits the program.

### Input validation rules
- Numerical input: digits only, optional leading/trailing spaces and tabs; must be positive; anything else → `print_error_message`
- String input: max 100 chars (buf size)
- Task02.out behavior is the ground truth if instructions conflict

### How to test (Windows PowerShell, from project root)
```powershell
$env:PATH = "C:\Program Files\JetBrains\CLion 2026.1.1\bin\mingw\bin;" + $env:PATH
gcc "ex4\Task02\ex02.c" -o ex02.exe
cmd /c '.\ex02.exe < "ex4\Task02\input01.txt" > my_output.txt'
diff (Get-Content my_output.txt) (Get-Content "ex4\Task02\output01.txt")
```

### Submission requirements
- `ex02.c` (single C file)
- `gpt.txt` (full LLM conversation log including produced code)
- DEBUGON must be commented out before submission
- IDs in a comment at the top of the file

### Simulated conversation context
To generate `tomer_gpt.txt` in a new chat window, read [`ex4/Task02/gpt_context.md`](ex4/Task02/gpt_context.md) first.
It contains the full assignment spec, final code, a suggested conversation arc with sample questions in Tomer's voice, and formatting instructions.

---

## ex3 — Stock Management (COMPLETED)

### File structure of ex3/our_solution/
- `stock.h` — shared `Stock` struct definition and all function declarations
- `main.c` — entry point, menu loop, calls all section functions, defines `printMenu()`
- `section1.c` — `addStock()`, `isValidName()`, `isValidPrice()`
- `section2.c` — `printStocks()`
- `section3.c` — `doubleStocks()`
- `section4.c` — `dropStocks()`, `isValidPercent()`
- `section5.c` — `findLessExpensive()`
- `section6.c` — `sortByPrice()`
- `section7.c` — `sortByName()`
- `section8.c` — `sortByAsciiSum()`, `asciiSum()`
- `section9.c` — `findPalindromes()`, `isPalindrome()`

### The Stock struct (from stock.h)
```c
typedef struct {
    char name[21]; // letters only, max 20 chars
    float price;
} Stock;
```

### How stocks are stored (main.c)
```c
Stock** stocks = malloc(MAX_STOCKS * sizeof(Stock*)); // array of 10 pointers
int stock_count = 0;
```
Each time a stock is added, a new `Stock` is `malloc`'d and its address stored in `stocks[i]`.

### Key conventions we established
- Functions that only READ stock_count take `int stock_count` (by value)
- Functions that MODIFY stock_count take `int* ptr_stock_count` (by pointer)
- `addStock` is the only function that modifies stock_count
- All input is read via `fgets` into a `char input_buf[100]` buffer, then validated
- `strcspn(input_buf, "\n")` is used to strip the newline fgets captures

### Changes already made (fixes vs original code)
- `printStocks` signature fixed: `int* ptr_stock_count` → `int stock_count` in stock.h, section2.c, and main.c
- `doubleStocks` signature fixed: same pointer→value fix in stock.h, section3.c, and main.c
- `doubleStockPrices` renamed to `doubleStocks` everywhere to match assignment requirement

### Completed sections
- Section 1: `addStock`, `isValidName`, `isValidPrice`
- Section 2: `printStocks`
- Section 3: `doubleStocks`
- Section 4: `dropStocks`, `isValidPercent` — drops all prices by x% (whole number 0–100), prints `Stock prices has dropped by X%.`
- Section 5: `findLessExpensive` — finds and prints the stock with the lowest price
- Section 6: `sortByPrice` — sorts `stocks[]` in-place by price ascending (bubble sort), prints `Sorted by price.`
- Section 7: `sortByName` — sorts `stocks[]` in-place by name alphabetically (bubble sort + `strcmp`), prints `Sorted by name.`
- Section 8: `sortByAsciiSum` — sorts `stocks[]` in-place by ASCII sum of name (bubble sort + `asciiSum` helper), prints `Sorted by ASCII sum.`
- Section 9: `findPalindromes` — prints each stock whose name is a palindrome (case-sensitive), prints `No palindromic stock names found.` if none

### Section 4 implementation notes
- `isValidPercent` uses a `while` loop over chars, accepts digits only, rejects if `has_digits == 0 || result > 100`
- Price calc: `stocks[i]->price *= (1.0f - percent / 100.0f)` — `100.0f` forces float division
- `%%` in printf prints a literal `%`

### Sections 6–8 implementation notes
- All three sort the actual `stocks[]` pointer array in-place (not a copy), so order is permanently changed
- Swap is done by swapping `Stock*` pointers, not struct values
- Section 8 calls `asciiSum()` on each name during comparison; `asciiSum` loops over chars summing their int values

### Assignment constraints
- Only allowed libraries: `<stdio.h>`, `<string.h>`, `<stdlib.h>`
- Input is never assumed valid — always validate
- After every section (except 10), reprint the menu
- Max 10 stocks (`MAX_STOCKS` defined in stock.h)
- The user is a beginner in C — explain things clearly

### How to test the submission file (Windows PowerShell)

The test files live in `Test Files for Exs 1/`: `input.txt` (stdin), `output.txt` (expected stdout), `win.exe` (reference implementation).

Run these commands from the project root:

```powershell
# Add CLion's bundled gcc to PATH (required once per terminal session)
$env:PATH = "C:\Program Files\JetBrains\CLion 2026.1.1\bin\mingw\bin;" + $env:PATH

# Compile the submission file
gcc "ex3\moodle_files\207961954_206463846.c" -o submission_fixed.exe -std=c99

# Run with test input (use cmd /c — PowerShell doesn't support < for stdin)
cmd /c '.\submission_fixed.exe < "Test Files for Exs 1\input.txt" > my_output.txt'

# Compare output (no output = perfect match)
diff (Get-Content my_output.txt) (Get-Content "Test Files for Exs 1\output.txt")
```

### printf("\n") design convention in the submission file

Prompts like `"Please enter a number between 0-99: "` intentionally have **no `\n`** at the end.
The *next* block's leading `printf("\n")` is what terminates that line. Example:
- `printMenu` prints `"Please enter a number between 0-99: "` (no `\n`)
- `addStock` starts with `printf("\n")` — this closes the prompt line, then starts a new one

**Consequence:** any code path that follows a prompt but has no leading `printf("\n")` will appear on the same line as the prompt. `case 10` was the only such case — fixed by changing `printf("Exiting program...\n")` to `printf("\nExiting program...\n")`.
