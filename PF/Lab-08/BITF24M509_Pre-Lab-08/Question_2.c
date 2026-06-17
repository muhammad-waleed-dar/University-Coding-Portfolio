#include <stdio.h>

void findSecondLargest(int arr[], int size) {
    int max = -2147483648;   // Minimum possible value for a 32-bit int
    int smax = -2147483648;  // Minimum possible value for a 32-bit int

    for (int i = 0; i < size; i++) {
        if (arr[i] > max) {
            smax = max;
            max = arr[i];
        } else if (arr[i] > smax && arr[i] != max) {
            smax = arr[i];
        }
    }

    if (smax == -2147483648) {
        printf("\nNo second maximum found! (All elements may be equal or only one unique element exists).\n");
    } else {
        printf("\nSecond largest element: %d\n", smax);
    }
}

int main() {
        int size;
        printf("\nEnter the size of the array: ");
        scanf("%d", &size);

        if (size < 2) {
            printf("Error: At least two elements are required.\n");
        } else {
            int arr[size];
            printf("Enter the elements of the array:\n");
            for (int i = 0; i < size; i++) {
                printf("Element %d: ", i + 1);
                scanf("%d", &arr[i]);
            }

            findSecondLargest(arr, size);
        }
    return 0;
}
