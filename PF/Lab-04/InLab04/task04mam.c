#include <stdio.h>

void convertToRoman(int num) {
    printf("Roman numeral: ");

    while (num >= 1000) { printf("M"); num -= 1000; }  // 1000 → M
    while (num >= 500)  { printf("D"); num -= 500; }   // 500 → D
    while (num >= 100)  { printf("C"); num -= 100; }   // 100 → C
    while (num >= 50)   { printf("L"); num -= 50; }    // 50 → L
    while (num >= 10)   { printf("X"); num -= 10; }    // 10 → X
    while (num >= 5)    { printf("V"); num -= 5; }     // 5 → V
    while (num >= 1)    { printf("I"); num -= 1; }     // 1 → I

    printf("\n");
}

int main() {
    int number;
    printf("Enter a number (1-3999): ");
    scanf("%d", &number);

    if (number < 1 || number > 3999) {
        printf("Invalid input! Please enter a number between 1 and 3999.\n");
    } else {
        convertToRoman(number);
    }

    return 0;
}
