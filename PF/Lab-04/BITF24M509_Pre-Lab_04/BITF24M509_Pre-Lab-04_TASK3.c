#include <stdio.h>

char determineSign(int x)
{
    if(x>0) return 'P';
    if (x<0) return 'N';
    return 'Z';                                                                            
}

int main()
{
    int num;
    printf("\n Enter a number to find its sign: ");
    scanf("%d", &num);

    char result = determineSign(num);

    if (result == 'P')
        printf("\n %c   i.e., The number is Positive.\n", result);
    else if (result == 'N')
        printf("\n %c   i.e., The number is Negative.\n", result);
    else
        printf("\n %c   i.e., The number is Zero.\n", result);
    
    return 0;
}