#include <stdio.h>

int sequence(int n, int k) {

    if(n <= k)
    return 1;

    int sum=0;
    for(int i=1; i<=k; i++)
    {
        sum = sum + sequence(n-i,k);
 
    }
    return sum;
}
int main()
{
    int n;
    printf("Enter value of 'n': ");
    scanf("%d", &n);
    int k;
    printf("Enter value of 'k': ");
    scanf("%d", &k);
    
    printf("The nth term of the sequence is: %d\n", sequence(n, k));

    return 0;
}