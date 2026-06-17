#include <stdio.h>

int a,b;

void swap()
{
    a = a-b;
    b = a+b;
    a = b-a;
    printf("\nAfter Swapping: \n");
    printf("1st number: %d\n",a);
    printf("2nd number: %d\n",b);
}

int main()
{

    printf("\nBefore Swapping: \n");
    printf("Enter value of 1st number: ");
    scanf("%d", &a);
    printf("Enter value of 2nd number: ");
    scanf("%d", &b);

    swap();

    return 0;
}