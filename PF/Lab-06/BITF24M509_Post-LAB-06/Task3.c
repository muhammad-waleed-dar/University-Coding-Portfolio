#include <stdio.h>

// Function to modify based on conditions
void modifyArray(int rows, int cols, int arr[rows][cols], int threshold) {
    int sum = 0;

// Calculate sum for first half (row-wise)
    for (int i = 0; i < rows/2; i++) {
        for (int j = 0; j < cols; j++) {
            sum += arr[i][j];
        }
    }

// Average
    float avg = (float)sum / (rows / 2 * cols);
    
// Modify second half based on conditions
    for (int i = rows / 2; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (avg <= threshold) {
                arr[i][j] *= 2;
            } else {
                arr[i][j] -= 5;
            }
        }
    }
}

// Function to print 2D array
void printArray(int rows, int cols, int arr[rows][cols]) {
    printf("\n");
    for (int i = 0; i < rows; i++) {
        printf("      ");  
        for (int j = 0; j < cols; j++) {
            printf("%4d ", arr[i][j]);  
        }
        printf("\n");    // Must
    }
}

int main() {
    int rows, cols, threshold;

    // Input for rows and columns
    printf("\nEnter the number of rows: ");
    scanf("%d", &rows);
    
    printf("\nEnter the number of columns: ");
    scanf("%d", &cols);

    if (rows % 2 != 0) {
        printf("\nError: The number of rows must be even.\n");
        return 1;
    }

    int arr[rows][cols];

    // Input for 2D array
    printf("\nEnter the elements of the 2D array:\n");
    for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
        printf("Element [%d][%d]: ", i, j);
        scanf("%d", &arr[i][j]);
    }
    }

    // Input for Threshold
    printf("\nEnter a threshold value: ");
    scanf("%d", &threshold);

    printf("\nOriginal Array: ");
    printArray(rows, cols, arr);

    modifyArray(rows, cols, arr, threshold);
    
    printf("\n\nModified Array: ");
    printArray(rows, cols, arr);
    printf("\n");

    return 0;
}
