#include <stdio.h>
#define N 5

long f( int x ) {
    return x ? x * f( x - 1 ) : 1;
}

int main() {
    int x;
    scanf("%d", &x);
    printf("%ld\n", f(x));
    return 0;
}
