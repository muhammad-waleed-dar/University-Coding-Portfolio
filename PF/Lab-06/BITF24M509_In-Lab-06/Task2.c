#include <stdio.h>
#include <time.h>
int main()
{
   clock_t start, end;

    int arr[5];

    printf("\nEnter the elements of the array:\n");
    for (int i = 0; i < 5; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    start= clock();
    for(int i=0; i<5; i++)
    {
        for(int j=i+1; j<5; j++)
        {
           if(arr[i]>arr[j])
            {
                int temp= arr[i];
                arr[i]=arr[j];
                arr[j]=temp; 
            }
        }
    }
    end= clock();

    printf("\n\nAscending order: ");

    for(int i=0;i<5;i++){
        printf("%d ",arr[i]);
    }

    double time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\n\nThe execution time is: %lf seconds\n", time);

    return 0;

}