#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/hash_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
const int N = 4e3 + 10;
int main() {
#ifdef LOCAL
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    int T;
    scanf("%d", &T);
    while ( T -- ) {
        int n, a[N], b[N], c[N], d[N];
        scanf("%d", &n);
        gp_hash_table<int, int> ab;
        for ( int i = 1; i <= n; i ++ )
            scanf("%d%d%d%d", &a[i], &b[i], &c[i], &d[i]);
        for ( int i = 1; i <= n; i ++ )
            for ( int j = 1; j <= n; j ++ )
                if ( !ab.count( a[i] + b[j] ) )
                    ab[ a[i] + b[j] ] = 1;
                else ab[ a[i] + b[j] ] ++;
        int sum = 0;
        for ( int i = 1; i <= n; i ++ )
            for ( int j = 1; j <= n; j ++ )
                if ( ab.count( - c[i] - d[j] ) )
                    sum += ab[ - c[i] - d[j] ];
        printf("%d\n%s", sum, T ? "\n" : "");
    }
    return 0;
}
