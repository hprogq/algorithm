#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

const int N = 600;
const long long INF = 1 << 40;

long long split( int a[N], int n, int from, long long size, int k, int idx, int pro[N], int maxn = 0 ) {
    if ( from > n )
        return maxn;
    int t = 0;
    pro[ idx ++ ] = n - from + 1;
    while ( from <= n && t + a[from] <= size )
        t += a[ from ++ ];
    if ( idx >= k && from <= n )
        return -1;  // size too small
    else if ( from > n && idx < k )
        return -2;  // size too big
    return split( a, n, from, size, k, idx, pro, max( maxn, t ) );
}

int main() {
#ifdef LOCAL
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    int v;
    scanf("%d", &v);
    while ( v -- ) {
        int m, k, a[N], maxa = 0, ans = 0x3f3f3f3f;
        long long sum = 0;
        scanf("%d%d", &m, &k);
        for ( int i = 1; i <= m; i ++ ) {
            scanf("%d", &a[i]);
            maxa = max( maxa, a[i] ), sum += a[i];
        }
        sort( a + 1, a + m + 1 );
        reverse( a + 1, a + m + 1 );
        long long l = maxa, r = sum;
        while ( l != r ) {
            int mid = ( l + r ) >> 1;
            int pro[N] = { 0 };
            int res = split( a, m, 1, mid, k, 0, pro, 0 );
            int t = 0;
            if ( res == -1 )
                l = mid + 1;
            else if ( res == -2 ) 
                r = mid;
            else r = mid, ans = min( res, ans );
            printf("new: %lld %d\n", mid, res);
            while ( pro[t] )
                printf("%d ", pro[ t ++ ]);
            puts("");
        }
        puts("");
    }
    return 0;
}
