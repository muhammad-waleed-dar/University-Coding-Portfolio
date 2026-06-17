#include <stdio.h>

float add(float a, float b)      { return a + b; }
float subtract(float a, float b) { return a - b; }
float multiply(float a, float b) { return a * b; }
float divide(float a, float b)   { return b != 0 ? a / b : 0; }

typedef float (*operation)(float, float);

float calculate(float x, float y, operation op) {
    return op(x, y);
}

int main() {
    float a = 10.0f, b = 5.0f;

    printf("Add: %.2f\n",      calculate(a, b, add));
    printf("Subtract: %.2f\n", calculate(a, b, subtract));
    printf("Multiply: %.2f\n", calculate(a, b, multiply));
    printf("Divide: %.2f\n",   calculate(a, b, divide));

    return 0;
}

