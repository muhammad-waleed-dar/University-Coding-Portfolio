#include <stdio.h>

int isPrime(int n, int i) {
        if(n<=1)   // 1 is not a prime number and number less than it
            return 0;
        if(i==1)
            return 1;
        if(n%i==0)
            return 0;

        return isPrime(n, i-1);
}
int main()
{
    int n;
    printf("Enter a number to check if it's prime: ");
    scanf("%d", &n);
    
    if( isPrime(n, n/2) )
         printf("Input number is a prime number.\n");
    else
         printf("Input number is not a prime number.\n");

    return 0;
}