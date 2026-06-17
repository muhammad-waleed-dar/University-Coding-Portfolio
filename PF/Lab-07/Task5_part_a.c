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
    for (int i = 0; i < students; i++) {
        avg = 0; // imp to intialzie here!
        for (int j = 0; j < tests; j++) {
            avg += marks[i][j];
        }
        avg /= tests;
        printf("\nScore average for student %d is %.1f", i + 1, avg);
    }

    printf("\n");
    return 0;
}
