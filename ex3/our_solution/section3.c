#include <stdio.h>
#include "stock.h"

// Double the price of every stock in the array.
// If there are no stocks, print a message and return.
void doubleStocks(Stock** stocks, int stock_count) {
    // Guard against invalid pointers.
    if (stocks == NULL) {
        return;
    }

    // If the list is empty, there is nothing to double.
    if (stock_count == 0) {
        printf("No stocks available.\n");
        return;
    }

    for (int i = 0; i < stock_count; i++) {
        if (stocks[i] != NULL) {
            stocks[i]->price *= 2;
        }
    }
    printf("Stock prices have doubled.\n");
}
    