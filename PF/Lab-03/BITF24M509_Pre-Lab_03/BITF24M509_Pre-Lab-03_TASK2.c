#include <stdio.h>
int main()
{
    char first, sec;
   
    printf("Enter first letter: "); 
    scanf(" %c", &first);
    printf("Enter second letter: "); 
    scanf(" %c", &sec);  
    if(first < sec)
    {
    for (char i = first + 1; i < sec; i++)
    {
        if (i>='a' && i<='z')  // If input letter is in the lowercase, convert it to the uppercase
        printf("%c ", i-32);  
        else                   // Already uppercase letter, print as it is
        printf("%c ", i);
    }
    }
    else
    printf("Enter first letter smaller than the second letter. ");
    
    return 0;
}