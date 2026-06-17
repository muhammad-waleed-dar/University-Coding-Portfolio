#include <stdio.h>

// Function to sort an array using Bubble Sort in descending order
void bubbleSortDescending(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int sorted = 1;         // Checkmark to see if array is correctly sorted or not as per our requirements of sorting. No need to go through further passes in case of a "non-worst case array"! A non-worst case array is that array which would sort early and won't take n-1 (size-1) passes! '1' with 'sorted' variable denotes it is sorted!!! If it satisfies the swapping condition in the inner loop for any element means that it's not sorted yet as per requirement so loop won't be break as going in inner loop would make sorted variable '0' which denotes it is not sorted!
        for (int j = 0; j < size - 1 - i; j++) {   // We can also write "j < size-1" but optimized version is "j < size-1-i" cause there is no need to check for last element in each further passes. After 1st pass, last element would be as per our sorting requirements. After 2nd pass, second last and last element checking is unnecessary/irrelevant cause they will be organized in correct order/manner!!! And so on for further passes! This doesn't do further unnecessary checking!
            if (arr[j] < arr[j + 1]) {  
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                sorted = 0;
            }
        }
        if (sorted == 1) break;    // Optimized bubble sort due to sorted named "checkmark" (like a flag variable) cause no need to go through further passes if an array is sorted early (array will take n-1 (size-1) passes only in the worst case!!! Otherwise, would be sorted early. Hence, if an array is sorted early e.g., it is not a worst case array, so for that algorithm doesn't run the bubble sort algorithm till the last pass!!!)
    }
}

// Function to print the array
void printArray(int arr[], int size) {
    printf("\nSorted array in descending order: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
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

    bubbleSortDescending(arr, size);

    printArray(arr, size);

    return 0;

}