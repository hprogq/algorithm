#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int N = 103;

bool dfs( int u, int n, int& t, bool G[N][N], int vis[N], int ans[N] ) {
    vis[u] = -1;
    for ( int i = 1; i <= n; i ++ ) {
        if ( G[u][i] ) {
            if ( !~vis[i] )  return false;
            else if ( !vis[i] && !dfs( i, n, t, G, vis, ans ) )  return false;
        }
    }
    vis[u] = 1, ans[ t -- ] = u;
    return true;
}

bool topo_sort( int n, bool G[N][N], int ans[N] ) {
    int t = n, vis[N] = { 0 };
    for ( int i = 1; i <= n; i ++ )
        if ( !vis[i] && !dfs( i, n, t, G, vis, ans) )
            return false;
    return true;
}

int main() {
#ifdef LOCAL
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    int n, m;
    while ( ~scanf("%d%d", &n, &m) && n ) {
        int ans[N];
        bool G[N][N] = { false };
        for ( int i = 1; i <= m; i ++ ) {
            int a, b;
            scanf("%d%d", &a, &b);
            G[a][b] = true;
        }
        if ( !topo_sort( n, G, ans ) )
            printf("-1\n");
        else {
            for ( int i = 1; i <= n; i ++ )
                printf("%d ", ans[i]);
            printf("\n");
        }
    }
    return 0;
}
