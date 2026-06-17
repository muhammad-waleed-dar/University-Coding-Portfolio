#include <stdio.h>
void foo(int n) {
 if (n <= 0)
 return;
 printf("%d ", n);
 foo(n - 2);
 printf("%d ", n);
}
int main() {
 foo(5);
 return 0;
}