#include <stdio.h>
int main() {
    char c;
    scanf("%c", &c);
    if ( c >= '0' && c <= '9' )
        printf("Digit.\n");
    else if ( ( c >= 'a' && c <= 'z' ) || ( c >= 'A' && c <= 'Z' ) )
        printf("Alphabet.\n");
    else printf("Other Character.\n");
    return 0;
}
