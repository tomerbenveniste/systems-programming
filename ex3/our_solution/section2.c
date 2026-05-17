#include <stdio.h>
#include "stock.h"

void printStocks(Stock** stocks, int* ptr_stock_count) {
    if (stocks == NULL || ptr_stock_count == NULL) {
        return;
    }

    if (*ptr_stock_count == 0) {
        printf("No stocks available.\n");
        return;
    }

    for (int i = 0; i < *ptr_stock_count; i++) {
        if (stocks[i] != NULL) {
            printf("%d. %s - $%.2f\n", i + 1, stocks[i]->name, stocks[i]->price);
        }
    }
}
