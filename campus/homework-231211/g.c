#include <stdio.h>
#define N 5

void sum( int x[N] ) {
    int sum = 0;
    for ( int i = 0; i < N; i ++ )
        sum += x[i];
    printf("%d\n", sum);
    return;
}

int main() {
    int x[N];
    for ( int i = 0; i < N; i ++ )
        scanf("%d", &x[i]);
    sum(x);
    return 0;
}
