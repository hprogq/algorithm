#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
const int N = 17;

int n, tot, C[N], isp[ 2 * N ];
bool vis[N];

bool is_prime( int x ) {
    bool r = false;
    for ( int i = 2; i <= sqrt(x) && ( r = x % i ); i ++ );
    return ( x >= 4 && r ) || x == 2 || x == 3;
}

void dfs( int cur = 1 ) {
    if ( cur == n && isp[ C[0] + C[ n - 1 ] ] ) {
        for ( int i = 0; i < n; i ++ )
            printf("%s%d", i ? " " : "", C[i]);
        printf("\n");
        return;
    }
    for ( int i = 2; i <= n; i ++ ) {
        if ( !vis[i] && isp[ i + C[ cur - 1 ] ] ) {
            C[cur] = i;
            vis[i] = true;
            dfs( cur + 1 );
            vis[i] = false;
        }
    }
    return;
}

int main() {
#ifdef LOCAL
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    int v = 0;
    while ( ~scanf("%d", &n) ) {
        printf( v ? "\n" : "" );
        printf("Case %d:\n", ++ v);
        tot = 0;
        memset( vis, false, sizeof(vis) );
        for ( int i = 1; i <= n * 2; i ++ )
            isp[i] = is_prime(i);
        C[0] = 1;
        dfs();
    }
}