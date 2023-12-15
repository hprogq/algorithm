#include <stdio.h>
#include <math.h>
#define MAXN 300

int prime( int n ) {
    int i, j;
    for ( i = 2; i <= sqrt(n) && ( j = n % i ); i ++ );
    return n >= 2 && j;
}

int main() {
    for ( int i = 1; i <= MAXN; i ++ )
        if ( prime(i) )
            printf("%d\n", i);
    return 0;
}
