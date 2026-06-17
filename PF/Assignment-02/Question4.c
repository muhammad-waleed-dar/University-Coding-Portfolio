#include <stdio.h>

// Function that computes the sum of the boundary elements of the matrix
void boundarySum(int rows, int cols, int matrix[rows][cols]) {
    int sum = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (i == 0 || i == rows - 1 || j == 0 || j == cols - 1) {
                sum += matrix[i][j];
            }
        }
    }
    
    printf("\nSum of all the boundary elements of the given matrix: %d\n", sum);
}

// Function to display the matrix
void printMatrix(int rows, int cols, int matrix[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        printf("      "); 
        for (int j = 0; j < cols; j++) {
            printf("%8d ", matrix[i][j]);
        }
        printf("\n");
    }
}

//  Function to take input for the matrix elements
void inputMatrix(int rows, int cols, int matrix[rows][cols]) {
for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
        printf("Element [%d][%d]: ", i, j);
        scanf("%d", &matrix[i][j]);
    }
}
}
int main() {
    int rows, cols;

    // Input for number of rows and columns
    printf("\nEnter number of rows: ");
    scanf("%d", &rows);

    // Input validation for rows
    if (rows <= 0) {
        printf("\nInvalid number of rows!!! Please enter a positive integer.\n");
        return 1;
    }

    printf("Enter number of columns: ");
    scanf("%d", &cols);

    // Input validation for columns
    if (cols <= 0) {
        printf("\nInvalid number of columns!!! Please enter a positive integer.\n");
        return 1;
    }

    int matrix[rows][cols]; 

    // Input for the matrix elements
    printf("\nEnter the elements of the matrix:\n");
    inputMatrix(rows, cols, matrix);

    // Display the matrix
    printf("\nThe matrix is:\n\n");
    printMatrix(rows, cols, matrix);

    // Compute the sum of boundary elements
    boundarySum(rows, cols, matrix);

    return 0;
}