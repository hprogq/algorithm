#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
const int N = 1e5 + 10, A = 26;

int v, n, h[A], e[N], ne[N], in[N], out[N];
bool vis[N];

bool dfs( int x, int cnt = 0 ) {
    if ( cnt == n )
        return true;
    
    for ( int i = h[x]; ~i; i = ne[i] ) {
        if ( !vis[i] ) {
            vis[i] = true;
            bool res = dfs( e[i], cnt + 1 );
            vis[i] = false;
            if ( res )
                return true;
        }
    }

    return false;
}

int ola() {
    int start = -1, end = -1;
    for ( int i = 0; i < A; i ++ )
        if ( !~start && out[i] - in[i] == 1 )
            start = i;
        else if ( !~end && in[i] - out[i] == 1 )
            end = i;
        else if ( in[i] != out[i] )
            return false;
    if ( dfs(start) )
        return true;
    else return false;
}

int main() {
#ifdef LOCAL
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    scanf("%d", &v);
    while ( v -- ) {
        memset( h, -1, sizeof(h) );
        memset( e, 0, sizeof(e) );
        memset( ne, -1, sizeof(ne) );
        memset( vis, false, sizeof(vis) );
        memset( in, 0, sizeof(in) );
        memset( out, 0, sizeof(out) );
        scanf("%d\n", &n);
        for ( int i = 0; i < n; i ++ ) {
            string s;
            getline( cin, s );
            int a = s[0] - 'a', b = s[ s.length() - 1 ] - 'a';
            e[i] = b, ne[i] = h[a], h[a] = i;
            in[b] ++, out[a] ++;
        }
        printf( ola() ? "Yes\n" : "No\n" );
    }
    return 0;
}
