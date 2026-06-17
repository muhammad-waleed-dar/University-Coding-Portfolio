#include <stdio.h>

long long count = 0, product = 1, checkedDigits = 0;  

// Recursive function to check if a digit has already been processed
int isDigitUsed(long long checked, int digit) {
    if (checked == 0)
        return 0;  // Base case: No digits checked yet
    if (checked % 10 == digit)
        return 1;  // Digit is already used
    return isDigitUsed(checked / 10, digit);  // Recursive call to check next digit
}

// Recursive function to count and compute product of unique digits (excluding 0)
void analyzeUniqueDigits(long long n) {
    if (n == 0)
        return;  // Base case: Stop when all digits are processed

    int last_digit = n % 10;

    if (last_digit != 0 && !isDigitUsed(checkedDigits, last_digit)) {
        count++;  // Increment unique digit count
        product *= last_digit;  // Multiply unique digit to product
        checkedDigits = checkedDigits * 10 + last_digit;  // Store the checked digit
    }

    analyzeUniqueDigits(n / 10);  // Recursive call for remaining digits
}

int main() {
    long long n;
    printf("Enter a number: ");
    scanf("%lld", &n);

    analyzeUniqueDigits(n);

    printf("Number of unique digits (excluding 0): %lld\n", count);
    printf("Product of unique digits (excluding 0): %lld\n", product);

    return 0;
}
