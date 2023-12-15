#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 1e6 + 10;
int main() {
#ifdef LOCAL
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    int k;
    scanf("%d", &k);
    while ( k -- ) {
        int n, num[N], st[N], idx = 0;
        bool odd;
        scanf("%d", &n);
        for ( int i = 1; i <= n; i ++ ) {
            scanf("%d", &num[i]);
            if ( i == 1 || odd == ( abs(num[i]) % 2 ) )
                st[ ++ idx ] = i;
            odd = ( abs(num[i]) % 2 );
        }
        int rans = -0x7fffffff;
        for ( int i = 1; i <= idx; i ++ ) {
            int ans = num[ st[i] ], t = num[ st[i] ], nxt = ( i == idx ) ? n + 1 : st[ i + 1 ];
            for ( int j = st[i] + 1, k = nxt - j; j < nxt; j ++ ) {
                    ans = max( num[j], ans + num[j] );
                    t = max(t, ans);
            }
            rans = max( t, rans );
        }
        printf("%d\n", rans);
    }
    return 0;
}