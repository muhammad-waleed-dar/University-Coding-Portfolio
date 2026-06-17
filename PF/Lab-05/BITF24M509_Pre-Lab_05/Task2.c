#include <stdio.h>

int sumFromNtoZero(int n)
{
    if(n == 0)
        return 0;
    else 
        return n + sumFromNtoZero(n - 1);
}

int main()
{
    int n;
    printf("\nEnter a positive integer 'n' within the given range (1 ≤ n ≤ 1000): ");
    scanf("%d", &n);

    if (n>=1 && n<=1000)
        printf("The sum of numbers from %d to 0 is: %d\n", n, sumFromNtoZero(n));
    else
    printf("Invalid input. Enter input within the specified range (1 to 1000).\n");

    return 0;
}