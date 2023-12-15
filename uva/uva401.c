#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAXL 30
const char *rev = "A   3  HIL JM O   2TUVWXY51SE Z  8 ";
const char *status[] = {
    // 2 * m + p
    "not a palindrome",     // 2 * 0 + 0
    "a regular palindrome", // 2 * 0 + 1
    "a mirrored string",    // 2 * 1 + 0
    "a mirrored palindrome" // 2 * 1 + 1
};
char revc(char ori)
{
    int t;
    if (isalpha(ori))
        t = ori - 'A';
    else
        t = ori - '0' + 25;
    return rev[t];
}
int main(void)
{
    char s[MAXL];
    while (scanf("%s", s) == 1)
    {
        int p = 1, m = 1;
        for (int i = 0; i < (strlen(s) + 1) / 2; i++)
        {
            // printf("%c %c %c\n", s[i], s[strlen(s) - i - 1], revc(s[i]));
            if (s[strlen(s) - i - 1] != revc(s[i])) {
                m = 0;
                // printf("%d", m);
            }
            if (s[strlen(s) - i - 1] != s[i])
                p = 0;
        }
        printf("%s -- is %s.\n\n", s, status[2 * m + p]);
    }
    return 0;
}
