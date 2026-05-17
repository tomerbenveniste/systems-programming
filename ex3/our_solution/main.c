//---------------------------------------------- Libraries Imported ----------------------------------------------------
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//---------------------------------------------- Constants Definition --------------------------------------------------
#define MAX_STOCKS 10

//------------------------------------------ Stock Structure Definition ------------------------------------------------
typedef struct {
    char name[21]; // 20 characters + '\0' character
    float price;
} Stock;

//--------------------------------------------- Functions Declaration --------------------------------------------------
// 0. the menu print function
void printMenu();
// 1. the Stock Adding function
void addStock(Stock** stocks, int* ptr_stock_count);
// function that checks for name validity (Assistant function for 1.)
int isValidName(const char* str_buf);
/*  function that checks for price validity and transfers the valid value via the
 *  price pointer address (Assistant function for 1.) */
int isValidPrice(const char* str_buf, float* ptr_price);

//-------------------------------------------------- Main Function -----------------------------------------------------
int main() {
    int stock_count = 0;
    Stock** stocks = malloc(MAX_STOCKS * sizeof(Stock*));

    int error_count = 0;
    int choice = -1;
    char input_buffer[100];

    // Flag to manage the loop execution state
    int keep_running = 1;

    // The main loop
    do {
        printMenu();
        // Read a line of input safely from the user
        if (fgets(input_buffer, sizeof(input_buffer), stdin) != NULL) {

            int is_valid = 0; // A flag that will be lit if the input is completely valid.
            int len = strlen(input_buffer); // The length of the inputted string (ignores the '\0' at the end)

            // check for a single-digit number (digit + '\n')
            if ( (len == 2) && (input_buffer[0] >= '0') && (input_buffer[0] <= '9') ) {
                choice = input_buffer[0] - '0'; // Convert char to int
                is_valid = 1;
            }
            // check for a two-digit number (digit + digit + '\n')
            else if ( (len == 3) && (input_buffer[0] >= '0') && (input_buffer[0] <= '9')
                                 && (input_buffer[1] >= '0') && (input_buffer[1] <= '9') ) {
                // convert both chars to a single int
                choice = (input_buffer[0] - '0') * 10 + (input_buffer[1] - '0');
                is_valid = 1;
            }
            if (is_valid == 1) {
                // valid format — check if it matches a menu option
                if (choice >= 1 && choice <= 10) {
                    error_count = 0;

                    // ------------------ switch cases -----------------------------
                    switch (choice) {
                        case 1: addStock(stocks, &stock_count);
                            break;
                        case 2:
                            printf("you chose option %d\n", choice);
                            break;
                        case 3:
                            printf("you chose option %d\n", choice);
                            break;
                        case 4:
                            printf("you chose option %d\n", choice);
                            break;
                        case 5:
                            printf("you chose option %d\n", choice);
                            break;
                        case 6:
                            printf("you chose option %d\n", choice);
                            break;
                        case 7:
                            printf("you chose option %d\n", choice);
                            break;
                        case 8:
                            printf("you chose option %d\n", choice);
                            break;
                        case 9:
                            printf("you chose option %d\n", choice);
                            break;
                        case 10:
                            keep_running = 0; // exit loop
                            break;
                    }
                    // ---------------- end switch cases ---------------------------
                }
                // valid format but not in menu range (0 or 11-99) — re-prompt silently
            } else {
                // invalid input (letters, symbols, etc.)
                error_count++;

                if (error_count >= 5) {
                    printf("Too many errors. Exiting...\n");
                    keep_running = 0;
                }
            }
        }
    } while (keep_running == 1);

    // TODO: Free any dynamically allocated here before exiting
    for (int i = 0; i < stock_count; i++)
        free(stocks[i]);
    free(stocks);

    return 0;
}

//---------------------------------------------------- Functions -------------------------------------------------------
// 0. Function that prints the main menu
void printMenu() {
    printf("=== Stock Management Menu ===\n");
    printf("1. Add Stock\n");
    printf("2. Print Stocks\n");
    printf("3. Double All Stocks Price\n");
    printf("4. Drop Stocks Price by x%%\n");
    printf("5. Find Less Expensive Stock\n");
    printf("6. Sort Stocks by Price\n");
    printf("7. Sort Stocks Alphabetically\n");
    printf("8. Sort Stocks by ASCII Sum of Names\n");
    printf("9. Check Palindromic Stock Names\n");
    printf("10. Exit\n");
    printf("Please enter a number between 0-99:\n");
}

// 1. Function that adds a stock to the 'stock file'
void addStock(Stock** stocks, int* ptr_stock_count) {
    // check if there is space in the static pointer array
    if (*ptr_stock_count >= MAX_STOCKS) {
        printf("The system is full\n");
        return;
    }

    // Allocate memory for a new stock structure on the heap
    stocks[*ptr_stock_count] = (Stock*)malloc(sizeof(Stock));
    if (stocks[*ptr_stock_count] == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    char input_buf[100];
    int valid = 0;

    //loop for valid stock name
    printf("Please enter the stock name: ");
    do {
        if (fgets(input_buf, sizeof(input_buf), stdin) != NULL) {
            // remove '\n' character that fgets() captures
            input_buf[strcspn(input_buf, "\n")] = '\0';

            if (isValidName(input_buf)) {
                // if yes, copies the name to the allocated stock structure
                strcpy(stocks[*ptr_stock_count]->name, input_buf);
                valid = 1;
            } else {
                printf("Invalid name, please try again: ");
            }
        }
    } while (!valid);

    // loop for valid stock price
    valid = 0;
    printf("Please enter the stock price: ");
    do {
        if (fgets(input_buf, sizeof(input_buf), stdin) != NULL) {
            /* call isValidPrice function to check the string
             * and to store the value in the struct if it is valid */
            if (isValidPrice(input_buf, &(stocks[*ptr_stock_count]->price))) {
                valid = 1;
                printf("Stock added\n");
            } else {
                printf("Invalid Price, please try again: ");
            }
        }
    } while (!valid);

    // everything is good, increment the count through the pointer
    (*ptr_stock_count)++;
}

// the function validates the stock name (assistant to 1.)
int isValidName(const char* str_buf) {
    int len = strlen(str_buf);
    if (len == 0 || len > 20)
        return 0;
    for (int i = 0; i < len; i++) {
        if (!((str_buf[i] >= 'a' && str_buf[i] <= 'z') ||
              (str_buf[i] >= 'A' && str_buf[i] <= 'Z')))
            return 0;
    }
    return 1;
}

/* validates if the inputted string is a valid positive integer.
 * if yes, it converts it and stores it in the price pointer and returns 1.
 * if no, returns 0 */
int isValidPrice(const char* str_buf, float* ptr_price) {
    int i = 0;
    int has_digits = 0;
    float result = 0.0f;

    while (str_buf[i] != '\0' && str_buf[i] != '\n') {
        if (str_buf[i] >= '0' && str_buf[i] <= '9') {
            has_digits = 1;
            result = result * 10.0f + (str_buf[i] - '0');
        } else {
            return 0;
        }
        i++;
    }

    if (has_digits == 0 || result <= 0.0f)
        return 0;

    *ptr_price = result;
    return 1;
}