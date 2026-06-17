#include<stdio.h>
int main ()
{
    int n1,n2;
    char op;
    printf("\nEnter 1st number: ");
    scanf("%d", &n1);
    printf("Enter 2nd number: ");
    scanf("%d", &n2);
    printf("Enter an operator (+, -, *, /, %%) : ");
    scanf(" %c", &op);

    if (op == '+')
    printf("Addition: %d\n", n1+n2);
    
    else if (op == '-')
    printf("Subtraction: %d\n", n1-n2);

    else if (op == '*')
    printf("Multiplication: %d\n", n1*n2);

    else if (op == '/')
    {
    if (n2 != 0)  
        printf("Division: %.2f\n", (float)n1 / n2);
    else
        printf("Error: Division by zero is not allowed.\n");
    }
    
    else if (op == '%')
    {
    if (n2 != 0) 
        printf("Remainder: %d\n", n1 % n2);
    else
        printf("Error: Modulo by zero is not allowed.\n");
    }

    else
    printf("Invalid operator!!!\n");

    return 0;

}