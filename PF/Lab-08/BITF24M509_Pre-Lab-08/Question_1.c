#include <stdio.h>

void reverseArray(int arr[], int size) {
    int start= 0;       
    int end= size-1;                  
    while (start < end)      
    {
     int temp= arr[start];  
     arr[start]= arr[end];  
     arr[end]= temp;
     start++;           
     end--;          
    } 
}

void displayArray(int arr[], int size) {
    printf("\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int size;
    printf("\nEnter the size of the array: ");
    scanf("%d", &size);

    if (size <= 0) {
        printf("\nInvalid array size. Please enter a positive integer.\n");
        return 1;
    }

    int arr[size];

    printf("\nEnter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("\nOriginal array:\n");
    displayArray(arr, size);
    
    reverseArray(arr, size); 

    printf("\nReversed array:\n");
    displayArray(arr, size);

    return 0;
}