#include <stdio.h>
#include "stock.h"

int asciiSum(const char* str) {
    int sum = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        sum += str[i];
    }
    return sum;
}

void sortByAsciiSum(Stock** stocks, int stock_count) {
    for (int i = 0; i < stock_count - 1; i++) {
        for (int j = 0; j < stock_count - 1 - i; j++) {
            if (asciiSum(stocks[j]->name) > asciiSum(stocks[j + 1]->name)) {
                Stock* temp = stocks[j];
                stocks[j] = stocks[j + 1];
                stocks[j + 1] = temp;
            }
        }
    }
    printf("\n");
    printf("Sorted by ASCII sum.\n");
}
