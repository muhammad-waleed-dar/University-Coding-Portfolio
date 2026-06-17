#include <stdio.h>

// Function to classify the matrix
void classifyMatrix(int n, int matrix[n][n]) {
    int isDiagonal = 1, isIdentity = 1, isScalar = 1, isNull = 1;
    int scalarValue = matrix[0][0]; // First diagonal element

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) { // Checking diagonal elements
                if (matrix[i][j] != 0) {
                    isNull = 0; // If any diagonal element is non-zero, it's not null
                }
                if (matrix[i][j] != 1) {
                    isIdentity = 0; // If any diagonal element is not 1, it's not identity
                }
                if (matrix[i][j] != scalarValue) {
                    isScalar = 0; // If diagonal elements are different, it's not scalar
                }
            } else { // Checking non-diagonal elements
                if (matrix[i][j] != 0) {
                    isDiagonal = 0; // If any non-diagonal element is non-zero, it's not diagonal
                }
            }
        }
    }

    // Classification logic
    if (isNull && isDiagonal) {
        printf("The matrix is a Null (Zero) Matrix.\n");
    } else if (isIdentity && isDiagonal) {
        printf("The matrix is an Identity Matrix.\n");
    } else if (isScalar && isDiagonal) {
        printf("The matrix is a Scalar Matrix.\n");
    } else if (isDiagonal) {
        printf("The matrix is a Simply Diagonal Matrix.\n");
    } else {
        printf("The matrix is None of the above.\n");
    }
}

int main() {
    int n;
    printf("Enter the order of the square matrix: ");
    scanf("%d", &n);

    int matrix[n][n];
    printf("Enter the elements of the %dx%d matrix:\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    classifyMatrix(n, matrix);
    return 0;
}
