#include<stdio.h>
int main()
{
    int n, lastdigit, sum;
    printf("Enter a number: ");
    scanf("%d", &n);

    repeat:
    sum=0;
    while (n>0)
    { 
        lastdigit = n%10;
        sum=sum+lastdigit;
        n=n/10;
    }
    if (sum>=0 && sum<=9)
    printf("The sum of the digits of the number is: %d ", n); 
    else
    {
        n=sum;
    goto repeat;
    }

}