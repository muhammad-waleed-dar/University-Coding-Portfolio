#include <stdio.h>
#include <string.h>

int main() {
    char arr[100];
    printf("Enter a string: ");
    scanf("%s", arr); 

    int n = strlen(arr);
    int visited[n];

    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    printf("\nFrequency of each character:\n");

    for (int i = 0; i < n; i++) {
        if (visited[i] == 1)
            continue;

        int count = 1;

        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                count++;
                visited[j] = 1; 
            }
        }

        printf("%c: %d\n", arr[i], count);  
    }

    return 0;
}
