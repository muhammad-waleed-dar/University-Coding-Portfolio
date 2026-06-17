#include <stdio.h>

int main() {
    int students = 3, tests = 5;
    float marks[3][5], avg;

    // Input marks
    for (int i = 0; i < students; i++) {
        printf("\nEnter marks of Student %d:-\n", i + 1);
        for (int j = 0; j < tests; j++) {
            printf("          Enter marks of Test %d: ", j + 1);
            scanf("%f", &marks[i][j]);
        }
    }

    // Calculate and display averages
    for (int j = 0; j < tests; j++) {
        avg = 0; 
        for (int i = 0; i < students; i++) {
            avg += marks[i][j];
        }
        avg /= students;
        printf("\nStudents average for Test %d is: %.4f", j + 1, avg);
    }

    printf("\n");
    return 0;
}
