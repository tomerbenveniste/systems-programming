#ifndef STOCK_H
#define STOCK_H

// stock.h
// Shared definitions for the stock management program.
// This header declares the Stock data type and the functions used
// by the application modules for menu display, adding stocks,
// printing stocks, price updates, and validation.

#include <stddef.h>

#define MAX_STOCKS 10

// Stock record contains a name and a price value.
typedef struct {
    char name[21]; // 20 characters + '\0'
    float price;
} Stock;

// Print the menu options to stdout.
void printMenu(void);

// Add a new stock entry to the stocks array.
void addStock(Stock** stocks, int* ptr_stock_count);

// Print all stored stock entries.
void printStocks(Stock** stocks, int stock_count);

// Double the price of every stored stock.
void doubleStocks(Stock** stocks, int stock_count);

// Validate a stock name string.
int isValidName(const char* str_buf);

// Validate a price string and convert it to float.
int isValidPrice(const char* str_buf, float* ptr_price);

// Dropping x% off all the stocks
void dropStocks(Stock** stocks, int stock_count);

// Validate the % drop input for dropStocks function
int isValidPercent(const char* str_buf, int* ptr_percent);

#endif // STOCK_H
