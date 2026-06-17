#include<stdio.h>
int main()
{
    int side, area;

    printf("\nEnter the side length of the square: ");
    scanf("%d", &side);

    area= side * side;

    printf("Area of the square is: %d sq.units\n", area);

    return 0;
}