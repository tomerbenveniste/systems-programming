#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stock.h"

// the function finds the least expensive stock
void findLessExpensive(Stock** stocks, int stock_count) {

    int min_index = 0;
    for (int i = 1; i < stock_count; i++) {
        if (stocks[i]->price < stocks[min_index]->price) {
            min_index = i;
        }
    }

    printf("Less expensive stock: %s - $%.2f\n", stocks[min_index]->name, stocks[min_index]->price);
}