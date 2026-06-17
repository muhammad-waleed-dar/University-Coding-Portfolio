#include <stdio.h>

// Function for 2D-array-elements' sum
int sumOfArray(int rows, int cols, int arr[rows][cols]) {
    int sum = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            sum += arr[i][j];
        }
    }
    return sum;
}

int main() {
    int rows, cols;

    // Input for rows and columns
    printf("\nEnter the number of rows: ");
    scanf("%d", &rows);
    
    printf("\nEnter the number of columns: ");
    scanf("%d", &cols);

    int arr[rows][cols];


    // Input for 2D array
    printf("\nEnter the elements of the 2D array:\n");
    for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
        printf("Element [%d][%d]: ", i, j);
        scanf("%d", &arr[i][j]);
    }
    }

    int totalSum = sumOfArray(rows, cols, arr);
    printf("\nThe sum of all elements in the 2D array is: %d\n", totalSum);

    return 0;
}
