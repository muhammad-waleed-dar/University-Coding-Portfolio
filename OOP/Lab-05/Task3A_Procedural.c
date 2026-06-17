#include <stdio.h>

int main() {
    int a = 10;
    float b = 3.14f;
    char c = 'X';
    void *p = NULL;

    int *pInt = &a;
    float *pFloat = &b;
    char *pChar = &c;

    printf("Data Type | Size of Data | Size of Pointer\n");
    printf("-----------+--------------+----------------\n");
    printf("int   | %zu bytes | %zu bytes\n", sizeof(a), sizeof(pInt));
    printf("float | %zu bytes | %zu bytes\n", sizeof(b), sizeof(pFloat));
    printf("char  | %zu bytes | %zu bytes\n", sizeof(c), sizeof(pChar));
    printf("void* | - bytes   | %zu bytes\n", sizeof(p));

    return 0;
}
