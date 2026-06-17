#include<stdio.h>
int flag=0,num;
void isPrime(int n){
    if(n<=2)
    return ;
    if(num%n==0)
    flag++;
    else
    isPrime(n-1);
}
int main(){
    printf("enter n: ");
    scanf("%d",&num);
    isPrime(num/2);
    (flag==0)?printf("%d is a prime",num):printf("%d is not a prime",num);
    return 0;
}