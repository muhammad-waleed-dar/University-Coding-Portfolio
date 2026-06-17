#include<stdio.h>
int main()
{
    char first,last;
    printf("enter the first character: \n");
    scanf("%d",&first);
    printf("\nenter the last character: \n");
    scanf("%d",&last);
    if(first>=65&&first<=90&&last>=65&&last<=90&&first<last){
    printf("\nThe characters between %c and %c are:",first,last);
    for(char c=first+1;c<last;c++){
        printf("%c\n",c);
    }
}
    else{
        printf("\nEnter capital letters only or enter them in alphabetical order");
    }
}