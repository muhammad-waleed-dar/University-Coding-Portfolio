#include<stdio.h>
int main()
{
    int n1,n2,n3;

    printf("\nEnter 1st number: ");
    scanf("%d", &n1);
    printf("\nEnter 2nd number: ");
    scanf("%d", &n2);
    printf("\nEnter 3rd number: ");
    scanf("%d", &n3);

    if (n1>n2 && n1>n3)
        printf("\nThe largest number among the three is: %d \n", n1);
    else if (n2>n1 && n2>n3)
        printf("\nThe largest number among the three is: %d \n", n2);
    else
    printf("\nThe largest number among the three is: %d \n", n3);

    return 0;
}