#include <stdio.h>

void displayArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    if (size <= 0) {
        printf("Invalid array size.\n");
        return 1;
    }

    int arr[size];
    printf("Enter the elements:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    int pos[size], neg[size];
    int p = 0, n = 0;

    for (int i = 0; i < size; i++) {
        if (arr[i] >= 0)
            pos[p++] = arr[i];
        else
            neg[n++] = arr[i];
    }

    int result[size];
    int i = 0, j = 0, k = 0;

    while (i < n && j < p) {
        result[k++] = neg[i++];
        result[k++] = pos[j++];
    }

    while (i < n)
        result[k++] = neg[i++];

    while (j < p)
        result[k++] = pos[j++];

    printf("Rearranged array:\n");
    displayArray(result, size);

    return 0;
}
