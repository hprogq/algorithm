#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
using namespace std;
const int N = 4e3 + 10, NUL = 0x3f3f3f3f, H = 4003;

int find( int (&p)[H], int x ) {
    int k = ( x % H + H ) % H;
    while ( p[k] != NUL && p[k] != x )
        if ( ++ k == H )
            k = 0;
    return k;
}

int main() {
#ifdef LOCAL
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    int T;
    scanf("%d", &T);
    while ( T -- ) {
        int n, a[N], b[N], c[N], d[N];
        int h[H], q[H] = { 0 };
        memset( h, 0x3f, sizeof(h) );
        scanf("%d", &n);
        for ( int i = 1; i <= n; i ++ )
            scanf("%d%d%d%d", &a[i], &b[i], &c[i], &d[i]);
        for ( int i = 1; i <= n; i ++ )
            for ( int j = 1; j <= n; j ++ ) {
                int t = a[i] + b[j], f = find( h, t );
                h[f] = t, q[f] ++;
            }
        int sum = 0;
        for ( int i = 1; i <= n; i ++ )
            for ( int j = 1; j <= n; j ++ ) {
                int t = - c[i] - d[j], f = find( h, t );
                if ( h[f] != NUL )
                    sum += q[f];
            }
        printf("%d\n%s", sum, T ? "\n" : "");
    }
    return 0;
}
