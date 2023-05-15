#include <stdio.h>
#include <string.h>

void computeLPS(char *pattern, int *lps, int len)
{
    int i = 1, j = 0;
    lps[0] = 0;
    while (i < len) {
        if (pattern[i] == pattern[j]) {
            lps[i] = j + 1;
            i++;
            j++;
        } else if (j != 0) {
            j = lps[j-1];
        } else {
            lps[i] = 0;
            i++;
        }
    }
}

void kmp(char *text, char *pattern)
{
    int n = strlen(text);
    int m = strlen(pattern);

    int lps[m];
    computeLPS(pattern, lps, m);

    int i = 0, j = 0;
    while (i < n) {
        if (text[i] == pattern[j]) {
            i++;
            j++;
        } else if (j != 0) {
            j = lps[j-1];
        } else {
            i++;
        }

        if (j == m) {
            printf("Pattern found at index %d\n", i-j);
            j = lps[j-1];
        }
    }
}

int main()
{
    char text[] = "ABCABCDABABCDABCDABDE";
    char pattern[] = "ABCDABD";
    kmp(text, pattern);
    return 0;
}
