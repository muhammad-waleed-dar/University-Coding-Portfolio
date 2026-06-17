#include<stdio.h>
int main()
{
    int n, reverse=0;
    printf("Enter a number: ");
    scanf("%d",&n);

    int temp=n;

    while (n>0)
    { 
        int last_digit= n%10;
        reverse = reverse * 10 + last_digit;
        n=n/10;
    } 
    if (temp == reverse)
    printf("%d is a palindrome number. ", temp);
    else
    printf("%d is not a palindrome number. ", temp);

    return 0;
}