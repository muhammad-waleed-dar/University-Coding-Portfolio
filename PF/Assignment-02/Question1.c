#include <stdio.h>

// Recursive function to count the number of unique paths
int countPaths(int m, int n) {
    // Base case: if we reach the bottom or right edge of the grid
    if (m == 1 || n == 1) {
        return 1;
    }

    // Recursively count the number of paths
    return countPaths(m - 1, n) + countPaths(m, n - 1);
}

int main() {
    int m, n;

    // Input grid dimensions
    printf("Enter the number of rows: ");
    scanf("%d", &m);
    printf("Enter the number of columns: ");
    scanf("%d", &n);

    // Check for valid grid size
    if (m <= 0 || n <= 0) {
        printf("Invalid grid size. Both m and n should be positive integers.\n");
        return 1;
    }

    // Calculate the total number of unique paths
    int result = countPaths(m, n);
    
    // Output the result
    printf("Number of unique paths: %d\n", result);

    return 0;
}
