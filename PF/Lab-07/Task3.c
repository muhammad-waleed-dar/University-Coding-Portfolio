#include <stdio.h>

int main() {

    int arr[5][5];
    int maxArr[5];

    //Input for 2D array
    printf("\nEnter the elements of the 2D array:\n");
    for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
        printf("Element [%d][%d]: ", i, j);
        scanf("%d", &arr[i][j]);
    }
    }
    
    // Display 2D array
    printf("\n\n2D array content:\n\n");
    for(int i = 0; i < 5; i++) {
        printf("      ");  
        for (int j = 0; j < 5; j++) {
            printf("%8d ", arr[i][j]);  
        }
        printf("\n");
    }

    // Finding max in each row
    for(int i=0; i<5; i++)
    {
    int max= arr[i][0];   // 1st element of each row is set to be the max element in each iteration one-by-one! Then we are finding real max element in each row by comparing!
    
    for(int j=1; j<5; j++)  // start from next element not from '0'
    {
    if(arr[i][j]>max)
    max = arr[i][j];
    }
    
    maxArr[i] = max;
    }
    
    // Printing max elements row-wise
    printf("\n\nMaximum element in each row of the 2D array:\n\n");
    for(int i=0; i<5; i++)
    {
    printf("Row %d: %d\n", i+1, maxArr[i]);
    }

    return 0;
}