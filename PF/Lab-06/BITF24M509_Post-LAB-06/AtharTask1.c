#include<stdio.h>
#include<math.h>
int main()
{
    int size;
    printf("Enter the size of array: ");
    scanf("%d",&size);
    int array[size];
    float array1[size];
    printf("Enter the elements of array:\n");
    for(int i=0;i<size;i++){
        scanf("%d",&array[i]);
    }
    for(int j=0;j<size;j++){
        if(array[j] % 2 == 0)
        array1[j]=sqrt(array[j]);
        else
        array1[j]=pow(array[j],2);
    }
    printf("Transformed Array: \n");
    for(int k=0;k<size;k++){
        printf("%.3f  ",array1[k]);
    }
}