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

    printf("\n\nLeader elements in the array:\n");

    int isLeader;

    // Print leader element (s)
    for(int i=0; i<size; i++)
    { 
        isLeader = 1;

    for(int j=i+1; j<size; j++){
        if(arr[i]<=arr[j])
        {
            isLeader = 0;
            break; 
        }
    }
        if(isLeader)
        printf("%d\n", arr[i]);
    }
   
    printf("\n");

    return 0;
}