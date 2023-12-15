#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
const int N = 1e5 + 10, M = 2 * N;
int n, ans = 0x3f3f3f3f, h[N], e[M], ne[M], idx = 0;
bool vis[N];

void connect( int a, int b ) {
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx;
    idx ++;
    return;
}

int dfs( int x ) {
    int sum = 0, size = -1;
    vis[x] = true;
    for ( int i = h[x]; ~i ; i = ne[i] )
        if ( !vis[ e[i] ] ) {
            int t = dfs( e[i] );
            size = max(t, size);
            sum += t;
        }
    size = max( size, n - sum - 1 );
    ans = min( size, ans );
    return sum + 1;
}

int main() {
    memset( h, -1, sizeof(h) );
    scanf("%d", &n);
    for ( int i = 1; i < n; i ++ ) {
        int a, b;
        scanf("%d%d", &a, &b);
        connect( a, b );
        connect( b, a );
    }
    dfs(1);
    printf("%d\n", ans);
    return 0;
}
