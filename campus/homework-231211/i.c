#include <stdio.h>
#define N 1000

int solve( int a[N] ) {
    int idx = 0;
    for ( int i = 1; i <= N; i ++ )
        if ( ( !( i % 7 ) || !( i % 11 ) ) && ( i % 77 ) )
            a[ idx ++ ] = i;
    return idx;
}

int main() {
    int a[N];
    int n = solve(a);
    printf("%d\n", n);
    for ( int i = 0; i < n; i ++ )
        printf("%d ", a[i]);
    return 0;
}
