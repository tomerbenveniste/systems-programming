#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stock.h"

// sorts the stocks by price
void sortByPrice(Stock** stocks, int stock_count) {

    // Allocate memory for a new stock structure on the heap
    Stock** helper = malloc(sizeof(Stock*) * stock_count);
    if (helper == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    // loop to copy all stocks to a helper array
    for (int i = 0; i < stock_count; i++) {
        helper[i] = stocks[i];
    }

    // loop that sorts the helper stocks array by price with bubble sort
    for (int i = 0; i < stock_count - 1; i++) {

        for (int j = 0; j < stock_count - 1 - i; j++) {

            if (helper[j]->price > helper[j+1]->price) {
                Stock* temp = helper[j]; // temporary pointer with current greater price
                helper[j] = helper[j+1]; // moving the cheaper stock one spot back
                helper[j+1] = temp; // bubbles forward the stock with higher price
            }
        }
    }

    // printing sorted helper array by price
    printStocks(helper, stock_count);
    printf("Sorted by price.\n");

    free(helper); // frees allocated memory
}