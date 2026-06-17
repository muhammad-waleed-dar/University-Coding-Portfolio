#include <stdio.h>

// Function that checks whether the matrix is a magic square or not!
void magicSquare(int n, int matrix[n][n]) {
    
    int sum, sumcheck=0;

    for(int j=0; j<n; j++)
    {
        sumcheck += matrix[0][j];
    }

    for (int i = 1; i < n; i++) {
        sum=0;
        for (int j = 0; j < n; j++) {
                sum += matrix[i][j];
        }
        if(sum != sumcheck)
        {
            printf("\nThe given matrix is not a Magic Square!!!\n");
        return;
        } 
    
    }

    for (int j = 0; j < n; j++) {
        sum=0;
        for (int i = 0; i < n; i++) {
                sum += matrix[i][j];
        }
        if(sum != sumcheck)
        {
            printf("\nThe given matrix is not a Magic Square!!!\n");
        return;
        } 
    }

    sum = 0;
    for (int i = 0; i < n; i++) {
        sum += matrix[i][i];
    }
    if (sum != sumcheck) {
            printf("\nThe given matrix is not a Magic Square!!!\n");
        return;
    }

    sum = 0;
    for (int i = 0; i < n; i++) {
        sum += matrix[i][n - 1 - i];
    }
    if (sum != sumcheck) {
            printf("\nThe given matrix is not a Magic Square!!!\n");
        return;
    }

    printf("\nThe given matrix is a Magic Square!!!\n");
    printf("\nSo, Magic Constant (Sum of each row/col/diagonal): %d\n", sumcheck);
}

// Function to display the matrix
void printMatrix(int n, int matrix[n][n]) {
    for (int i = 0; i < n; i++) {
        printf("      "); 
        for (int j = 0; j < n; j++) {
            printf("%8d ", matrix[i][j]);
        }
        printf("\n");
    }
}

//  Function to take input for the matrix elements
void inputMatrix(int n, int matrix[n][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
}

int main() {
    int n;

    printf("\nMagic square is a square matrix!!!\n");

    // Input for number of rows and columns
    printf("\nEnter number of rows and columns of the square matrix: ");
    scanf("%d", &n);

    // Input validation
    if (n <= 0) {
        printf("\nInvalid number of rows and columns!!! Please enter a positive integer.\n");
        return 1;
    }

    // Single element matrix
    if (n == 1) {
        printf("\nSingle element matrix is always a Magic Square.\n");
        return 0;
    }    

    int matrix[n][n]; 

    // Input for the matrix elements
    printf("\nEnter the elements of the matrix:\n");
    inputMatrix(n, matrix);

    // Display the matrix
    printf("\nThe matrix is:\n\n");
    printMatrix(n, matrix);

    // Check for magic square matrix
    magicSquare(n, matrix);

    return 0;
}
