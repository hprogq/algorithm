#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

const int N = 510, INF = 0x3f3f3f3f;

int n, m, g[N][N], d[N], idx = 0;
bool st[N];

int main() {
#ifdef LOCAL
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    memset( g, 0x3f, sizeof(g) );
    scanf("%d%d", &n, &m);
    while ( m -- ) {
        int a, b, w;
        scanf("%d%d%d", &a, &b, &w);
        g[a][b] = min( g[a][b], w);
    }

    memset( d, 0x3f, sizeof(d) );
    d[1] = 0;
    for ( int i = 1; i < n; i ++ ) {
        int t = -1;
        for ( int j = 1; j <= n; j ++ )
            if ( !st[j] && ( !~i || d[t] > d[j] ) )
                t = j;
        // st[t] = true;
        // for ( int j = 1; j <= n; j ++ )
        //     if ( g[t][j] != INF && d[j] > d[t] + g[t][j] )
        //         d[j] = d[t] + g[t][j];
        for (int j = 1; j <= n; j ++ )
            d[j] = min(d[j], d[t] + g[t][j]);
        st[t] = true;
    }

    printf("%d\n", d[n] == INF ? -1 : d[n]);
    return 0;
}
