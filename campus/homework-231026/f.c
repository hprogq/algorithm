#include <stdio.h>
int main() {
    char c;
    scanf("%c", &c);
    if ( c >= 'A' && c <= 'Z' )
        printf("%c\n", c + 32);
    else if ( c >= 'a' && c <= 'z' )
        printf("%c\n", c - 32);
    else printf("%c\n", c);
    return 0;
}
