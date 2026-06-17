#include <stdio.h>

// Function to take input for the 2D array elements
void inputArray(int rows, int cols, int arr[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }
}

// Function to display the 2D array
void printArray(int rows, int cols, int arr[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        printf("      ");
        for (int j = 0; j < cols; j++) {
            printf("%8d ", arr[i][j]);
        }
        printf("\n");
    }
}

// Function that prints the 2D array elements in spiral order
void spiralPrint(int rows, int cols, int arr[rows][cols]) {
    int minRow = 0, maxRow = rows - 1;
    int minCol = 0, maxCol = cols - 1;
    int totalElements = rows * cols;
    int count = 0;

    while (count < totalElements) {
        // Print top row
        for (int j = minCol; j <= maxCol && count < totalElements; j++) {
            printf("%d ", arr[minRow][j]);
            count++;
        }
        minRow++;

        // Print right column
        for (int i = minRow; i <= maxRow && count < totalElements; i++) {
            printf("%d ", arr[i][maxCol]);
            count++;
        }
        maxCol--;

        // Print bottom row
        for (int j = maxCol; j >= minCol && count < totalElements; j--) {
            printf("%d ", arr[maxRow][j]);
            count++;
        }
        maxRow--;

        // Print left column
        for (int i = maxRow; i >= minRow && count < totalElements; i--) {
            printf("%d ", arr[i][minCol]);
            count++;
        }
        minCol++;
    }
    printf("\n");
}

int main() {
    int rows, cols;

    // Input for number of rows
    printf("\nEnter number of rows: ");
    scanf("%d", &rows);
    if (rows <= 0) {
        printf("Invalid number of rows! Please enter a positive integer.\n");
        return 1;
    }

    // Input for number of columns
    printf("Enter number of columns: ");
    scanf("%d", &cols);
    if (cols <= 0) {
        printf("Invalid number of columns! Please enter a positive integer.\n");
        return 1;
    }

    int arr[rows][cols];

    // Input elements
    printf("\nEnter the elements of the matrix:\n");
    inputArray(rows, cols, arr);

    // Display matrix
    printf("\nThe matrix is:\n\n");
    printArray(rows, cols, arr);

    // Print in spiral order
    printf("\nArray elements in Spiral order:\n\n");
    spiralPrint(rows, cols, arr);

    return 0;
}
