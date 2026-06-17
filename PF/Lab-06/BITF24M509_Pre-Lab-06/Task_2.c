#include <stdio.h>

int main()
{
    // Input for the size
    int size;
    printf("\nEnter the size of the array: ");
    scanf("%d", &size);

    // Input validation
    if (size <= 0) {
        printf("\nInvalid array size. Please enter a positive integer.\n");
        return 1; // Exit program
    }

    int arr[size];
    
    // Input for the array elements
    printf("\nEnter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // Display original array
    printf("\nOriginal array: ");
    for(int i=0; i<size; i++)
    {
        printf("%d ", arr[i]);
    }

    // Modify array as per requirements
    printf("\n\nModified array: ");
    for(int i=0; i<size; i++)
    {
        if(arr[i]%2==0)
        printf("%d ", arr[i]/3);
        else
        printf("%d ",i);
    }
    printf("\n");

    return 0;
}