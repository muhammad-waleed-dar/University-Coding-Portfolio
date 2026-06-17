#include<stdio.h>
void roman(int n){
    int result=0;
    while(n>0){
   if(n>=1000){
    printf("M");
    result=n-1000;
   }
   else if(n>=500){
    printf("D");
    result=n-500;
   }
   else if(n>=100){
    printf("C");
    result=n-100;
   }
   else if(n>=50){
    printf("L");
    result=n-50;
   }
   else if(n>=10){
    printf("X");
    result=n-10;
   }
   else if(n==9){
    printf("IX");
    result=n-9;
   }
   
   else if(n>=5){
    printf("V");
    result=n-5;
   }
   else if(n==4){
    printf("IV");
    result=n-4;
   }
   else if(n>=1){
    printf("I");
    result=n-1;
   }
   n=result;
   
}
   
   


}
int main(){
    int n;
    printf("Enter a number:");
    scanf("%d",&n);
    roman(n);

}