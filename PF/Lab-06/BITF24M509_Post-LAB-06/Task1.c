#include <stdio.h>
#include <math.h>

// Function
void transformArray(double arr[], int size) {
    for(int i=0; i<size; i++)
    {
        if((int)arr[i]%2==0)
        {
        arr[i]=sqrt(arr[i]);
        printf("%.3lf          ", arr[i]);
        }
        else
        {
        arr[i]=arr[i]*arr[i];
        printf("%.0lf          ", arr[i]);
        }
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

    double arr[size];
    
    // Input for array elements
    printf("\nEnter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        printf("Element %d: ", i + 1);
        scanf("%lf", &arr[i]);
    }

    // Display original array
    printf("\nOriginal array:          ");
    for(int i=0; i<size; i++)
    {
        printf("%.0lf            ", arr[i]);
    }

    // Modify array as per requirements
    printf("\n\nModified array:          ");
    transformArray(arr, size);

    return 0;
}