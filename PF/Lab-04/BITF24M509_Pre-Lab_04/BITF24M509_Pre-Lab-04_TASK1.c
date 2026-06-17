#include <stdio.h>


int square(int x)
{
     return x*x;
}

int main()
{
    int num;
    printf("\nEnter a number to find its square: ");
    scanf("%d", &num);

    printf("\nSquare of the number is: %d\n", square(num));

    return 0;
}