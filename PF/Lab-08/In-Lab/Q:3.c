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

    int i = 0, j = 0, k = 0;

    while (i < n) // 'n' has the size of negative array that contains negative elements of arr[] which itself is a mixture of positive & negative elements.
        arr[k++] = neg[i++];

    while (j < p)
        arr[k++] = pos[j++];

    printf("Rearranged array:\n");
    displayArray(arr, size);

    return 0;
}
