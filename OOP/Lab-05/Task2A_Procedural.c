#include <stdio.h>
#include <stdlib.h>

int main() {
    const size_t BLOCK_SIZE = 1024 * 1024; 
    size_t total = 0;
    int count = 0;
    void* ptr;

    printf("Allocating 1 MB blocks repeatedly (press Ctrl+C to stop)...\n\n");

    while (1) {
        ptr = malloc(BLOCK_SIZE);
        if (ptr == NULL) {
            printf("Memory allocation failed after %zu MB!\n", total / (1024 * 1024));
            break;
        }

        for (size_t i = 0; i < BLOCK_SIZE; ++i) ((char*)ptr)[i] = 0;

        total += BLOCK_SIZE;
        ++count;
        printf("Block %d allocated. Total allocated: %.2f MB\n",
               count, total / (1024.0 * 1024.0));
    }
    return 0;
}

