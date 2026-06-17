#include <stdio.h>

int sumOfDigits(int n, int sum) {
        if (n == 0)
            return sum;
        return sumOfDigits( n / 10, sum + (n % 10) );
}
int main()
{
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    
    printf("Sum of digits: %d\n", sumOfDigits(n, 0));

    return 0;
}