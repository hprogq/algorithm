#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
const int N = 1e5 + 10, M = 2 * N;
int n, m, h[N], e[M], ne[M], idx = 0;

void connect( int a, int b ) {
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx;
    idx ++;
    return;
}


int main() {
#ifdef LOCAL
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    memset( h, -1, sizeof(h) );
    scanf("%d%d", &n, &m);
    for ( int i = 1; i <= m; i ++ ) {
        int a, b;
        scanf("%d%d", &a, &b);
        connect( a, b );
    }
    int q[M], d[N], hh = 0, tt = 0;
    memset( d, -1, sizeof(d) );
    q[0] = 1, d[1] = 0;
    while ( hh <= tt ) {
        int x = q[ hh ++ ];
        for ( int i = h[x]; ~i ; i = ne[i] )
            if ( !~d[ e[i] ] ) {
                d[ e[i] ] = d[x] + 1;
                q[ ++ tt ] = e[i];
            }
    }
    printf("%d\n", d[n]);
    return 0;
}
