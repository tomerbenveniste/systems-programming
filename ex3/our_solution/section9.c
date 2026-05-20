#include <stdio.h>
#include <string.h>
#include "stock.h"

int isPalindrome(const char* str) {
    int left = 0;
    int right = strlen(str) - 1;
    while (left < right) {
        if (str[left] != str[right]) {
            return 0;
        }
        left++;
        right--;
    }
    return 1;
}

void findPalindromes(Stock** stocks, int stock_count) {
    int found = 0;
    for (int i = 0; i < stock_count; i++) {
        if (isPalindrome(stocks[i]->name)) {
            printf("\n");
            printf("Palindrome stock: %s\n", stocks[i]->name);
            found = 1;
        }
    }
    if (!found) {
        printf("\n");
        printf("No palindromic stock names found.\n");
    }
}
