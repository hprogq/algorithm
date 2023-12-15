#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
int main() {
#ifdef LOCAL
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    int n, v = 0;
    while ( ~scanf("%d", &n) ) {
        v ++;
        int k[19];
        long long maxn = 0;
        for ( int i = 1; i <= n; i ++ )
            scanf("%d", &k[i]);
        for ( int i = 1; i <= n; i ++ )
            for ( int j = i; j <= n; j ++ ) {
                long long tmaxn = 1;
                for ( int x = i; x <= j; x ++ )
                    tmaxn *= k[x];
                maxn = max( maxn, tmaxn );
            }
        printf("Case #%d: The maximum product is %lld.\n\n", v, maxn);
    }
    return 0;
}