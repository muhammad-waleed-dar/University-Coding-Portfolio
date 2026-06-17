#include <stdio.h>

void convertToRoman(int num) {
    if (num < 1 || num > 3999) {
        printf("Please enter a number between 1 and 3999.\n");
        return;
    }

    printf("Roman numeral: ");

    if (num >= 1000) { printf("M"); num -= 1000; }
    if (num >= 1000) { printf("M"); num -= 1000; }
    if (num >= 1000) { printf("M"); num -= 1000; }

    if (num >= 900) { printf("CM"); num -= 900; }
    if (num >= 500) { printf("D"); num -= 500; }
    if (num >= 400) { printf("CD"); num -= 400; }
    
    if (num >= 100) { printf("C"); num -= 100; }
    if (num >= 100) { printf("C"); num -= 100; }
    if (num >= 100) { printf("C"); num -= 100; }

    if (num >= 90) { printf("XC"); num -= 90; }
    if (num >= 50) { printf("L"); num -= 50; }
    if (num >= 40) { printf("XL"); num -= 40; }
    
    if (num >= 10) { printf("X"); num -= 10; }
    if (num >= 10) { printf("X"); num -= 10; }
    if (num >= 10) { printf("X"); num -= 10; }

    if (num >= 9) { printf("IX"); num -= 9; }
    if (num >= 5) { printf("V"); num -= 5; }
    if (num >= 4) { printf("IV"); num -= 4; }
    
    if (num >= 1) { printf("I"); num -= 1; }
    if (num >= 1) { printf("I"); num -= 1; }
    if (num >= 1) { printf("I"); num -= 1; }

    printf("\n");
}

int main() {
    int number;
    printf("Enter a number (1-3999): ");
    scanf("%d", &number);
    convertToRoman(number);
    return 0;
}
