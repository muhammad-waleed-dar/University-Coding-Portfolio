#include <stdio.h>
void changeValue(int x) {
 x = 20;
 printf("x : %d\n", x);
}
int main() {
 int x = 10;
 printf("Before function call: %d\n", x);
 changeValue(x);
 printf("After function call: %d\n", x);
 return 0;
}