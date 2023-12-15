#include <stdio.h>
#include <string.h>
#include <math.h>
#define LENL 3
#define MAXL 260
char c[MAXL];
int getlen() {
    int sum = 0;
    for ( int i = LENL - 1; i >= 0; ) {
        char c = getchar();
        if ( c != '\n' ) {
            sum += pow(2, i) * ( c - '0' );
            i--;
        }
    }
    return sum;
}
int getpos(int len) {
    int sum = 0, flag = 1;
    while ( len ) {
        char c = getchar();
        if ( c != '\n' ) {
            if ( c == '0' )
                flag = 0;
            len--;
            sum += pow(2, len) * ( c - '0' ) + pow(2, len) - 1;
        }
    }
    return flag ? -1 : sum;
}
int main( void ) {
#ifdef LOCAL
    freopen("uva213.in", "r", stdin);
    freopen("uva213.out", "w", stdout);
#endif
    int l;
    while ( fgets(c, MAXL, stdin) != NULL && c[0] != '\n' ) {
        while ( ( l = getlen() ) != 0 ) {
            int pos;
            while ( ( pos = getpos(l) ) != -1 )
                printf("%c", c[pos]);
        }
        getchar();
        printf("\n");
    }
    return 0;
}
