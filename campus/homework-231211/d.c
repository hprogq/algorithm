#include <stdio.h>
#include <math.h>

int prime( int n ) {
    int i, j;
    for ( i = 2; i <= sqrt(n) && ( j = n % i ); i ++ );
    return n >= 2 && j;
}

int main() {
    int n;
    scanf("%d", &n);
    printf( prime(n) ? "YES" : "NO" );
    return 0;
}
