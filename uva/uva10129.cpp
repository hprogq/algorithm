#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
const int N = 1e5 + 10, A = 26;

int v, n, in[A], out[A];
bool G[A][A], vis[A];

void dfs( int u ){
	vis[u] = false;
	for ( int i = 0; i < A; i ++ )
		if ( G[u][i] && vis[i] )
			dfs(i);
}

int ola() {
    int start = -1, end = -1, temp = -1;
    for ( int i = 0; i < A; i ++ )
        if ( !~start && out[i] - in[i] == 1 )
            start = i;
        else if ( !~end && in[i] - out[i] == 1 )
            end = i;
        else if ( in[i] != out[i] )
            return false;
        else if ( out[i] )
            temp = i;
    dfs( ~start ? start : temp );
    for ( int i = 0; i < A; i ++ )
        if ( vis[i] )
            return false;
    return true;
}

int main() {
#ifdef LOCAL
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    scanf("%d", &v);
    while ( v -- ) {
        memset( G, false, sizeof(G) );
        memset( vis, false, sizeof(vis) );
        memset( in, 0, sizeof(in) );
        memset( out, 0, sizeof(out) );
        scanf("%d\n", &n);
        for ( int i = 0; i < n; i ++ ) {
            string s;
            getline( cin, s );
            int a = s[0] - 'a', b = s[ s.length() - 1 ] - 'a';
            G[a][b] = true;
            vis[a] = vis[b] = true;
            in[b] ++, out[a] ++;
        }
        printf( ola() ? "Ordering is possible.\n" : "The door cannot be opened.\n" );
    }
    return 0;
}
