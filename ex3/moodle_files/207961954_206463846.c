#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STOCKS 10


// Struct definition - Do not change the name or the fields
typedef struct {
    char name[21];
    float price;
} Stock;

// ==========================================
// Function Prototypes - MUST be implemented exactly as defined
// ==========================================

void printMenu();
void addStock(Stock** stocks, int* ptr_stock_count);
int isValidName(const char* str_buf);
int isValidPrice(const char* str_buf, float* ptr_price);
void printStocks(Stock** stocks, int stock_count);
void doubleStocks(Stock** stocks, int stock_count);
void dropStocks(Stock** stocks, int stock_count);
int isValidPercent(const char* str_buf, int* ptr_percent);
void sortByPrice(Stock** stocks, int stock_count);
void sortByName(Stock** stocks, int stock_count);
void sortByAsciiSum(Stock** stocks, int stock_count);
int asciiSum(const char* str);
void findLessExpensive(Stock** stocks, int stock_count);
void findPalindromes(Stock** stocks, int stock_count);
int isPalindrome(const char* str);

// ==========================================
// Main Program
// ==========================================

int main() {


    int stock_count = 0;
    Stock** stocks = malloc(MAX_STOCKS * sizeof(Stock*));

    int error_count = 0;
    int choice = -1;
    int reprint_menu = 1;
    char input_buffer[100];

    // Flag to manage the loop execution state
    int keep_running = 1;

    // The main loop
    do {
        if (reprint_menu) {
            printMenu();
        }
        reprint_menu = 1; // reset - assuming a valid input
        
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
                            if (stock_count == 0) {
                                printf("Must add a stock first\n");
                                printf("Please enter a number between 0-99: \n");
                                reprint_menu = 0;
                            } else {
                                printStocks(stocks, stock_count);
                            }
                            break;
                        case 3:
                            if (stock_count == 0) {
                                printf("Must add a stock first\n");
                                printf("Please enter a number between 0-99: ");
                                reprint_menu = 0;
                            } else {
                                doubleStocks(stocks, stock_count);
                            }
                            break;
                        case 4:
                            if (stock_count == 0) {
                                printf("Must add a stock first\n");
                                printf("Please enter a number between 0-99: ");
                                reprint_menu = 0;
                            } else {
                                dropStocks(stocks, stock_count);
                            }
                            break;
                        case 5:
                            if (stock_count == 0) {
                                printf("Must add a stock first\n");
                                printf("Please enter a number between 0-99: ");
                                reprint_menu = 0;
                            } else {
                                findLessExpensive(stocks, stock_count);
                            }
                            break;
                        case 6:
                            if (stock_count == 0) {
                                printf("Must add a stock first\n");
                                printf("Please enter a number between 0-99: ");
                                reprint_menu = 0;
                            } else {
                                sortByPrice(stocks, stock_count);
                            }
                            break;
                        case 7:
                            if (stock_count == 0) {
                                printf("Must add a stock first\n");
                                printf("Please enter a number between 0-99: ");
                                reprint_menu = 0;
                            } else {
                                sortByName(stocks, stock_count);
                            }
                            break;
                        case 8:
                            if (stock_count == 0) {
                                printf("Must add a stock first\n");
                                printf("Please enter a number between 0-99: ");
                                reprint_menu = 0;
                            } else {
                                sortByAsciiSum(stocks, stock_count);
                
                            }
                            break;
                        case 9:
                            if (stock_count == 0) {
                                printf("Must add a stock first\n");
                                printf("Please enter a number between 0-99: ");
                                reprint_menu = 0;
                            } else {
                                findPalindromes(stocks, stock_count);
                            }
                            break;
                        case 10:
                            keep_running = 0; // exit loop
                            printf("\nExiting program...\n");
                            break;
                    }
                    // ---------------- end switch cases ---------------------------
                }

            // valid format but not in menu range (0 or 11-99) — re-prompt silently
            } else {

                // invalid input (letters, symbols, etc.)
                error_count++;
                printf("\n");
                printf("Invalid input.\n");
                printf("You made %d errors from 5, try again.\n", error_count);
                printf("Please enter a number between 0-99: ");
                reprint_menu = 0; // skip full menu in the next iteration

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

// ==========================================
// Function Implementations
// ==========================================

void printMenu() {
    printf("\n");
    printf("=== Stock Management Menu ===\n");
    printf("1. Add Stock\n");
    printf("2. Print Stocks\n");
    printf("3. Double All Stocks Price\n");
    printf("4. Drop Stocks Price by x%%\n");
    printf("5. Find Less Expensive Stock\n");
    printf("6. Sort Stocks by Price\n");
    printf("7. Sort Stocks Alphabetically\n");
    printf("8. Sort Stocks by ASCII Sum of Name\n");
    printf("9. Check Palindromic Stock Names\n");
    printf("10. Exit\n");
    printf("Please enter a number between 0-99: ");

}

void addStock(Stock** stocks, int* ptr_stock_count) {
    // check if there is space in the static pointer array
    if (*ptr_stock_count >= MAX_STOCKS) {
        printf("\n");
        printf("The system is full\n");
        return;
    }

    // Allocate memory for a new stock structure on the heap
    stocks[*ptr_stock_count] = (Stock*)malloc(sizeof(Stock));
    if (stocks[*ptr_stock_count] == NULL) {
        printf("\n");
        printf("Memory allocation failed!\n");
        return;
    }

    char input_buf[100];
    int valid = 0;

    // loop for valid stock name
    printf("\n");
    printf("Enter stock name: ");
    do {
        if (fgets(input_buf, sizeof(input_buf), stdin) != NULL) {
            // remove '\n' character that fgets() captures
            input_buf[strcspn(input_buf, "\n")] = '\0';

            if (isValidName(input_buf)) {
                // if yes, copies the name to the allocated stock structure
                strcpy(stocks[*ptr_stock_count]->name, input_buf);
                valid = 1;
            } else {
                printf("\n");
                printf("Invalid name, please try again:");
            }
        }
    } while (!valid);
    printf("\n");

    // loop for valid stock price
    valid = 0;
    printf("Enter stock price: ");
    do {
        if (fgets(input_buf, sizeof(input_buf), stdin) != NULL) {
            /* call isValidPrice function to check the string
             * and to store the value in the struct if it is valid */
            if (isValidPrice(input_buf, &(stocks[*ptr_stock_count]->price))) {
                valid = 1;
                printf("\n");
                printf("Stock added.");
                printf("\n");

            } else {
                printf("\n");
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


void printStocks(Stock** stocks, int stock_count) {
    if (stocks == NULL) {
        return;
    }

    if (stock_count == 0) {
        printf("\n");
        printf("No stocks available.\n");
        return;
    }
    printf("\n");
    for (int i = 0; i < stock_count; i++) {
        if (stocks[i] != NULL) {
            printf("%d. %s - $%.2f\n", i + 1, stocks[i]->name, stocks[i]->price);
        }
    }
}

void doubleStocks(Stock** stocks, int stock_count) {
    // Guard against invalid pointers.
    if (stocks == NULL) {
        return;
    }

    // If the list is empty, there is nothing to double.
    if (stock_count == 0) {
        printf("\n");
        printf("No stocks available.\n");
        return;
    }

    for (int i = 0; i < stock_count; i++) {
        if (stocks[i] != NULL) {
            stocks[i]->price *= 2;
        }
    }
    printf("\n");
    printf("Stock prices have doubled.\n");
}

// Dropping x% off all the stocks
void dropStocks(Stock** stocks, int stock_count) {
    char input_buf[100];
    int percent;
    int valid = 0; // validation flag
    printf("\n");
    printf("Enter x%%: ");

    // Validation loop of the input
    do {
        if (fgets(input_buf, sizeof(input_buf), stdin) != NULL) {
            // call isValidPercent function to check the int
            if (isValidPercent(input_buf, &percent)) {
                valid = 1;
            } else {
                printf("\n");
                printf("Invalid Percentage, please try again:");
            }
        }
    } while (!valid);

    // input was valid. now a loop that drops the percent value off every stock
    for (int j = 0; j < stock_count; j++) {
        // percentage calculation and updating the value at the price address
        stocks[j]->price *= (1.0f - percent / 100.0f);
    }
    printf("\n");
    printf("Stock prices has dropped by %d%%.\n", percent);
}

// Validate the %-drop input for dropStocks function
int isValidPercent(const char* str_buf, int* ptr_percent) {
    int i = 0;
    int has_digits = 0;
    int result = 0;

    while (str_buf[i] != '\0' && str_buf[i] != '\n') {
        if (str_buf[i] >= '0' && str_buf[i] <= '9') {
            has_digits = 1;
            result = result * 10 + (str_buf[i] - '0');
        } else {
            return 0;
        }
        i++;
    }

    if (has_digits == 0 || result > 100)
        return 0;

    *ptr_percent = result;
    return 1;
}

// the function finds the least expensive stock
void findLessExpensive(Stock** stocks, int stock_count) {

    int min_index = 0;
    for (int i = 1; i < stock_count; i++) {
        if (stocks[i]->price < stocks[min_index]->price) {
            min_index = i;
        }
    }
    printf("\n");
    printf("Less expensive stock: %s - $%.2f\n", stocks[min_index]->name, stocks[min_index]->price);
}
// sorts the stocks by price
void sortByPrice(Stock** stocks, int stock_count) {

    // loop that sorts the helper stocks array by price with bubble sort
    for (int i = 0; i < stock_count - 1; i++) {

        for (int j = 0; j < stock_count - 1 - i; j++) {

            if (stocks[j]->price > stocks[j+1]->price) {
                Stock* temp = stocks[j]; // temporary pointer with current greater price
                stocks[j] = stocks[j+1]; // moving the cheaper stock one spot back
                stocks[j+1] = temp; // bubbles forward the stock with higher price
            }
        }
    }
    printf("\n");
    printf("Sorted by price.\n");
}
void sortByName(Stock** stocks, int stock_count) {

    // loop that sorts the helper stocks array by price with bubble sort
    for (int i = 0; i < stock_count - 1; i++) {

        for (int j = 0; j < stock_count - 1 - i; j++) {

            if (strcmp(stocks[j]->name, stocks[j+1]->name) > 0) {
                Stock* temp = stocks[j]; // temporary pointer with current greater price
                stocks[j] = stocks[j+1]; // moving the cheaper stock one spot back
                stocks[j+1] = temp; // bubbles forward the stock with higher price
            }
        }
    }
    printf("\n");
    printf("Sorted by name.\n");
}

// sorts the stocks by the sum of the ASCII values of their names
void sortByAsciiSum(Stock** stocks, int stock_count)
{
    // loop that sorts the helper stocks array by ASCII sum with bubble sort
    for (int i = 0; i < stock_count - 1; i++)
    {
        for (int j = 0; j < stock_count - 1 - i; j++)
        {
            //if the sum of the ASCII values of the name of the stock at index j is greater than that of the stock at index j+1, swap them
            if (asciiSum(stocks[j]->name) > asciiSum(stocks[j + 1]->name))
            {
                Stock* temp = stocks[j];
                stocks[j] = stocks[j + 1];
                stocks[j + 1] = temp;
            }
        }
    }
    printf("\n");
    printf("Sorted by ASCII sum.\n");
}
// calculates the sum of the ASCII values of the characters in a string
int asciiSum(const char* str)
{
    int sum = 0;

    for (int i = 0; str[i] != '\0'; i++)
    {
        sum += str[i];
    }

    return sum;
}

// finds and prints the stocks with palindromic names
void findPalindromes(Stock** stocks, int stock_count)
{
    int found = 0;

    for (int i = 0; i < stock_count; i++)
    {
        if (isPalindrome(stocks[i]->name))
        {
            printf("\n");
            printf("Palindrome stock: %s\n", stocks[i]->name);
            found = 1;
        }
    }
   
    if (!found)
    {
        printf("\n");
        printf("No palindromic stock names found.\n");
    }
}
// checks if a string is a palindrome
int isPalindrome(const char* str)
{
    int left = 0;
    int right = strlen(str) - 1;

    while (left < right)
    {
        if (str[left] != str[right])
        {
            return 0;
        }

        left++;
        right--;
    }

    return 1;
}