#include <stdio.h>

void descendingSort(int arr[], int size)
{
    for(int i=0; i<size; i++)
    {
        for(int j=i+1; j<size; j++)
        {
           if(arr[i]<arr[j])
            {
                int temp= arr[i];
                arr[i]= arr[j];
                arr[j]= temp; 
            }
        }
    }

    printf("\n\nSorted array in descending order: ");
    for(int i=0; i<size; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int main()
{
    // Input for size
    int size;
    printf("\nEnter the size of the array: ");
    scanf("%d", &size);


    if (size <= 0) {
        printf("\nInvalid array size. Please enter a positive integer.\n");
        return 1; // Exit 
    }

    int arr[size];

    // Input for array elements
    printf("\nEnter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    descendingSort(arr, size);

    return 0;

}