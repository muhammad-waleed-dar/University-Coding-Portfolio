#include <stdio.h>

    int Duplicate(int arr[], int index, int size, int n, int count) {
        if (index == size) {
            if (count > 1)
                printf("Number %d is a duplicate in the array.\n", n);
            else
                printf("Number %d is NOT a duplicate in the array.\n", n);
            return count;
        }
    
        if (arr[index] == n)
            count++;
    
        return Duplicate(arr, index + 1, size, n, count);
    }    

int main()
{
    int size, coun=0;
    printf("\nEnter the size of the array: ");
    scanf("%d", &size);

    if (size <= 0) {
        printf("\nInvalid array size.\n");
        return 1; 
    }

    int arr[size];
    
    printf("\nEnter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    int n;
    printf("\nEnter a number to check if it is duplicate in the array: ");
    scanf("%d", &n);  

    Duplicate(arr, 0, size, n, 0);
}