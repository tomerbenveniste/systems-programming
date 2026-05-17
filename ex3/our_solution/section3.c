#include <stdio.h>
#include "stock.h"

void doubleStockPrices(Stock** stocks, int* ptr_stock_count) {
    if (stocks == NULL || ptr_stock_count == NULL) {
        return;
    }

    if (*ptr_stock_count == 0) {
        printf("No stocks available.\n");
        return;
    }

    for (int i = 0; i < *ptr_stock_count; i++) {
        if (stocks[i] != NULL) {
            stocks[i]->price *= 2;
            printf("Stock price doubled\n");
        }
    }
}
    