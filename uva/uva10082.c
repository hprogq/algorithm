#include <stdio.h>
#include <string.h>
int main(void) {
    char s[100] = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
    char c;
    while ( ( c = getchar() ) != EOF ) {
        char *p = strchr(s, c);
        if ( p == NULL )
            printf("%c", c);
        else printf("%c", *( p - 1 ));
    }
    return 0;
}
