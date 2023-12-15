#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 1e5 + 10;

void down( int heap[], int x, int size ) {
    int t = x;
    if ( 2 * x <= size && heap[t] > heap[ 2 * x ] )
        t = 2 * x;
    if ( 2 * x + 1 <= size && heap[t] > heap[ 2 * x + 1 ] )
        t = 2 * x + 1;
    if ( t != x ) {
        swap( heap[t], heap[x] );
        down( heap, t, size );
    }
    return;
}

int main() {
    int n, m, p[N];
    scanf("%d%d", &n, &m);
    for ( int i = 1; i <= n; i ++ )
        scanf("%d", &p[i]); 
    for ( int i = n / 2; i; i -- )
        down(p, i, n);
    while ( m -- ) {
        printf("%d ", p[1]);
        p[1] = p[ n -- ];
        down( p, 1, n );
    }
    return 0;
}
