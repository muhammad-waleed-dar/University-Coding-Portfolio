#include <stdio.h>

// Function to reverse in groups of k
void reverseInGroup(int arr[], int size, int k)
{
    for (int i = 0; i < size; i += k) {
        int left = i;
        int right = (i + k - 1 < size) ? (i + k - 1) : (size - 1);
        
        // Swap elements within the subarray
        while (left < right) {
            int temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
            left++;
            right--;
        }
    }
}

// Function to print the array
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int size;

    // Input array size
    printf("\nEnter the size of the array: ");
    scanf("%d", &size);

    // Input validation
    if (size <= 0) {
        printf("\nInvalid array size. Please enter a positive integer.\n");
        return 1;
    }

    int arr[size];

    // Input array elements
    printf("\nEnter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // Display original array
    printf("\nOriginal array: ");
    printArray(arr, size);

    // Input value of k
    int k;
    printf("\nEnter the integer 'k' to reverse elements in groups of 'k': ");
    scanf("%d", &k);

    // Validate k
    if (k <= 0) {
        printf("\nInvalid value of k. Please enter a positive integer.\n");
        return 1;
    }

    // Modify array as per requirements
    reverseInGroup(arr, size, k);

    // Print modified array
    printf("\nReversed array in groups of %d: ", k);
    printArray(arr, size);
    
    return 0;
}
