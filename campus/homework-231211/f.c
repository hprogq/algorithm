#include <stdio.h>
#define N 5

void comp( int x[N] ) {
    for ( int i = 0; i < N; i ++ )
        if ( x[i] > 0 )
            printf("%d\n", x[i]);
    return;
}

int main() {
    int x[N];
    for ( int i = 0; i < N; i ++ )
        scanf("%d", &x[i]);
    comp(x);
    return 0;
}
