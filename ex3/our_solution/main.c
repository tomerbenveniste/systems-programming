//---------------------------------------------- Libraries Imported ----------------------------------------------------
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stock.h"

//--------------------------------------------- Functions Declaration --------------------------------------------------
// 0. the menu print function
// (declared in stock.h)

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
                        case 1: 
                            addStock(stocks, &stock_count);
                            break;
                        case 2: 
                            printStocks(stocks, stock_count);
                            break;
                        case 3:
                            doubleStocks(stocks, stock_count);
                            break;
                        case 4:
                            dropStocks(stocks, stock_count);
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

