#include<stdio.h>
int main()
{
    int n, fact=1;

    printf("\nEnter a number to find 'FACTORIAL' of: ");
    scanf("%d", &n);

    // if (n==0)
    //     printf("\nFactorial of '0' : 1");
    if (n<0)
        printf("\nEnter a non-negative number to calculate factorial.");
    else
    {
      for (int i=1; i<=n; i++)
      {
        fact = fact * i;
      }
    printf("Factorial of '%d' : %d \n", n, fact);
    }

    return 0;
}