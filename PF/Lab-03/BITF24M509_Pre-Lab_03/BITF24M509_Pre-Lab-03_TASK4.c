#include<stdio.h>
int main()
{
    int n, sum=0, counter=0;
    printf("Enter a number: ");
    scanf("%d",&n);

    int temp = n;

    while (temp>0)
    { 
        counter++;
        temp /= 10;
    }

    temp= n;
  
    while (temp>0)
    {   
        int last_digit = temp % 10;
        int power = 1;

    for(int i = 1; i <= counter; i++)
    { 
        power *= last_digit;
    }

    sum += power;
    temp /= 10;
    }

    if (n == sum)
    printf("%d is an Armstrong number. ", n);
    else
    printf("%d is not an Armstrong number. ", n);

    return 0;
}