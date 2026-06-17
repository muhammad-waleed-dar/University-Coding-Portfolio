#include <stdio.h>
int main()
{

    int arr[5];

    printf("\nEnter the elements of the array:\n");
    for (int i = 0; i < 5; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    for(int i=0; i<5; i++)
    {
        for(int j=i+1; j<5; j++)
        {
           if(arr[i]>arr[j])
            {
                int result= arr[i];
                arr[i]=arr[j];
                arr[j]=result; 
            }
        }
    }

        printf("%d ",arr[1]);

    return 0;

}