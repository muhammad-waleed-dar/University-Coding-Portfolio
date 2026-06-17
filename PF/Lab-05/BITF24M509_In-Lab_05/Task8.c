#include <stdio.h>
int add(int a, int b);       //Return-type was void in the given buggy code (Counted as an error)
int main() {
 float result = add(4, 5);
 printf("Sum: %f", result);
 return 0;
}
int add(int a, int b) {     //Return-type was void in the given buggy code (Counted as an error)
 return a + b;
}