#include <stdio.h>

int main() {
    char s1[100001], s2[100001];
    int freq[26] = {0};
    int i;

    fgets(s1, sizeof(s1), stdin);
    fgets(s2, sizeof(s2), stdin);

    for (i = 0; s1[i] != '\0'; i++) {
        if (s1[i] == '\n') {
            s1[i] = '\0';
            break;
        }
    }
    for (i = 0; s2[i] != '\0'; i++) {
        if (s2[i] == '\n') {
            s2[i] = '\0';
            break;
        }
    }

    for (i = 0; s1[i] != '\0'; i++) {
        char c = s1[i];
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
            if (c >= 'A' && c <= 'Z') {
                c = c + ('a' - 'A');
            }
            freq[c - 'a']++;
        }
    }

    for (i = 0; s2[i] != '\0'; i++) {
        char c = s2[i];
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
            if (c >= 'A' && c <= 'Z') {
                c = c + ('a' - 'A');
            }
            freq[c - 'a']--;
        }
    }

    for (i = 0; i < 26; i++) {
        if (freq[i] != 0) {
            printf("NO\n");
            return 0;
        }
    }

    printf("YES\n");
    return 0;
}
