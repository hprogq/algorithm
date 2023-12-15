#include <stdio.h>
#include <math.h>

void prime( int n ) {
    int i, j;
    for ( i = 2; i <= sqrt(n) && ( j = n % i ); i ++ );
    printf( n >= 2 && j ? "YES" : "NO" );
    return;
}

int main() {
    int n;
    scanf("%d", &n);
    prime(n);
    return 0;
}
