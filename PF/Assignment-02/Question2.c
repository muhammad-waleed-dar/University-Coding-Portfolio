#include <stdio.h>

// Reverses elements of arr from start_index to last_index using "two-pointer approach"
void reverseArray(int arr[], int start_index, int last_index) {
    while (start_index < last_index) {
        int temp = arr[start_index];
        arr[start_index] = arr[last_index];
        arr[last_index] = temp;
        start_index++;
        last_index--;
    }
}

// Function to print the array
void displayArray(int arr[], int size) {
    printf("\n");
    for (int i = 0; i < size; i++) {
        printf("%8d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int size;

    // Input for array size
    printf("\nEnter the size of the array: ");
    scanf("%d", &size);

    // Validate array size
    if (size <= 0) {
        printf("\nInvalid array size. Please enter a positive integer.\n");
        return 1;
    }

    int arr[size];

    // Input for array elements
    printf("\nEnter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("\nOriginal array:\n");
    displayArray(arr, size);

    // Input for rotation steps
    int k;
    printf("\nEnter a non-negative integer 'k' to rotate the array: ");
    scanf("%d", &k);

    // Validate 'k'
    if(k<0)
    {
        printf("\nInvalid input!!! Enter a positive integer!\n");
        return 1;
    }

    // Reduce k if greater than array size
    if(k>size)
    k = k % size;

    // Rotation
    reverseArray(arr, 0, size - 1);     // Reverse entire array
    reverseArray(arr, 0, k - 1);        // Reverse first k elements
    reverseArray(arr, k, size - 1);     // Reverse remaining elements

    // Display the rotated array
    printf("\n\nRotated array by %d step(s) to the right:\n", k);
    displayArray(arr, size);

    return 0;
}
