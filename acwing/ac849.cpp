#include <iostream>
#include <cstdio>
#include <cstring>
const int N = 503, INF = 0x3f3f3f3f;
using namespace std;
int main() {
#ifdef LOCAL
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    int n, m, g[N][N], d[N];
    bool s[N] = {false};
    
    memset( g, 0x3f, sizeof g );
    memset( d, 0x3f, sizeof d );
    
    scanf("%d%d", &n, &m);
    for ( int i = 1; i <= m; i ++ ) {
        int a, b, w;
        scanf("%d%d%d", &a, &b, &w);
        g[a][b] = max( g[a][b], w );
    }
    
    d[1] = 0;
    for ( int i = 1; i < n; i ++ ) {
        int t = 0;
        for ( int j = 1; j <= n; j ++ )
            if ( !s[j] && d[j] < d[t] )
                t = j;
        
        s[t] = true;
        for ( int j = 1; j <= n; j ++ )
            d[j] = min( d[j], d[t] + g[t][j] );
    }
    
    printf("%d\n", d[n] == INF ? -1 : d[n]);
    
    return 0;
}
