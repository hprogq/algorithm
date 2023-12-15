#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int N = 10;
typedef pair<int, int> com;

int n, k, ans = 0;
bool g[N][N] = { false }, visy[N] = { false };

void dfs( int x = 1, int vis = 0 ) {
    if ( vis == k ) {
        ans ++;
        return;
    }
    if ( x > n )
        return;
    for ( int y = 1; y <= n; y ++ )
        if ( g[x][y] && !visy[y] ) {
            visy[y] = true;
            dfs( x + 1, vis + 1 );
            visy[y] = false;
        }
    dfs( x + 1, vis );
    return;
}

int main() {
#ifdef LOCAL
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    while ( ~scanf("%d%d\n", &n, &k) && ~n && ~k ) {
        ans = 0;
        memset( g, false, sizeof(g) );
        memset( visy, false, sizeof(visy) );
        for ( int i = 1; i <= n; i ++ ) {
            string s;
            getline( cin, s );
            for ( int j = 0; j < n; j ++ )
                if ( s[j] == '#' )
                    g[i][ j + 1 ] = true;
        }
        dfs();
        printf("%d\n", ans);
    }
    return 0;
}