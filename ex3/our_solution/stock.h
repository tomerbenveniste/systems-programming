#ifndef STOCK_H
#define STOCK_H

#include <stddef.h>

#define MAX_STOCKS 10

typedef struct {
    char name[21]; // 20 characters + '\0'
    float price;
} Stock;

void printMenu(void);
void addStock(Stock** stocks, int* ptr_stock_count);
void printStocks(Stock** stocks, int* ptr_stock_count);
void doubleStockPrices(Stock** stocks, int* ptr_stock_count);
int isValidName(const char* str_buf);
int isValidPrice(const char* str_buf, float* ptr_price);

#endif // STOCK_H
