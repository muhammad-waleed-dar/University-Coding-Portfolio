#include <stdio.h>

int main() {
    int n, sum = 0;

    // Get user input
    printf("Enter number: ");           // Error 1: Incorrect quotation mark in the original code
    scanf("%d", &n);                   // Error 2: Missing '&' before n in scanf()

    // Calculate sum 
    for (int i = 1; i <= n; i++) {
        sum += i;
    }

    if (sum % 2 == 0) {                // Error 3: Used '=' instead of '==' for comparison
        printf("The sum is even.\n");
    } else {
        printf("The sum is odd.\n");
    }

    printf("The sum of the first %d numbers is: %d\n", n, sum);

    return 0;
}
