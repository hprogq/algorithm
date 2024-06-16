#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 103;
int main() {
#ifdef LOCAL
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    int n, m;
    while ( ~scanf("%d%d", &n, &m) && n + m ) {
        int g[N][N], d[N];
        bool s[N] = {false};
        memset( g, 0x3f, sizeof g );
        memset( d, 0x3f, sizeof d );
        d[1] = 0;
        while ( m -- ) {
            int a, b, w;
            scanf("%d%d%d", &a, &b, &w);
            g[a][b] = g[b][a] = w;
        }
        for ( int i = 1; i < n; i ++ ) {
            int t = 0;
            for ( int j = 1; j <= n; j ++ )
                if ( !s[j] && d[j] < d[t] )
                    t = j;
            s[t] = true;
            for ( int j = 1; j <= n; j ++ )
                d[j] = min( d[j],  d[t] + g[t][j] );
        }
        printf("%d\n", d[n]);
    }
    return 0;
}
