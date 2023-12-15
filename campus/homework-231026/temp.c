#include <stdio.h>
int main( void ) {
    char c;
    scanf("%c", &c);
    if ( c < 32 )
        printf("'%c' is a Control Character\n", c);
    else if ( c >= '0' && c <= '9' )
        printf("'%c' is a Digit\n", c);
    else if ( c >= 'A' && c <= 'Z' )
        printf("'%c' is an Uppercase Letter\n", c);
    else if ( c >= 'a' && c <= 'z' )
        printf("'%c' is a Lowercase Letter\n", c);
    else printf("'%c' is a Special Character\n", c);
    return 0;
}
