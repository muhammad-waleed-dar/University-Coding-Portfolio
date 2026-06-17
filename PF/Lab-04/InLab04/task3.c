#include<stdio.h>
void convert(float x)
{
    float mins,hours;
    mins= (x)/(60);
    hours= (x)/(3600);
    printf("\nSeconds to minutes is: %f\n", mins);
    printf("\nSeconds to hours is: %f\n", hours);

}

int main()
{
   float sec;

   printf("Enter no. of seconds: ");
   scanf("%f", &sec);

   if (sec<=86400)
   convert(sec);
   else
   printf("Error");

   return 0;
}