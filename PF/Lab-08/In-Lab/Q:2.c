#include <stdio.h>

int main() {

    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    if (size <= 0) {
        printf("Invalid array size.\n");
        return 1;
    }

    int arr[size];
    int visited[size];  

    printf("\nEnter the elements of the array:\n");
        for (int i = 0; i < size; i++) {
            printf("Element %d: ", i + 1);
            scanf("%d", &arr[i]);
        }
    
        printf("\nArray elements/content:\n");
        for (int i = 0; i < size; i++) {
            printf("%d  ", arr[i]);
            visited[i]=0;
        }

    printf("\n\nFrequency of all elements of the array:\n");  

    for(int i=0; i<size; i++)
    {
        if (visited[i] == 1)
        continue;  

        int count=1;              
        for(int j=i+1; j<size; j++)   
        {
            if(arr[i]==arr[j])
            {
            count++;
            visited[j] = 1; 
            } 
        }
        printf("\nFrequency of %d is: %d\n", arr[i], count);
    }
    return 0;
}