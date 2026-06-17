#include <stdio.h>

int factorial(int x)
{
    int fact=1;
     for(int i=1; i<=x; i++)
    {
       fact *= i;
    }
    return fact;
}

int main()
{
    int num;
    printf("\nEnter a number to find its factorial: ");
    scanf("%d", &num);

    if(num<0)
    printf("\nEnter a positive number!!!\n");
    else
    printf("\nFactorial of the number is: %d\n", factorial(num));

    return 0;
}