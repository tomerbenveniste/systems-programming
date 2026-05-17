#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stock.h"

// Dropping x% off all the stocks
void dropStocks(Stock** stocks, int stock_count) {
    char input_buf[100];
    int percent;
    int valid = 0; // validation flag

    printf("Enter x%%: ");

    // Validation loop of the input
    do {
        if (fgets(input_buf, sizeof(input_buf), stdin) != NULL) {
            // call isValidPercent function to check the int
            if (isValidPercent(input_buf, &percent)) {
                valid = 1;
            } else {
                printf("Invalid Percentage, please try again: ");
            }
        }
    } while (!valid);

    // input was valid. now a loop that drops the percent value off every stock
    for (int j = 0; j < stock_count; j++) {
        // percentage calculation and updating the value at the price address
        stocks[j]->price *= (1.0f - percent / 100.0f);
    }

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