#include <stdio.h>
int findSquare(int num) {
 int square = num * num;
 return square;   // No return statement was written in the buggy code. Hence, compiler error was being generated. Now fixed!
}
int main() {
 int result = findSquare(5);
 printf("Square: %d\n", result);
 return 0;
}