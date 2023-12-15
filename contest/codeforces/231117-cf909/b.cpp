#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <cmath>
#include <cstring>
using namespace std;
const int N = 150010;
int main() {
#ifdef LOCAL
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    int k;
    scanf("%d", &k);
    while ( k -- ) {
        int n, a[N];
        long long maxn = -1;
        scanf("%d", &n);
        for ( int i = 0; i < n; i ++ )
            scanf("%d", &a[i]);
        if ( n == 1 ) {
            printf("0\n");
            continue;
        }
        for ( int i = 1; i <= n / 2; i ++ ) {
            if ( n % i )
                continue;
            long long t[N] = { 0 };
            for ( int j = 0; j <= n - 1; j ++ )
                t[ j / i ] += a[j];
            sort( t, t + n / i );
            long long delta = t[ n / i - 1 ] - t[0];
            maxn = maxn > delta ? maxn : delta;
        }
        printf("%lld\n", maxn);
    }
    return 0;
}
