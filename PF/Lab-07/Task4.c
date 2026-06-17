#include <stdio.h>

int main() {
    int arr[3][3];

    //Input for 2D array
    printf("\nEnter the elements of the 2D array:\n");
    for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
        printf("Element [%d][%d]: ", i, j);
        scanf("%d", &arr[i][j]);
    }
    }
    
    // Display 2D array
    printf("\n\n2D array content:\n\n");
    for(int i = 0; i < 3; i++) {
        printf("      ");  
        for (int j = 0; j < 3; j++) {
            printf("%8d ", arr[i][j]);  
        }
        printf("\n");
    }

    // Checking for identity and diagonal matrix
    int isIdentity = 1, isDiagonal = 1;  

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == j) {
                if (arr[i][j] != 1) 
                    isIdentity = 0;
            } else {
                if (arr[i][j] != 0) {
                    isIdentity = 0;
                    isDiagonal = 0;
                }
            }
        }
    }

        // Output result
        printf("\nMatrix Type: ");
        if (isIdentity)
            printf("Identity Matrix\n");
        else if (isDiagonal)
            printf("Diagonal Matrix\n");
        else
            printf("Neither Diagonal nor Identity\n");
    
        return 0;
}
