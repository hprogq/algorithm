#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;

const int N = 3e5 + 10;

struct pos {
    int x, y;
} f[N];

int find( int p[N], int x ) {
    if ( p[x] != x )
        p[x] = find( p, p[x] );
    return p[x];
}
int main() {
#ifdef LOCAL
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    int n, d, p[N] = { 0 };
    bool s[N] = { false };
    scanf("%d %d\n", &n, &d);
    for ( int i = 1; i <= n; i ++ ) {
        scanf("%d %d\n", &f[i].x, &f[i].y);
        p[i] = i;
    }
    char op;
    while ( ~scanf("%c", &op) ) {
        int a[100];
        if ( op == 'O' ) {
            int a;
            scanf(" %d\n", &a);
            s[a] = true;
            for ( int i = 1; i <= n; i ++ )
                if ( s[i] && ( f[a].x - f[i].x ) * ( f[a].x - f[i].x ) + ( f[a].y - f[i].y ) * ( f[a].y - f[i].y ) <= d * d && find( p, a ) != find( p, i ) )
                    p[ find( p, i ) ] = find( p, a );
        } else if ( op == 'S' ) {
            int a, b;
            scanf(" %d %d\n", &a, &b);
            if ( !s[a] || !s[b] || find( p, a ) != find( p, b ) )
                printf("FAIL\n");
            else printf("SUCCESS\n");
        }
    }
    return 0;
}
