#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 1e5 + 10, M = 2 * N;

int n, m, h[N], e[M], ne[M], in[N], idx = 0;

void link( int a, int b ) {
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx ++;
    return;
}

int main() {
    while ( ~scanf("%d%d", &n, &m) && n ) {
        memset( h, -1, sizeof(h) );
        memset( e, 0, sizeof(e) );
        memset( ne, 0, sizeof(ne) );
        memset( in, 0, sizeof(in) );
        idx = 0;
        while ( m -- ) {
            int a, b;
            scanf("%d%d", &a, &b);
            link( a, b );
            in[b] ++;
        }
    
        int q[N], hh = 0, tt = -1;
        for ( int i = 1; i <= n; i ++ )
            if ( !in[i] )
                q[ ++ tt ] = i;
        
        while ( hh <= tt ) {
            int x = q[ hh ++ ];
            for ( int i = h[x]; ~i; i = ne[i] )
                if ( ! -- in[ e[i] ] )
                    q[ ++ tt ] = e[i];
        }
    
        if ( tt == n - 1 )
            for ( int i = 0; i <= tt; i ++ )
                printf("%d ", q[i]);
        else printf("-1\n");
        printf("\n");
    }

    return 0;
}
