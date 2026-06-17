#include <stdio.h>

int main() {
    char s[1001];
    scanf("%s", s);

    int i, j, found;

    for (i = 0; s[i] != '\0'; i++) {
        found = 0;
        for (j = 0; s[j] != '\0'; j++) {
            if (s[i] == s[j] && i != j) {
                found = 1;
                break;
            }
        }
        if (found == 0) {
            printf("%c\n", s[i]);
            return 0;
        }
    }

    printf("-1\n");
    return 0;
}
