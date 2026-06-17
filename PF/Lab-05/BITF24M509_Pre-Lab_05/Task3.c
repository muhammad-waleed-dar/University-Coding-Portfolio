#include <stdio.h>

int factorial(int n)
{
    if(n==0)
    return 1;

    return n * factorial(n - 1);
}

int main()
{
    int n;
    printf("\nEnter a positive integer 'n' to find factorial of: ");
    scanf("%d", &n);

    if (n>=0)
        printf("The factorial of %d is: %d\n", n, factorial(n));
    else
    printf("Invalid input. Enter a non-negative number.\n");

    return 0;
}