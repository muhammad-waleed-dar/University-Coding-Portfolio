#include <stdio.h>
#include <string.h>

int main() {
    char s[1001];
    scanf("%s", s);  

    int count = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        char c = s[i];
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            count++;
        }
    }

    printf("%d\n", count);

    return 0;
}
