#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1e5 + 10;
int main() {
#ifdef LOCAL
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    int n, q, tc, t[N];
    scanf("%d%d%d", &n, &q, &tc);
    for ( int i = 1; i <= n; i ++ )
        scanf("%d", &t[i]);
    sort( t + 1, t + n + 1 );
    long long sum[N] = { 0 };
    for ( int i = 1; i <= n; i ++ )
        sum[i] = sum[ i - 1 ] + t[i];
    while ( q -- ) {
        long long m;
        scanf("%lld", &m);
        int des = n - ( m / tc <= n ? m / tc : n );
        printf("%lld\n", sum[des] + tc);
    }
    return 0;
}
