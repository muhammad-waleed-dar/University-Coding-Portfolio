#include<stdio.h>
int reverse=0;
int flag=0;
int Reverse(int n){
    if(n<=0)
    return reverse/10;
    int dig=n%10;
    reverse+=dig;
    reverse=(reverse*10);
    return Reverse(n/10);
}
int Palindrome(int n){
    if(n==Reverse(n))
        return 1;
    else
        return 0;
}
int main(){
    int n;
    printf("Enter a number:");
    scanf("%d",&n);
    printf("Reverse=%d",Reverse(n));//Reverse
    Palindrome(n)?printf("\n%d is a palindrome",n):printf("\n%d is not a palindrome",n);//Palindrome
}