#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
const int N = 100;

int n, l, t = 0, s[N];

bool dfs( int p = 0 ) {
    if ( !p )
        t = 0;
    if ( t ++ == n ) {
        for ( int i = 0; i < p; i ++ )
            printf("%s%c", ( !i || i % 4 ) ? "" : i % 64 ? " " : "\n", s[i] + 'A');
        printf("\n%d\n", p);
        return true;
    }
    for ( int i = 0; i < l; i ++ ) {
        s[p] = i;
        bool flag = true;
        for ( int j = 1; j <= ( p + 1 ) / 2; j ++ ) {
            bool same = true;
            for ( int x = p - 2 * j + 1, y = p - j + 1; same && y <= p; x ++, y ++ )
                same = ( s[x] == s[y] );
            if ( !( flag = !same ) )
                break;
        }
        if ( flag && dfs( p + 1 ) )
            return true;
    }
    return false;
}

int main() {
#ifdef LOCAL
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    while ( ~scanf("%d%d", &n, &l) && n )
        dfs();
    return 0;
}
