#include <stdio.h>
void FizzBuzz (int x)
{
        if (x%3==0 && x%5==0)
        printf("FizzBuzz\n");

        else if(x%3==0)
        printf("Fizz\n");

        else if(x%5==0)
        printf("Buzz\n");

        else
        printf("%d\n", x);
    
}
int main()
{
    int n;
    for(int n=1; n<=100; n++)
    {
    FizzBuzz(n);
    }
    return 0;
}