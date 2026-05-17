#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stock.h"

// 1. Function that adds a stock to the 'stock file'
void addStock(Stock** stocks, int* ptr_stock_count) {
    // check if there is space in the static pointer array
    if (*ptr_stock_count >= MAX_STOCKS) {
        printf("The system is full\n");
        return;
    }

    // Allocate memory for a new stock structure on the heap
    stocks[*ptr_stock_count] = (Stock*)malloc(sizeof(Stock));
    if (stocks[*ptr_stock_count] == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    char input_buf[100];
    int valid = 0;

    // loop for valid stock name
    printf("Enter stock name: ");
    do {
        if (fgets(input_buf, sizeof(input_buf), stdin) != NULL) {
            // remove '\n' character that fgets() captures
            input_buf[strcspn(input_buf, "\n")] = '\0';

            if (isValidName(input_buf)) {
                // if yes, copies the name to the allocated stock structure
                strcpy(stocks[*ptr_stock_count]->name, input_buf);
                valid = 1;
            } else {
                printf("Invalid name, please try again: ");
            }
        }
    } while (!valid);

    // loop for valid stock price
    valid = 0;
    printf("Enter stock price: ");
    do {
        if (fgets(input_buf, sizeof(input_buf), stdin) != NULL) {
            /* call isValidPrice function to check the string
             * and to store the value in the struct if it is valid */
            if (isValidPrice(input_buf, &(stocks[*ptr_stock_count]->price))) {
                valid = 1;
                printf("Stock added.\n");
            } else {
                printf("Invalid Price, please try again: ");
            }
        }
    } while (!valid);

    // everything is good, increment the count through the pointer
    (*ptr_stock_count)++;
}

// the function validates the stock name (assistant to 1.)
int isValidName(const char* str_buf) {
    int len = strlen(str_buf);
    if (len == 0 || len > 20)
        return 0;
    for (int i = 0; i < len; i++) {
        if (!((str_buf[i] >= 'a' && str_buf[i] <= 'z') ||
              (str_buf[i] >= 'A' && str_buf[i] <= 'Z')))
            return 0;
    }
    return 1;
}

/* validates if the inputted string is a valid positive integer.
 * if yes, it converts it and stores it in the price pointer and returns 1.
 * if no, returns 0 */
int isValidPrice(const char* str_buf, float* ptr_price) {
    int i = 0;
    int has_digits = 0;
    float result = 0.0f;

    while (str_buf[i] != '\0' && str_buf[i] != '\n') {
        if (str_buf[i] >= '0' && str_buf[i] <= '9') {
            has_digits = 1;
            result = result * 10.0f + (str_buf[i] - '0');
        } else {
            return 0;
        }
        i++;
    }

    if (has_digits == 0 || result <= 0.0f)
        return 0;

    *ptr_price = result;
    return 1;
}
