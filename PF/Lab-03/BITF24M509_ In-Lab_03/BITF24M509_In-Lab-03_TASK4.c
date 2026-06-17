#include<stdio.h>
int main()
{
    int n, last_digit, sum;
    printf("\nEnter a number: ");
    scanf("%d", &n);

    while(n>=10)
    {
        sum=0;  //v.imp
    while (n>0)
    { 
        last_digit = n%10;
        sum= sum + last_digit;
        n=n/10;
    }
    n=sum;   //v.imp
    }

    printf("(Final single-digit sum) of the number is: %d \n", n); // 'n' is being printed

    return 0;
}