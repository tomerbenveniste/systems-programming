# Project Context for Claude

## What this project is
This repo is the hub for all C programming assignments in the Intro to System Programming course.
Assignments are organized by folder (`ex3/`, `ex4/`, etc.). The root-level `main.c` is an old draft — ignore it.
Work is done in pairs with school partner Carmi (GitHub: CarmiF). IDs: 207961954 (Tomer) and 206463846 (Carmi).

---

## ex4 — EX2: Inventory Management System (CURRENT ASSIGNMENT)

### Branch & file setup
- Working branch: `ex4-tomer-1` (branched from `main`, includes Carmi's branch `origin/ex4_carmi_1` merged in)
- `ex4/Task02/ex02.c` — **the file we are actively developing** (created this session)
- `ex4/Task02/main_template.c` — plain professor's scaffold, restored to original (Carmi mistakenly worked in this file; his work was moved to `ex02.c`)
- Carmi's original work lives on `origin/ex4_carmi_1`

### Overview
Linked-list based inventory system associating items to warehouses. Single-file submission.
- Source: `ex4/Task02/ex02.c` (exists — partially implemented, see status below)
- Compile (Linux): `gcc ex02.c -o ex02.out`
- Reference binary: `ex4/Task02/task02.out` (Linux) and `ex4/Task02/task02` (also Linux, added by Carmi)
- Test files: `ex4/Task02/input01.txt` (stdin), `ex4/Task02\output01.txt` (expected stdout)
- Do NOT modify `main()`, `getstring()`, or `print_error_message()` in the template

### Current state of ex02.c
All commands are stubbed and compile. Functions implemented:
- `search_item_by_id`, `search_warehouse_by_code` — recursive search
- `add_sorted_itemlst`, `add_sorted_whs` — insert into linked list in ascending id/code order
- `create_item`, `create_warehouse` — malloc + strdup + sorted insert; reuse if id/code exists
- `assign_item_to_warehouse` — adds item to warehouse's list AND warehouse to item's list (both sides)
- `unassign_item_from_warehouse` — removes from both sides without freeing item/warehouse
- `print_item_lst`, `print_whs_lst`, `print_items` — print formatted output
- `generate_and_assign` — srand(1948), creates warehouses 0–9, items 0–99, assigns each via rand()%10
- `free_all` — frees all malloc'd memory

**Known issue:** output does not yet match `output01.txt` exactly — a line-by-line diff was started but not completed. The `w` command section showed an offset around line 20 vs expected. This needs investigation in the next session.

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
