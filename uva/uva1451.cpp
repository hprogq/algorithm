#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <stack>
using namespace std;
const int N = 1e5 + 10, INF = 0x3f3f3f3f;

int delta( int (&sum)[N], int ax1, int ax2, int bx1, int bx2 ) {
    return ( sum[ax2] - sum[ax1 - 1] ) * ( bx2 - bx1 + 1 ) - ( sum[bx2] - sum[bx1 - 1] ) * ( ax2 - ax1 + 1 );
}

int main() {
#ifdef LOCAL
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    int v;
    scanf("%d\n", &v);
    while ( v -- ) {
        int n, L, e[N] = { 0 }, s[N] = { 0 };
        scanf("%d %d\n", &n, &L);
        for ( int i = 1; i <= n; i ++ ) {
            e[i] = getchar() - '0';
            s[i] = s[ i - 1 ] + e[i];
        }

        int p[N] = { 0 }, l = 0, r = 0;
        int ll = 1, rr = L;
        for ( int t = L; t <= n; t ++ ) {
            while ( r - l >= 2 && delta( s, p[ r - 2 ], t - L, p[ r - 1 ], t - L ) >= 0 )
                r --;
            p[ r ++ ] = t - L + 1;

            while ( r - l >= 2 && delta( s, p[l], t, p[ l + 1 ], t ) <= 0 )
                l ++;
            
            int c = delta( s, p[l], t, ll, rr );
            if ( c > 0 || c == 0 && t - p[l] < rr - ll )
                ll = p[l], rr = t;
        }
        
        printf("%d %d\n", ll, rr);
        
    }
    return 0;
}
