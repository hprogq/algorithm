#include <stdio.h>
int init = 0;
int main(void) {
    char c;
    while ( ( c = getchar() ) != EOF ) {
        switch (c) {
            case '"':
                printf( init ? "''" : "``" );
                init = !init;
                break;
            default:
                printf("%c", c);
                break;
        }
    }
    return 0;
}
