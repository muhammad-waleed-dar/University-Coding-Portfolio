#include <stdio.h>

int power(int a , int b) {
    if(b == 0)
    return 1;
    return a * power(a, b-1);
}
int main()
{
    int a;
    printf("Enter base: ");
    scanf("%d", &a);

    int b;
    printf("Enter exponent: ");
    scanf("%d", &b);
    
    printf("Result of %d raise to the power %d is: %d\n", a, b, power(a,b));

    return 0;
}