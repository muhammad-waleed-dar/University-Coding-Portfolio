#include <stdio.h>

// Function that sorts the 1D array in wave array
void waveArray(int arr[], int size) {
    for (int i = 0; i < size - 1; i += 2) {
        // If current element is smaller than the previous, swap
        if (i > 0 && arr[i] < arr[i - 1]) {
            int temp = arr[i];
            arr[i] = arr[i - 1];
            arr[i - 1] = temp;
        }

        // If current element is smaller than the next, swap
        if (i < size - 1 && arr[i] < arr[i + 1]) {
            int temp = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = temp;
        }
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

    // Input for the 1D array elements
    printf("\nEnter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("\nOriginal array:\n");
    displayArray(arr, size);

    // Edge case of a single element
    if (size == 1) {
        printf("\nThe wave array is the same as the original array: ");
        displayArray(arr, size);
        return 0;
    }

    // Sort array in wave array
    printf("\nWave array:\n");
    waveArray(arr, size);

    // Display the wave array
    displayArray(arr, size);

    return 0;
}
