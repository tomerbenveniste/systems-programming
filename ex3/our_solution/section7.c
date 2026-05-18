#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stock.h"

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
    printf("Sorted by name.\n");
}
