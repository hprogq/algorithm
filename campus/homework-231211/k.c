#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void reverse( int n ) {
    if ( n < 0 )
        printf("-");
    int t = abs(n);
    while ( t ) {
        printf("%d", t % 10);
        t /= 10;
    }
}

int main() {
    int n;
    scanf("%d", &n);
    reverse(n);
    return 0;
}
