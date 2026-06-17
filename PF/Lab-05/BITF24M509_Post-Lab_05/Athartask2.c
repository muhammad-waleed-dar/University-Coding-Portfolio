#include <stdio.h>
int f1=0,f2=0,f3=0,f4=0,f5=0,f6=0,f7=0,f8=0,f9=0;
long long count=1;  //Initially, it was int. Now works for large no.s
long long digits=0; //Initially, it was int
long long p=1; //Initially, it was int
void prod_digs(long long n){   //Initially, it was int
    if(n<=0)
        return;
    int dig=n%10;
    if(dig==1)
    f1++;
    else if(dig==2)
    f2++;
    else if(dig==3)
    f3++;
    else if(dig==4)
    f4++;
    else if(dig==5)
    f5++;
    else if(dig==6)
    f6++;
    else if(dig==7)
    f7++;
    else if(dig==8)
    f8++;
    else if(dig==9)
    f9++;
    prod_digs(n/10); 
}
void final_product(){
    if(f1>0)
    { 
    p*=1;
    digits++;
    }
     if(f2>0)
    {p*=2;
    digits++;}
     if(f3>0)
    {p*=3;
    digits++;}
     if(f4>0)
    {p*=4;
    digits++;}
     if(f5>0)
    {p*=5;
    digits++;}
     if(f6>0)
    {p*=6;
    digits++;}
     if(f7>0)
    {p*=7;
    digits++;}
     if(f8>0)
    {p*=8;
    digits++;}
     if(f9>0)
   { p*=9;
    digits++;}
    return;
}
int main() {
    long long prod;  //Initially, it was int
    long long n;     //Initially, it was int
    printf("Enter a number: ");
    scanf("%lld", &n);   //Initially, it was int
    prod_digs(n);
    final_product();
    printf("%lld",p);    //Initially, it was int
    printf("\n%lld",digits);   //Initially, it was int
      return 0;
}