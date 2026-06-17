#include <stdio.h>

long long sequence(long long n, long long k) {
    if (n <= k)
        return 1; // Base case: First k terms are 1

    return sequence(n - 1, k) + sequence(n - 2, k) + sequence(n - 3, k) +
           sequence(n - 4, k) + sequence(n - 5, k) + sequence(n - 6, k) +
           sequence(n - 7, k) + sequence(n - 8, k) + sequence(n - 9, k) +
           (k >= 10 ? sequence(n - 10, k) : 0);
}

int main() {
    long long n, k;
    printf("Enter value of 'n' within the range e.g., (1 <= n <= 1000): ");
    scanf("%lld", &n);
    printf("Enter value of 'k' within the range e.g., (1 <= k <= 10): ");
    scanf("%lld", &k);

    if ((n >= 1 && n <= 1000) && (k >= 1 && k <= 10))
        printf("The nth term of the sequence is: %lld\n", sequence(n, k));
    else
        printf("Invalid input. Enter input within the specified range for 'n' and 'k'.\n");

    return 0;
}
