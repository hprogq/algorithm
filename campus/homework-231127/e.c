#include <stdio.h>
#include <string.h>
#define N 20
int main() {
    int fib[N] = { 1, 1 };
    for ( int i = 2; i < N; i ++ )
        fib[i] = fib[ i - 1 ] + fib[ i - 2 ];
    for ( int i = 0; i < N; i ++ )
        printf("%6d%s", fib[i], ( i + 1 ) % 5 ? " " : "\n");
    return 0;
}
