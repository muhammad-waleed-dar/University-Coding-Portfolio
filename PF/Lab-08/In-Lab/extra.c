#include <stdio.h>

int main() {
    int size;
    printf("Enter number of elements: ");
    scanf("%d", &size);

    if (size <= 0) {
        printf("Invalid array size.\n");
        return 1;
    }

    int arr[size];
    printf("Enter elements: ");
    for (int i = 0; i < size; i++) 
    {
        scanf("%d", &arr[i]);
    }

    int left = 0;  

    for (int i = 0; i < size; i++) {
        if (arr[i] < 0) 
        {
            int temp = arr[i];
            arr[i] = arr[left]; // You are very confused about what is left??? and are we swapping it!!! See odd even array program as well given in kab by abdul mateen!
            arr[left] = temp;
            left++;
        }
    }

    printf("Rearranged array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
