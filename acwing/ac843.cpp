#include <iostream>
using namespace std;
const int N = 13;
int n;
bool vx[N], vls[ 2 * N ], vrs[ 2 * N ], vis[N][N], first;

int lslash( int x, int y ) {
    return x + y - 1;
}

int rslash( int x, int y ) {
    return n + x - y;
}

void dfs( int y, int m ) {
    if ( m == n ) {
        if ( !first )
            first = true;
        else printf("\n");
        for ( int i = 1; i <= n; i ++ )
            for ( int j = 1; j <= n; j ++ )
                printf("%c%s", vis[i][j] ? 'Q' : '.', j == n ? "\n" : "" );
    }
    for ( int i = 1; i <= n; i ++ ) {
        if ( !vx[i] && !vls[ lslash( i, y + 1 ) ] && !vrs[ rslash( i, y + 1 ) ] ) {
            vx[i] = true;
            vls[ lslash( i, y + 1 ) ] = true;
            vrs[ rslash( i, y + 1 ) ] = true;
            vis[i][ y + 1 ] = true;
            dfs( y + 1, m + 1 );
            vx[i] = false;
            vls[ lslash( i, y + 1 ) ] = false;
            vrs[ rslash( i, y + 1 ) ] = false;
            vis[i][ y + 1 ] = false;
        }
    }
    return;
}

int main() {
#ifdef LOCAL
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    scanf("%d", &n);
    dfs( 0, 0 );
    return 0;
}
