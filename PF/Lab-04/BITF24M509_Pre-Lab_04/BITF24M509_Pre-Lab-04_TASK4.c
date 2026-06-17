#include <stdio.h>
//In Task 4 statement, it's not the requirement to print output in the main(). So, I directly printed in checkVowel() function.
void checkVowel(char x)
{
    if ((x >= 'A' && x <= 'Z') || (x >= 'a' && x <= 'z')) 
    {
    if(x=='A' || x=='a' || x=='E' || x=='e' || x=='I' || x=='i' || x=='O' || x=='o' || x=='U' || x=='u')
    {
        printf("\n A Vowel character\n");
    } 
    else 
    {
        printf("\n A Consonant character\n");
    } 
    } 
    else 
    {
        printf("\n Invalid input! Please enter an alphabetic character.\n");
    }                                                          
}

int main()
{
    char ch;
    printf("\n Enter a character: ");
    scanf(" %c", &ch);

    checkVowel(ch);
    
    return 0;
}