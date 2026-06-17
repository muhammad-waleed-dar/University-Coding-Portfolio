#include <stdio.h>
#include <string.h>

int main() {
    char s[1001];
    scanf("%s", s);

    int left = 0;
    int right = strlen(s) - 1; // size of char array = strlen(s) + 1 (addition of 1 is for \0. Strlen() doesn't count \0)
    int isPalindrome = 1;

    while (left < right) {
        char a = s[left];
        char b = s[right];

        if (a >= 'A' && a <= 'Z') {    //a = a|32   // s[left] = s[left] | 32
            a += 32;
        }
        if (b >= 'A' && b <= 'Z') {    //b = b|32  // s[right] = s[right] | 32
            b += 32;
        }

        if (a != b) {              // if(s[left] != s[right])
            isPalindrome = 0;
            break;
        }

        left++;
        right--;
    }

    if (isPalindrome)
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}
