#include <cstdio>
#include <cstring>
using namespace std;
const int N = 5, A = 6;

void change( bool g[N][N], int x, int y ) {
    g[x][y] = !g[x][y];
    if ( x > 0 )  g[ x - 1 ][y] ^= 1;
    if ( y > 0 )  g[x][ y - 1 ] ^= 1;
    if ( x + 1 < N )  g[ x + 1 ][y] ^= 1;
    if ( y + 1 < N )  g[x][ y + 1 ] ^= 1;
    return;
}

bool check( bool g[N][N] ) {
    for ( int i = 0; i < N; i ++ )
        for ( int j = 0; j < N; j ++ )
            if ( !g[i][j] )
                return false;
    return true;
}

int solve( bool g[N][N], int s, int r ) {
    if ( s > A )  return -1;
    if ( check(g) )  return s;
    if ( r >= N )  return -1;
    if ( !r ) {
        int ans = -1;
        for ( int i = 0; i <= 1 << N; i ++ ) {
            int d = 0;
            bool b[N][N];
            memcpy( b, g, sizeof(bool) * N * N );
            for ( int j = 0, k = i; j < N; j ++ ) {
                if ( k & 1 ) {
                    d ++;
                    change( g, r, j );
                }
                k >>= 1;
            }
            int tmp = solve( g, s + d, r + 1 );
            if ( ~tmp && tmp <= ( ~ans ? ans : A ) )
                ans = tmp;
            memcpy( g, b, sizeof(bool) * N * N );
        }
        return ans;
    } else {
        int d = 0;
        bool b[N][N];
        memcpy( b, g, sizeof(bool) * N * N );
        for ( int i = 0; i < N; i ++ )
            if ( !g[ r - 1 ][i] ) {
                d ++;
                change( g, r, i );
            }
        int tmp = solve( g, s + d, r + 1 );
        memcpy( g, b, sizeof(bool) * N * N );
        return tmp;
    }
}

int main() {
#ifdef LOCAL
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    int v;
    scanf("%d", &v);
    while ( v -- ) {
        bool g[N][N];
        for ( int i = 0; i < N; i ++ ) {
            int t, m = N;
            scanf("%d", &t);
            while ( m -- )
                g[i][m] = t % 10, t /= 10;
        }
        printf("%d\n", solve( g, 0, 0 ));
    }
}
