#include <stdio.h>

int fibonacci(int n)
{
    if(n==0)
        return 0;
    else if (n == 1) 
        return 1;
    else 
        return fibonacci(n-1) + fibonacci(n-2);
}

int main()
{
    int n;
    printf("\nEnter the 'nth term' till you wanna print the fibonacci sequence within the given range (0 ≤ n ≤ 30): ");
    scanf("%d", &n);

    if (n>=0 && n<=30)
    {
        for (int i = 0; i <= n; i++) {
            printf("%d ", fibonacci(i));
        }
        printf("\n");  
    }
    else
    printf("Invalid input. Enter input within the specified range (0 to 30).\n");

    return 0;
}