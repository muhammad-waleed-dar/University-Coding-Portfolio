#include <stdio.h>

int Sum(int arr[], int start, int end) {

    if(start>end)
    return 0;
    
    return arr[start] + Sum(arr,start+1,end);
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
    int size,start,end;
    printf("\nEnter the size of the array: ");
    scanf("%d", &size);

    if (size <= 0) {
        printf("\nInvalid array size.\n");
        return 1;
    }

    start=0, end=size-1;

    int arr[size];

    printf("\nEnter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("\nArray:");
    displayArray(arr, size);

    int sum = Sum(arr, start, end);

    printf("Sum of the array's elements: %d\n", sum);

    return 0;
}