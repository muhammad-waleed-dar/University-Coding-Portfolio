#include <stdio.h>

// Recursive function to check if a digit has already been counted
int isDigitUsed(int num, int digit) {
    if (num == 0) 
        return 0;  // Base case: No more digits left to check
    if (num % 10 == digit) 
        return 1;  // Digit is found
    return isDigitUsed(num / 10, digit);  // Recursive call to check next digit
}

// Recursive function to count unique digits excluding 0
int countUniqueDigits(int n, int checked, int count) {
    if (n == 0)
        return count;  // Base case: return count when all digits are processed

    int last_digit = n % 10;

    // If digit is not 0 and has not been counted yet
    if (last_digit != 0 && !isDigitUsed(checked, last_digit)) {
        count++;  // Increment count
        checked = checked * 10 + last_digit;  // Store checked digit
    }

    return countUniqueDigits(n / 10, checked, count);  // Process remaining digits
}

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    printf("Unique digit count (excluding 0): %d\n", countUniqueDigits(n, 0, 0));

    return 0;
}
