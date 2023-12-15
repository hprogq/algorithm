#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 3e4, maxm = 5e2;

int find( int p[], int x ) {
    if ( p[x] != x )
        p[x] = find( p, p[x] );
    return p[x];
}

int main() {
#ifdef LOCAL
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    int n, m;
    while ( ~scanf("%d%d", &n, &m) && n ) {
        int p[maxn] = { 0 };
        bool vis[maxn] = { false };
        for ( int i = 1; i <= m; i ++ ) {
            int t, first = -1;
            scanf("%d", &t);
            while ( t -- ) {
                int id;
                scanf("%d", &id);
                if ( !~first )  first = id;
                if ( vis[id] && find( p, id ) == 0 )
                    p[ find( p, first ) ] = 0;
                p[id] = first;
                vis[id] = true;
            }
        }
        int sum = 1;
        for ( int i = 1; i < n; i ++ )
            if ( vis[i] && !find( p, i ) )
                sum ++;
        printf("%d\n", sum);
    }
    return 0;
}